#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
LL Map[256];
#define inf 0x7fffffff
//溢出
//LL inf = (1LL << 63) - 1;
void init()
{
    for (char c = '0'; c <= '9'; c++) {
        Map[c] = c - '0';
    }
    for (char c = 'a'; c <= 'z'; c++) {
        Map[c] = c - 'a' + 10;
    }
}
// 转换成十进制
LL convertTo10(string a, LL radix, LL t)
{
    int len = a.size();
    LL ans = 0;
    for (int i = 0; i < len; i++) {
        ans = radix * ans + Map[a[i]];
        // 判断溢出
        // if (ans > t || ans < 0)
        if (ans < 0)
            return -1;
    }
    return ans;
}
// 判断当前进制是否过大、过小、可用。t为N1的十进制值
int cmp(string a, LL radix, LL t)
{
    int len = a.size();
    LL num = convertTo10(a, radix, t);
    // 溢出
    if (num < 0)
        return 1;
    // 过大
    if (num > t)
        return 1;
    // 一致
    else if (t == num)
        return 0;
    // 过小
    else
        return -1;
}
LL binarySearchMy(string a, LL left, LL right, LL t)
{
    LL mid;
    //printf("%lld  %lld\n", right, left);
    while (left <= right) {
        mid = left + (right - left) / 2;
        int flag = cmp(a, mid, t);
        if (flag == 0)
            return mid;
        else if (flag == -1)
            left = mid + 1;
        else
            right = mid - 1;
    }
    // 不存在
    return -1;
}
// 找当前字符串最大的数值，说明至少是该数+1进制
int findLargestDigit(string b)
{
    int len = b.size(), ans = -1;
    for (int i = 0; i < len; i++) {
        if (Map[b[i]] > ans)
            ans = Map[b[i]];
    }
    return ans + 1;
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

    string a, b, temp;
    LL tag, radix;
    cin >> a >> b >> tag >> radix;
    if (a == b) {
        cout << radix;
        return 0;
    }
    // a始终为已知进制对应的数
    if (tag == 2) {
        swap(a, b);
    }
    init();
    LL t = convertTo10(a, radix, inf);
    LL low = findLargestDigit(b);
    LL high = max(low, t) + 1;
    LL ans = binarySearchMy(b, low, high, t);
    if (ans == -1)
        cout << "Impossible";
    else
        cout << ans;
    return 0;
}