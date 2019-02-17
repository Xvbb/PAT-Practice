#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB
    char a[maxn];
    cin >> a;
    int len = strlen(a);
    int leftNumP[maxn] = { 0 };
    int ans = 0, rightNum = 0;
    for (int i = 0; i < len; i++) {
        if(i > 0) {
            leftNumP[i] = leftNumP[i - 1];
        }
        if(a[i] == 'P') {
            leftNumP[i]++;
        }
    }
    for (int i = len - 1; i > 1; i--){
        if(a[i] == 'T') {
            rightNum++;
        } else if(a[i] == 'A') {
            ans = (rightNum * leftNumP[i] + ans) % MOD;
        }
    }
    cout << ans;
    return 0;
}