#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
char s[22];
int hashtable_1[256] = { 0 }, hashtable_2[256] = { 0 };
void myreverse(char s[], int len)
{
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
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

    scanf("%s", s);
    int len = strlen(s), rest = 0;
    bool flag = true;
    if (len == 1) {
        int a = (s[0] - '0') << 1;
        if(a == 0)
            printf("Yes\n0");
        else printf("No\n%d", a);
        return 0;
    }
    myreverse(s, len);
    for (int i = 0; i < len; i++) {
        char temp = s[i];
        hashtable_1[temp]++;
        s[i] = '0' + (((temp - '0') * 2 + rest) % 10);
        rest = ((temp - '0') * 2 + rest) / 10;
        hashtable_2[s[i]]++;
    }
    if (rest != 0) {
        printf("No\n");
        printf("1");
    } else {
        for (int i = 0; i < len; i++) {
            if (hashtable_1[s[i]] != hashtable_2[s[i]]) {
                printf("No\n");
                flag = false;
                break;
            }
        }
        if (flag)
            printf("Yes\n");
    }
    while (--len >= 0)
        printf("%c", s[len]);
    return 0;
}