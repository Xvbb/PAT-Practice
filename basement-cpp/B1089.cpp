#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int n;
// 判断2数组是否一致
bool isSame(int a[], int b[])
{
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
void showArray(int a[])
{
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
}
bool insertSort(int a[], int b[])
{
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (i != 1 && isSame(a, b))
            flag = true;
        int temp = a[i], j = i, count = 0;
        for (; j >= 0 && a[j - 1] > temp; j--) {
            a[j] = a[j - 1];
            count++;
        }
        a[j] = temp;
        if (flag == true && count != 0)
            return true;
    }
    return false;
}
void mergerSort(int a[], int b[])
{
    bool flag = false;
    for (int step = 2; step / 2 <= n; step *= 2) {
        if (step != 2 && isSame(a, b))
            flag = true;
        for (int i = 0; i < n; i += step)
            sort(a + i, a + min(i + step, n));
        if (flag == true) {
            printf("Merge Sort\n");
            showArray(a);
            return;
        }
    }
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

    // a原始数列，b比较数列，c原始备份
    int a[110], b[110], c[110];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    if (insertSort(a, b)) {
        printf("Insertion Sort\n");
        showArray(a);
    } else {
        for (int i = 0; i < n; i++)
            a[i] = c[i];
        mergerSort(a, b);
    }
    return 0;
}