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
    LL a, len = 0, left = 0, now = 0, n;
    scanf("%lld", &a);
    if (a <= 3) {
        printf("1\n2");
        return 0;
    }
    n = (int)sqrt(a);
    for (int i = 2; i <= n; i++) {
        int j = i, temp = a;
        while (1) {
            if (temp % j == 0) {
                temp /= j;
                j++;
                now++;
            } else {
                break;
            }
        }
        if (now > len) {
            left = i;
            len = now;
            //cout << "len = " << len << " left = " << left << endl;
        }
        now = 0;
    }
    if(len == 0) {
        printf("1\n%lld", a);
        return 0;
    }
    printf("%lld\n", len);
    int k = 0;
    while (len--) {
        printf("%lld", left + k);
        k++;
        if (len > 0)
            printf("*");
    }

    return 0;
}