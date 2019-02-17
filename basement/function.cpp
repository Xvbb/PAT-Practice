#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;

// 快速幂
LL binaryPow(LL a, LL b, LL m);
// 思想，输出给定数组元素中两两和为m的元素对
void twoPointer(int a[], int n, int m);
// 二路归并,将数组A的[l1,r1],[l2,r2]合并为有序区间
void merge(int a[], int l1, int r1, int l2, int r2);
// 归并排序
void mergesor(int a[], int left, int right);
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    return 0;
}
// 常规
LL binaryPow(LL a, LL b, LL m)
{
    LL ans = 1;
    for (int i = 0; i < b; i++) {
        ans = ans * a % m;
    }
    return ans;
}
// 递归
LL binaryPow(LL a, LL b, LL m)
{
    if (b == 0)
        return 1;
    // b%2 == 1
    if (b & 1)
        return a * binaryPow(a, b - 1, m) % m;
    else {
        LL mul = binaryPow(a, b / 2, m);
        return mul * mul % m;
    }
}

//  迭代写法
LL binaryPow(LL a, LL b, LL m)
{
    LL ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >> 1;
    }
    return ans;
}

void twoPointer(int a[], int n, int m)
{
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] == m)
            printf("%d %d", a[i], a[j]);
        else {
            if (a[i] + a[j] < m)
                i++;
            else
                j--;
        }
    }
}

void merge(int a[], int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2;
    int index = 0;
    int temp[maxn];
    while (i < r1 && j < r2) {
        if (a[i] <= a[j]) {
            temp[index++] = a[i];
        } else {
            temp[index++] = a[j];
        }
    }
    while (i <= r1)
        temp[index++] = a[i++];
    while (j <= r2)
        temp[index++] = a[j++];
    for (int i = 0; i < index; i++)
        a[l1 + i] = temp[i];
}

void mergesort(int a[], int left, int right)
{
    if (left < right) {
        int mid = left + (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, mid + 1, right);
    }
}