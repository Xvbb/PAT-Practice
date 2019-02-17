#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
struct data {
    double pi;
    double di;
} s[510];
bool cmp(data d1, data d2)
{
    if (d1.di != d2.di)
        return d1.di < d2.di;
    else
        return d1.pi < d2.pi;
}
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    double p = 0.00;
    double cmax, d, davg, dis = 0.00, left = 0.00;
    int n, min, flag = 0;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &s[i].pi, &s[i].di);
    }
    s[n].di = d;
    s[n].pi = 0;
    sort(s, s + n + 1, cmp);
    if (s[0].di != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        min = i + 1;
        for (int j = i + 1; j <= n && dis + cmax * davg >= s[j].di; j++) {
            if (s[j].pi < s[i].pi) {
                p += ((s[j].di - dis) / davg - left) * s[i].pi;
                //printf("%d - %d号站, pi = %.2f, dis = %.2f, 油量 = %.2f, p = %.2f\n", i, j, s[i].pi, s[j].di - dis, (s[j].di - dis) / davg - left, p);
                dis = s[j].di;
                i = j - 1;
                flag = 0;
                left = 0;
                break;
            } else if (s[j].pi <= s[min].pi) {
                flag = 1;
                min = j;
            }
        }
        if (flag) {
            // 当前可达最远距离内，没有比当前价格低的加油站。故而在当前站满油
            if (s[min].pi > s[i].pi) {
                p += (cmax - left) * s[i].pi;
                //printf("%d - %d号站, pi = %.2f, dis = %.2f, 油量 = %.2f, p = %.2f\n", i, min, s[i].pi, s[min].di - dis, cmax - left, p);
                left = cmax - (s[min].di - dis) / davg;
            } else {
                // 选能达到的价格最低的油站
                p += (s[min].di - dis) / davg * s[i].pi;
            }
            dis = s[min].di;
            i = min - 1;
            flag = 0;
        }
    }
    if (dis < d) {
        printf("The maximum travel distance = %.2f", dis + cmax * davg);
    } else {
        printf("%.2f", p);
    }
    return 0;
}
