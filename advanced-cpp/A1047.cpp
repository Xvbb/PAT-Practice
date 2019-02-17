#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);                      

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
const int N = 40010;
#define LOCAL_XBB

int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    vector<string> info[N];
    int n, m, k, course;
    char name[5];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", name, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &course);
            info[course].push_back(name);
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d %lu\n", i, info[i].size());
        sort(info[i].begin(), info[i].end());
        for (int j = 0; j < info[i].size(); j++)
            printf("%s\n", info[i][j].c_str());
    }

    return 0;
}