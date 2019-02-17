#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
// 十三进制个位
string a[14] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun",
    "jly", "aug", "sep", "oct", "nov", "dec"
};
// 13的[0, 12]倍
string b[14] = {
    "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
    "elo", "syy", "lok", "mer", "jou"
};
#define LOCAL_XBB
int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n;
    string s[170], c;
    map<string, int> mp;
    // 分别用string[]和map建立映射,[0,13)
    for (int i = 0; i < 13; i++) {
        s[i] = a[i];
        mp[a[i]] = i;
        s[i * 13] = b[i];
        mp[b[i]] = i * 13;
    }
    // [13, 169]
    for (int i = 1; i < 13; i++) {
        for (int j = 1; j < 13; j++) {
            string str = b[i] + " " + a[j];
            s[i * 13 + j] = str;
            mp[str] = i * 13 + j;
        }
    }
    // 去除换行符
    scanf("%d%*c", &n);
    for (int i = 0; i < n; i++) {
        getline(cin, c);
        if (c[0] >= '0' && c[0] <= '9') {
            int num = 0;
            for (int k = 0; k < c.length(); k++)
                num = num * 10 + (c[k] - '0');
            printf("%s\n", s[num].c_str());
        } else {
            printf("%d\n", mp[c]);
        }
    }

    return 0;
}