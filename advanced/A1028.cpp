#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;

struct data {
    int id;
    char name[9];
    int garde;
}d[maxn];

bool cmp1(data d1, data d2)
{
    return d1.id < d2.id;
}
bool cmp2(data d1, data d2)
{
    int s = strcmp(d1.name, d2.name);
    if (s != 0)
        return s < 0;
    else
        return d1.id < d2.id;
}
bool cmp3(data d1, data d2)
{
    if (d1.garde != d2.garde)
        return d1.garde < d2.garde;
    else
        return d1.id < d2.id;
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

    int n, b;
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &d[i].id, d[i].name, &d[i].garde);
    }
    if (b == 1)
        sort(d, d + n, cmp1);
    else if (b == 2)
        sort(d, d + n, cmp2);
    else
        sort(d, d + n, cmp3);

    for (int i = 0; i < n; i++)
        printf("%06d %s %d\n", d[i].id, d[i].name, d[i].garde);
    return 0;
}