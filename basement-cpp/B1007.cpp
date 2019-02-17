#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);                      

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int prime[maxn];
int getPrime(int n)
{
    int count = 1, index = 0, i = 3;
    bool flag;
    prime[1] = 2;
    while (i <= n) {
        flag = true;
        for (int j = 2; j <= count; j++) {
            if(prime[j] > i / 3)
                break;
            if (i % prime[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            prime[++count] = i;
            if(prime[count] - prime[count-1] == 2) index++;
        }
        i += 2;
    }
    return index;
}
#define LOCAL_XBB

int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, count = 0, last = 1;
    scanf("%d", &n);
    if(n <= 2){
        printf("0");
        return 0;
    }
    count = getPrime(n);
    printf("%d", count);
    return 0;
}