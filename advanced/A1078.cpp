#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e4;
int prime[maxn >> 2] = { 0 };
bool s[maxn];
// 获取Tsize
int getPrime(int n)
{
    if (n == 1 || n == 2)
        return 2;
    int count = 1, i = 3;
    bool flag = true;
    prime[1] = 2;
    while (i <= n) {
        flag = true;
        for (int j = 2; j <= count; j++) {
            if (prime[j] > i / 3)
                break;
            if (i % prime[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            prime[++count] = i;
        }
        i += 2;
    }
    if (flag)
        return n;
    else {
        while (1) {
            flag = true;
            for (int j = 2; j <= count; j++) {
                if (prime[j] > i / 3)
                    break;
                if (i % prime[j] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
            i += 2;
        }
    }
    return -1;
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

    int n, m, a, pos, count = 0;
    scanf("%d%d", &n, &m);
    int Tsize = getPrime(m);
    printf("%d", Tsize);
    for (int i = 0; i < n; i++) {
        //scanf("%d\n", &a);
        int k = 0;
        while (k < Tsize) {
            pos = (a + k * k) % Tsize;
            if (s[pos] == false) {
                s[pos] = true;
                printf("%d", pos);
                break;
            }
            k += 1;
        }
        if (k == Tsize)
            printf("-");
        if (i < n - 1)
            printf(" ");
    }
    return 0;
}