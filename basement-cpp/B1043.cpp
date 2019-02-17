#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
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
char s[10001];
int hashtable[256] = {0};
#define LOCAL_XBB

int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        hashtable[s[i]]++;
    }
    while(hashtable['P'] >0 || hashtable['A'] > 0 || hashtable['T'] > 0 || hashtable['e'] > 0 || hashtable['s'] > 0 || hashtable['t'] > 0) {
        if(hashtable['P'] >0) {
            printf("P");
            hashtable['P']--;
        }
        if(hashtable['A'] >0) {
            printf("A");
            hashtable['A']--;
        }
        if(hashtable['T'] >0) {
            printf("T");
            hashtable['T']--;
        }  
        if(hashtable['e'] >0){
            printf("e");
            hashtable['e']--;
        }
        if(hashtable['s'] >0){
            printf("s");
            hashtable['s']--;
        }
        if(hashtable['t'] >0){
            printf("t");
            hashtable['t']--;
        }
    }

    return 0;
}