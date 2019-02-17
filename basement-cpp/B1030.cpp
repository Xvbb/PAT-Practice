#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL a[maxn] = { 0 };
int n;
LL p;
// 查找a[i + 1]到a[n - 1]范围内第一个大于x的数的位置
int binarySearch(int i, LL x)
{
    if (a[n - 1] <= x)
        return n;
    int l = i + 1, h = n - 1, mid;
    while (l < h) {
        mid = l + (l + h) / 2;
        if (a[mid] < x) {
            l = mid + 1;
        } else if (a[mid] > x) {
            h = mid;
        } else {
            return mid;
        }
    }
    return l;
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
    int ans = 0;
    scanf("%d%lld", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    // for (int i = 0; i < n; i++) {
    //     int j = binarySearch(i, p * a[i]);
    //     ans = max(ans, j - i);
    // }
    for (int i = 0; i < n; i++) {
        int j = upper_bound(a + i + 1, a + n, p * a[i]) - a;
        ans = max(ans, j - i);
    }
    printf("%d", ans);
    return 0;
}