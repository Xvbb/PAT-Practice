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
int s[101] = { 0 };
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int grade;
        scanf("%d", &grade);
        s[grade]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int p;
        scanf("%d", &p);
        printf("%d", s[p]);
        if (i != k - 1)
            printf(" ");
    }

    return 0;
}