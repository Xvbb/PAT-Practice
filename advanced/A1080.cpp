#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 4 * 1e4 + 10;
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
int quota[100] = { 0 };
int t[100] = { 0 };
int p[100][maxn] = { 0 };
struct student {
    int ge;
    int gi;
    int perfer[5];
    int grade;
    int num;
} s[maxn];
struct school {
    int stu[maxn];
    int last;
    int ge;
} sch[110];
bool cmp(student s1, student s2)
{
    if (s1.grade != s2.grade)
        return s1.grade > s2.grade;
    else
        return s1.ge > s2.ge;
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

    int n, m, k;
    int pre_grade, pre_school;
    scanf("%d%d%d", &n, &m, &k);
    // get data
    for (int i = 0; i < m; i++)
        scanf("%d", &quota[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &s[i].ge, &s[i].gi);
        s[i].grade = s[i].ge + s[i].gi;
        s[i].num = i;
        for (int j = 0; j < k; j++) {
            scanf("%d", &s[i].perfer[j]);
        }
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            t[s[i].perfer[0]]++;
            pre_grade = s[i].grade;
            pre_school = s[i].perfer[0];
            sch[s[i].perfer[0]].stu[0] = s[i].num;
            sch[s[i].perfer[0]].last = s[i].grade;
            sch[s[i].perfer[0]].ge = s[i].ge;
            continue;
        }

        for (int j = 0; j < k; j++) {
            int pre = s[i].perfer[j];
            if (t[pre] < quota[pre]) {
                sch[pre].stu[t[pre]] = s[i].num;
                t[pre]++;
                sch[pre].last = s[i].grade;
                sch[pre].ge = s[i].ge;
                break;
            } else if (s[i].grade == sch[pre].last && s[i].ge == sch[pre].ge) {
                sch[pre].stu[t[pre]] = s[i].num;
                t[pre]++;
                break;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        sort(sch[i].stu, sch[i].stu + t[i]);
    }
    for (int i = 0; i < m; i++) {
        if (t[i] != 0) {
            for (int j = 0; j < t[i]; j++) {
                printf("%d", sch[i].stu[j]);
                if (j < t[i] - 1)
                    printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}