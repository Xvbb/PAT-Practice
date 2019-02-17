#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
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

int age[201] = { 0 };
struct data {
    char name[9];
    int age;
    int money;
} d[maxn], valid[100];

bool cmp(data d1, data d2)
{
    if (d1.money != d2.money)
        return d1.money > d2.money;
    else if (d1.age != d2.age)
        return d1.age < d2.age;
    else
        return strcmp(d1.name, d2.name) < 0;
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

    int a, b;
    int n, min, max;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%s %d %d", d[i].name, &d[i].age, &d[i].money);
    }
    sort(d, d + a, cmp);
    int count = 0;
    // 每个年龄前100名数据拉出来，预处理减少后续数据量
    for (int i = 0; i < a; i++) {
        if (age[d[i].age] < 100) {
            age[d[i].age]++;
            valid[count++] = d[i];
        }
    }
    for (int k = 1; k <= b; k++) {
        scanf("%d %d %d", &n, &min, &max);
        printf("Case #%d:\n", k);
        int flag = 0;
        for (int i = 0; i < count; i++) {
            //printf("i = %d, name = %s money = %d, age = %d\n", i,d[i].name, d[i].money,d[i].age);
            if (valid[i].age <= max && valid[i].age >= min) {
                if (flag == n)
                    break;
                flag++;
                printf("%s %d %d\n", valid[i].name, valid[i].age, valid[i].money);
            }
        }
        if (flag == 0)
            printf("None\n");
    }

    return 0;
}