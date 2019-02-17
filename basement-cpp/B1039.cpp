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

    char s1[1001], s2[1001];
    int falg = 1;
    int hashtable1[256] = { 0 }, hashtable2[256] = { 0 };
    scanf("%s", s1);
    scanf("%s", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i < len1; i++) {
        hashtable1[s1[i]]++;
    }
    for (int i = 0; i < len2; i++) {
        hashtable1[s2[i]]--;
        if(hashtable1[s2[i]] < 0)
            falg = 0;
    }
    if(falg)
        printf("Yes %d", len1 - len2);
    else {
        int more = 0;
        for (int i = 0; i < 256; i++) {
            if(hashtable1[i] < 0)
                more -= hashtable1[i];
        }
        printf("No %d", more);
    }

    return 0;
}