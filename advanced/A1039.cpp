#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1;
int getId(char s[])
{
    int id = 0;
    for (int i = 0; i < 3; i++)
        id = id * 26 + (s[i] - 'A');
    id = id * 10 + s[3] - '0';
    return id;
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

    int n, m, no, k;
    char name[5];
    vector<int> info[M];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &no, &k);
        for (int j = 0; j < k; j++) {
            scanf("%s", name);
            int id = getId(name);
            info[id].push_back(no);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        int id = getId(name);
        sort(info[id].begin(), info[id].end());
        int len = info[id].size();
        printf("%s %d", name, len);
        for (int j = 0; j < len; j++)
            printf(" %d", info[id][j]);
        printf("\n");
    }

    return 0;
}