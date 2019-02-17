#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL a[maxn], big[maxn], ans[maxn];
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, count = 0;
    scanf("%d", &n);
    scanf("%lld", &a[0]);
    big[0] = 0;
    for (int i = 1; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > big[i - 1])
            big[i] = max(big[i - 1], a[i - 1]);
        else
            big[i] = big[i - 1];
    }
    a[n] = 1e10;
    LL temp = 1e10;
    // small[n - 1] = 1e10;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < temp)
            temp = min(temp, a[i+1]);
        if (a[i] > big[i] && a[i] < temp) {
            ans[count] = a[i];
            count++;
        }
    }
    printf("%d\n", count);
    while(count > 0){
        count--;
        printf("%lld", ans[count]);
        if (count > 0)
            printf(" ");
    }
    if(count == 0)
        printf("\n");

    return 0;
}