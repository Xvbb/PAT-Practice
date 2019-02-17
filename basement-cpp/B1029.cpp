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

#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    char s1[81], s2[82];
    int hashtable[63] = { 0 };
    scanf("%s", s1);
    getchar();
    scanf("%s", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0, j = 0; i < len1; i++) {
        if (s1[i] != s2[j]) {
            if (s1[i] == '_') {
                if (hashtable[62] == 0)
                    printf("_");
                hashtable[62] = 1;
            } else if (s1[i] - '0' >= 0 && s1[i] - '0' <= 9) {
                if (hashtable[s1[i] - '0'] == 0)
                    printf("%c", s1[i]);
                hashtable[s1[i] - '0'] = 1;
            } else if (s1[i] - 'a' >= 0 && s1[i] - 'a' <= 25) {
                if (hashtable[s1[i] - 'a' + 10] == 0)
                    printf("%c", s1[i] - 'a' + 'A');
                hashtable[s1[i] - 'a' + 10] = 1;
            } else if (hashtable[s1[i] - 'A' + 10] == 0) {
                printf("%c", s1[i]);
                hashtable[s1[i] - 'A' + 10] = 1;
            }
        } else {
            j++;
        }
    }

    return 0;
}