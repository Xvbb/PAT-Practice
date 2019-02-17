#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;

#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, now, old, ans = 0;
    scanf("%d", &n);
    scanf("%d", &old);
    ans += 6 * old + 5;
    for (int i = 1; i < n; i++) {
        scanf("%d", &now);
        if (old > now)
            ans += 4 * (old - now) + 5;
        else if (old < now)
            ans += (now - old) * 6 + 5;
        else
            ans += 5;
        old = now;
    }
    printf("%d", ans);

    return 0;
}