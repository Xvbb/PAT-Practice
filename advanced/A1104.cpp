#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);                      

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
double a[maxn];
#define LOCAL_XBB

int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n;
    double ans = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
        ans += a[i] * i * (n + 1 - i) ;
    }
    printf("%.2f", ans);
    return 0;
}