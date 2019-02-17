#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int b[maxn] = { 0 };
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, amount, a = 0, maxMinus = 0;
    int hashtabl[1001] = { 0 };
    scanf("%d%d", &n, &amount);
    if (amount > 1000) {
        printf("No Solution");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (hashtabl[b[i]] == 0)
            hashtabl[amount - b[i]] = 1;
        else {
            int between = (b[i] << 1) - amount;
            if (between >= maxMinus) {
                maxMinus = between;
                a = b[i];
            } 
        }
    }
    if (a != 0)
        printf("%d %d", amount - a, a);
    else
        printf("No Solution");

    return 0;
}