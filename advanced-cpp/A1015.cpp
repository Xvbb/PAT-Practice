#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int s[20];
// 获取maxn范围内全部素数
bool getPrime(int a)
{
    if(a == 1)
        return false;
    for (int i = 2; i <= a / 2; i++) {
        if(a % i == 0)
            return false;
    }
    return true;
}
// 获得a的b进制反转后的十进制数
int changeRadix(int a, int b)
{
    int index = 0;
    int ans = 0;
    while (a != 0) {
        s[index++] = a % b;
        a /= b;
    }
    // for (int i = 0; i < index; i++)
    //     printf("%d", s[i]);
    // printf("\n");
    // for (int i = index - 1; i >= 0; i--) {
    //     ans = ans * b + (s[i] - '0');
    // }
    for (int i = 0; i < index; i++) {
        ans = ans * b + s[i];
    }
    return ans;
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

    int a, b;
    while (1) {
        scanf("%d", &a);
        if (a < 0)
            return 0;
        else if(getPrime(a) == false) {
            printf("No\n");
            scanf("%d", &b);
            continue;
        }
        scanf("%d", &b);
        b = changeRadix(a, b);
        if (getPrime(b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}