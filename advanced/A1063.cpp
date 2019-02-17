#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e4 + 10;
set<int> st[51];
void compare(int n, int m)
{
    int a = 0, b = st[m].size();
    for (set<int>::iterator it = st[n].begin(); it != st[n].end(); it++) {
        if(st[m].find(*it) != st[m].end())
            a++;
        else
            b++;
    }
    printf("%.1f%%\n", a * 100.0 / b);
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

    int n, m, k, a, first, last;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a);
            st[i].insert(a);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &first, &last);
        compare(first, last);
    }
    return 0;
}