#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL a1[maxn] = { 0 }, a2[maxn] = { 0 }, b1[maxn] = { 0 }, b2[maxn] = { 0 };
bool cmp1(int a, int b)
{
    return a > b;
}
bool cmp2(int a, int b)
{
    return a < b;
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

    int n1, n2, k1 = 0, m1 = 0, k2 = 0, m2 = 0;
    LL ans = 0, temp;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%lld", &temp);
        if (temp > 0) {
            a1[k1++] = temp;
        } else if (temp < 0) {
            a2[m1++] = temp;
        }
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%lld", &temp);
        if (temp > 0) {
            b1[k2++] = temp;
        } else if (temp < 0) {
            b2[m2++] = temp;
        }
    }
    sort(a1, a1 + k1, cmp1);
    sort(a2, a2 + m1, cmp2);
    sort(b1, b1 + k2, cmp1);
    sort(b2, b2 + m2, cmp2);
    for (int i = 0; i < k1 && i < k2; i++) {
        ans += a1[i] * b1[i];
    }
    for (int i = 0; i < m1 && i < m2; i++) {
        ans += a2[i] * b2[i];
    }
    printf("%lld", ans);
    return 0;
}