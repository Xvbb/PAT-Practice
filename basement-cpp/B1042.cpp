#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
////string转int
int my_to_int(string s)
{
    stringstream ss;
    int a;
    ss.clear();
    ss << s;
    ss >> a;
    return a;
}
////字符串数组转int
int my_to_int(char s[])
{
    int k;
    sscanf(s, "%d", &k);
    return k;
}
struct data {
    int c;
    int fre;
} d;
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    char s[1001];
    int hashtable[27] = { 0 };
    int max = 0;
    fgets(s, 1001, stdin);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int p = -1;
        if (s[i] >= 'A' && s[i] <= 'Z') {
            p = s[i] - 'A';
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            p = s[i] - 'a';
        }
        if(p == -1)
            continue;
        ++hashtable[p];
        if (hashtable[p] > max)
            max = hashtable[p];
    }
    for (int i = 0; i < 27; i++) {
        if (hashtable[i] == max) {
            printf("%c ", 'a' + i);
            break;
        }
    }
    printf("%d", max);
    return 0;
}