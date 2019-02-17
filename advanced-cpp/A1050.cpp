#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e4 + 10;
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
char s1[maxn], s2[maxn];
int hashtable[256] = { 0 };
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    fgets(s1, maxn, stdin);
    fgets(s2, maxn, stdin);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len2 == 0) {
        printf("%s", s1);
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        hashtable[s1[i]]++;
    }
    for (int i = 0; i < len2; i++) {
        hashtable[s2[i]] = 0;
    }
    for (int i = 0; i < len1; i++) {
        if(hashtable[s1[i]] != 0)
            printf("%c", s1[i]);
    }

    return 0;
}