#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int a[maxn] = { 0 };
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int pos = -1, count = 0, n = 0, now = 0, t = 0, num, k = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        // 数组存储每个数对应的下标位置
        a[num] = i;
        if (num != i && num != 0)
            count++;
    }
    while (count > 0) {
        if (a[0] == 0) {
            while (k < n) {
                if(a[k] != k) {
                    swap(a[0], a[k]);
                    t++;
                    break;
                }
                k++;
            }
        }
        while (a[0] != 0) {
            swap(a[0], a[a[0]]);
            pos = now;
            count--;
            t++;
        }
    }
    printf("%d", t);
    return 0;
}