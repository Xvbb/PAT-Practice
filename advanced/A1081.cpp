#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
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

    LL up = 0, down = 1;
    int n, a, b, gys;
    scanf("%d", &n);
    while (n--) {
        scanf("%d/%d", &a, &b);
        up = up * b + a * down;
        down = down * b;
        gys = gcd(abs(up), abs(down));
        up /= gys;
        down /= gys;
    }
    int rest = up % down;
    if (up > down && rest != 0) {
        printf("%lld %lld/%lld", up / down, up % down, down);
    } else if (rest == 0) {
        printf("%lld", up / down);
    } else {
        printf("%lld/%lld", up, down);
    }
    return 0;
}