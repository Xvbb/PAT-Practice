// 头文件，只要一个，其他include全都不用写了
#include <bits/stdc++.h>    
// 加速cin cout
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
// c++ 必备，写上就是
using namespace std;
// 给long long取别名，代码里写LL相当于写long long
typedef long long LL;
// 科学计数法，一般用来表示数组的最大长度，下面的表示10的5次方再加10
const int maxn = 1e5 + 10;
// 我自己写的string转int函数,现在你不用管
int my_to_int(string s)
{
    stringstream ss;
    int a;
    ss.clear();
    ss << s;
    ss >> a;
    return a;
}
// 我自己写的字符串数组转int函数
int my_to_int(char s[])
{
    int k;
    sscanf(s, "%d", &k);
    return k;
}
// 预处理命令，本地测试main函数执行时，从_in文件里读取数据，就不用每次自己手敲。把数据放在_in文件里就行
// 在oj上提交代码的时候，在这一行前面加//注释掉就行了，不然会从错误的地方读数据
//#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    // 这里就是代码开始写的地方
    char str[100] = "(๑•̀ㅂ•́)و✧加油易青蓝";
    printf("%s\n", str);
    // cout是c++语法，输出的时候不需要指定变量类型，更省心，但速度相对printf慢，oj测试的时候可能会超时。这也是上面预处理IO的原因。
    // 效果和上面一行等价
    cout << str << endl;

    int n;
    printf("请输入一个1~10的数值");
    scanf("%d", &n);
    // 这俩等价
    // cin >> n;
    for (int i = 0; i < n; i++) {
        printf("开开心心每一天\n");
    }

    // 效果是暂停，输入任意值后继续执行代码
    system("pause");
    return 0;
}