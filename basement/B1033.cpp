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

char s[maxn],s1[maxn];
bool hashtable[256];
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    memset(hashtable, true, sizeof(hashtable));
    scanf("%s", s1);
    scanf("%s", s);
    int len1 = strlen(s1);
    int len = strlen(s);
    // 第一行为空，scanf("%s", s1)读入的是第二行，s读入空
    if(len == 0) {
        printf("%s", s1);
        return 0;
    }
    for (int i = 0; i < len1; i++) {
         if (s1[i] >= 'A' && s1[i] <= 'Z') {
             s1[i] = s1[i] - 'A' + 'a';
        } 
        hashtable[s1[i]] = false;
    }
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            int low = s[i] -'A' + 'a';
            if(hashtable[low] == true && hashtable['+'] == true) {
                printf("%c", s[i]);
            }
        } else if (hashtable[s[i]] == true) {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}