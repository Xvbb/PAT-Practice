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
int p[maxn] = { 0 }, cop[maxn] = { 0 };
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, a, flag = 1, fre = 0, index = 0;
    map<int, int> m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        cop[i] = a;
        if (p[a] == 0) {
            cop[index++] = a;
        }
        p[a]++;
    }

    for (int i = 0; i < index; i++) {
        if (p[cop[i]] != 1)
            continue;
        printf("%d", cop[i]);
        return 0;
    }
    printf("None");
    return 0;
}