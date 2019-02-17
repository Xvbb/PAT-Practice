#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e4 + 1;
int prime[maxn];

void getPrime(int m, int n)
{
    int count = 1, index = 0, i = 3;
    bool flag;
    if (n == 1) {
        printf("2");
        return;
    }
    prime[1] = 2;
    while (count < n) {
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
        }
        i += 2;
    }
    for (int i = m; i <= n; i++) {
        printf("%d", prime[i]);
        ++index;
        if (index == 10) {
            printf("\n");
            index = 0;
        } else if (i != n)
            printf(" ");
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

    int n, m;
    scanf("%d%d", &m, &n);
    double dur;
    clock_t start, end;
    start = clock();
    getPrime(m, n);
    end = clock();
    dur = (double)(end - start);
    printf("Use Time:%f\n", (dur / CLOCKS_PER_SEC));

    return 0;
}