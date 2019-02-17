#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
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
struct student{
    char name[11];
    char id[11];
    int grade;
} s[maxn], cop[maxn];
bool cmp(student s1, student s2) {
    if(s1.grade != s2.grade)
        return s1.grade > s2.grade;
    else
        return s1.name < s2.name;
}
#define LOCAL_XBB

int
main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, min ,max;
    int valid = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", s[i].name, s[i].id, &s[i].grade);
    }
    scanf("%d%d", &min, &max);
    for (int i = 0; i < n; i++) {
        if(s[i].grade >= min && s[i].grade <= max) {
            cop[valid] = s[i];
            valid++;
        }
    }
    if(valid == 0) {
        printf("NONE");
        return 0;
    }
    sort(cop, cop + valid, cmp);
    for (int i = 0; i < valid; i++) {
        printf("%s %s", cop[i].name, cop[i].id);
        if(i != valid - 1)
            printf("\n");
    }

    return 0;
}