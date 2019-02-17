#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 * 2 + 10;
int a[maxn];
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, m, count = 0, temp;
    scanf("%d", &n);
    // MLE
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = 0x7fffffff;
    scanf("%d", &m);
    int k = (n + m - 1) / 2;
    int now = 0, i = 0;
    scanf("%d", &temp);
    while(count < k) {
        if (a[now] < temp) {
            now++;
        } else {
            i++;
            if (i == m)
                temp = 0x7fffffff;
            else
                scanf("%d", &temp);
        }
        count++;
    }

    if (a[now] < temp)
        printf("%d", a[now]);
    else
        printf("%d", temp);

    return 0;
}