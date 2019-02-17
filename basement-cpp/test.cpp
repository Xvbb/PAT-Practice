#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;

#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int recover = 58, consume_1 = 20, counsume_2 = 30;
    double get_meat = 1.5, use_meat = 3;
    int get_1 = 23, get_2 = 48;
    int total = 2000 * 16;
    int times;
    cin >> times;
    int a = times * get_meat / use_meat * 48 + times * 23;
    int b = (times * consume_1 + times * get_meat / use_meat * counsume_2) / recover;
    double c = 1.0 * (2 * get_1 + get_2) / (2 * consume_1 + counsume_2) * recover;
    double d = 1.0 * (a - (b - 1.0 * a / 2000 * 10) * c) / 100;
    cout << "得到" << a << "战货" << endl;
    cout << "打了" << times << "次肉本， " << times * get_meat / use_meat << "次ex" << endl;
    cout << "消耗" <<  b << "红" << endl;
    cout << "如果不耗红，需要出现" << d << "次hl" << endl;
    cout << "平均" << 1.0 * times * get_meat / use_meat / d
         << "次ex出一个HL" << endl;
    return 0;
}