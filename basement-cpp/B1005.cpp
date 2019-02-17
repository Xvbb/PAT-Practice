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
int hashtable[10000] = { 0 };

void func(int n)
{
    int index = 0;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = (3 * n + 1) / 2;
        hashtable[n] = 1;
    }
}
bool cmp(int a, int b)
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

    int k, a, count = 0, flag = 0;
    int result[10000], b[10000];
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &b[i]);
        func(b[i]);
    }

    for (int i = 0; i < k; i++) {
        if (hashtable[b[i]] == 0) {
            result[count++] = b[i];
        }
    }
    sort(result, result + 100, cmp);
    for (int i = 0; i < count; i++) {
        printf("%d", result[i]);
        if (i != count - 1)
            printf(" ");
    }

    return 0;
}