#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int b[5] = { 0 };
int arrayToInt()
{
    int ans = 0, len = 4;
    while (len > 0) {
        ans = ans * 10 + b[len - 1];
        len--;
    }
    return ans;
}
void intToArray(int a)
{
    int k = 3;
    while (k>=0) {
        b[k--] = a % 10;
        a /= 10;
    }
}
bool cmp1(int a, int b)
{
    return a < b;
}
bool cmp2(int a, int b)
{
    return a > b;
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

    int a, ans = 0;

    scanf("%d", &a);
    while (ans != 6174) {
        intToArray(a);
        sort(b, b + 4, cmp1);
        int first = arrayToInt();
        sort(b, b + 4, cmp2);
        int last = arrayToInt();
        ans = first - last;
        a = ans;
        printf("%04d - %04d = %04d\n", first, last, ans);
        if (first == last)
            break;
    }

    return 0;
}