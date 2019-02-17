#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
const int maxm = 1e8 + 10;
int min = maxm;
int a[maxn] = { 0 };
int findUpperBound(int low, int high, int m)
{
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (a[mid] > m)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
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

    int n, m, count = 0, min = maxn;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = a[i] + a[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        int j = findUpperBound(i, n + 1, a[i - 1] + m);
        // 存在差值>=m
        if (a[j - 1] - a[i - 1] == m) {
            min = m;
            break;
        } else if (j <= n && a[j] - a[i - 1] < min) {
            min = a[j] - a[i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        int j = findUpperBound(i, n + 1, a[i - 1] + min);
        if (a[j - 1] - a[i - 1] == min)
            printf("%d-%d\n", i, j - 1);
    }
    return 0;
}