#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);                      

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
char s[maxn], temp[maxn];
void myreverse(int len)
{
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
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
    int n, count = 0;
    LL a, b;
    scanf("%s %d", s, &n);
    int len = strlen(s);
    strcpy(temp, s);
    myreverse(len);
    if(strcmp(s, temp) == 0){
        printf("%s\n0", temp);
        return 0;
    }
    while (count < n) {
        count++;
        sscanf(s, "%lld", &a);
        sscanf(temp, "%lld", &b);
        // 越界
        sprintf(s, "%lld", a + b);
        len = strlen(s);
        strcpy(temp, s);
        myreverse(len);
        if(strcmp(temp, s) == 0) {
            printf("%s\n%d", s, count);
            break;
        } else {
            if(count == n)
                printf("%s\n%d", temp, n);
        }
    }

    return 0;
}