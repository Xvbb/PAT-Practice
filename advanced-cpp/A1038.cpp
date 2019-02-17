#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);                      

using namespace std;
typedef long long LL;
const int maxn = 1e4 + 10;
string s[maxn];
// 字符串拼接，取小
bool cmp(string s1, string s2){
        return s1 + s2 < s2 + s1;
}
#define LOCAL_XBB

int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n;
    string ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        ans += s[i];
    }
    // 去除首部0
    while(ans.size() != 0 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    // 如果全0去除，ans长度0
    if(ans.size() == 0)
        cout << "0";
    else
        cout << ans;
    return 0;
}