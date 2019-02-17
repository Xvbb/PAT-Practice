#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
const int hl_100 = 265;
const int goal = 1e5;
////string转int
int my_to_int(string s)
{
    stringstream ss;
    int a;
    ss.clear();
    ss << s;
    ss >> a;
    return a;
}
////字符串数组转int
int my_to_int(char s[])
{
    int k;
    sscanf(s, "%d", &k);
    return k;
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

    int a;
    int count = 0, index = 0;
    string id;
    while (scanf("%d", &a) != EOF) {
        count += (a / 20);
        index++;
    }
    int total = count * hl_100;
    printf("%d人\n", index);
    printf("%d只100hl\n", count);
    printf("总贡献%d\n", total);
    if (total >= goal) {
        printf("ojbk肉够");
        printf("过剩%.2f亿贡献", 1.00 * (total - goal)/10000);
    } else {
        printf("距离目标还差%d贡献\n", goal - total);
        printf("还差%d肉\n", (goal - total) / 265 * 20);
    }

    return 0;
}