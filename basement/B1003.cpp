#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);                      

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int Map[256] = { 0 };
bool judge(string s)
{
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if(i != "P" && i != "A" && i != "T")
            return false;
        Map[s[i]]++;
        if(Map["p"] > 1 || Map["T"] > 1)
            return false;
    }
    if(Map["p"] = 0 || Map["T"] = 0)
        return false;
    int pos_p = s.find("P"), pos_t = s.find("T");
    if(pos_p > pos_t)
        return false;
    else {
        int a = pos_p;
        int b =
    }
    int str;
    for (int i = 0; i < pos_p; i++) {
        if
    }

}
#define LOCAL_XBB

int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    string s[110];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if(s[i] == "PAT")
            cout << "YES";
        else if()
    }

    return 0;
}