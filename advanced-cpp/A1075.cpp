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
struct student {
    int id;
    int grade[5];
    int all;
    int perfect;
    int falg;
} s[maxn] = { 0, { -2, -2, -2, -2 }, 0, 0, 0 };
bool cmp(student s1, student s2)
{
    if (s1.falg != s2.falg)
        return s1.falg > s2.falg;
    if (s1.all != s2.all)
        return s1.all > s2.all;
    else if (s1.perfect != s2.perfect)
        return s1.perfect > s2.perfect;
    else
        return s1.id < s2.id;
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

    int a, b, n;
    int grade[5];
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 0; i < b; i++)
        scanf("%d", &grade[i]);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 5; j++)
            s[i].grade[j] = -2;
    for (int i = 0; i < n; i++) {
        int id, no, g;
        scanf("%d %d %d", &id, &no, &g);
        s[id - 1].id = id;
        if (s[id - 1].grade[no - 1] <= g) {
            s[id - 1].grade[no - 1] = g;
        }
        if (g >= 0)
            s[id - 1].falg = 1;
    }
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j < b; j++) {
            if (s[i].grade[j] > 0)
                s[i].all += s[i].grade[j];
            else {
                if (s[i].grade[j] == -1)
                    continue;
            }
            if (s[i].grade[j] == grade[j])
                s[i].perfect++;
        }
    }
    sort(s, s + a, cmp);
    int rank = 1;
    for (int i = 0; i <= a; i++) {
        if (s[i].all != 0 || s[i].falg) {
            if (i == 0) {
                printf("1 %05d %d", s[i].id, s[i].all);
            } else {
                if (s[i].all == s[i - 1].all) {
                    printf("%d %05d %d", rank, s[i].id, s[i].all);
                } else {
                    rank = i + 1;
                    printf("%d %05d %d", rank, s[i].id, s[i].all);
                }
            }
        } else
            continue;
        for (int j = 0; j < b; j++) {
            if (s[i].grade[j] == -2)
                printf(" -");
            else if (s[i].grade[j] == -1)
                printf(" 0");
            else
                printf(" %d", s[i].grade[j]);
            if (j == b - 1)
                printf("\n");
        }
    }
    return 0;
}