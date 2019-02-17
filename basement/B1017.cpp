#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
char s[1001];
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int div, rest = 0, i = 0;
    scanf("%s %d", s, &div);
    int n = strlen(s);
    if(n == 1 && s[0] - '0' < div) {
        printf("0 %s", s);
        return 0;
    }
    if (s[0] - '0' + 10 * rest > div) {
        printf("%d", (s[0] - '0') / div);
    }
    rest = (s[0] - '0') % div;
    i++;
    while (i < n) {
        printf("%d", (s[i] - '0' + rest * 10) / div);
        rest = (s[i] - '0' + rest * 10) % div;
        i++;
    }
    printf(" %d", rest);
    return 0;
}