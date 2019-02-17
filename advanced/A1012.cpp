#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e6 + 10;
int pos[maxn][5] = { 0 };
string str[6] = { "C", "M", "E", "A" };
typedef struct student {
    char id[7];
    int a;
    int b;
    int c;
    int d;
} stu1, stu2;

bool cmp_a(student stu1, student stu2)
{
    if (stu1.a != stu2.a)
        return stu1.a > stu2.a;
    else
        return stu1.id < stu2.id;
}
bool cmp_b(student stu1, student stu2)
{
    if (stu1.b != stu2.b)
        return stu1.b > stu2.b;
    else
        return stu1.id < stu2.id;
}
bool cmp_c(student stu1, student stu2)
{
    if (stu1.c != stu2.c)
        return stu1.c > stu2.c;
    else
        return stu1.id < stu2.id;
}
bool cmp_d(student stu1, student stu2)
{
    if (stu1.d != stu2.d)
        return stu1.d > stu2.d;
    else
        return stu1.id < stu2.id;
}

void myFunction(int n)
{
    int k = 3;
    for (int i = 0; i < 3; i++) {
        if (pos[n][i] < pos[n][k])
            k = i;
    }
    cout << pos[n][k] << " " << str[k] << endl;
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
    int n, m;
    student s[2010];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> s[i].id >> s[i].a >> s[i].b >> s[i].c;
        s[i].d = s[i].a + s[i].b + s[i].c;
    }
    for (int j = 0; j < 4; j++) {
        if (j == 0)
            sort(s, s + n, cmp_a);
        if (j == 1)
            sort(s, s + n, cmp_b);
        if (j == 2)
            sort(s, s + n, cmp_c);
        if (j == 3)
            sort(s, s + n, cmp_d);
        int k, l;
        sscanf(s[0].id, "%d", &k);
        pos[k][j] = 1;
        for (int i = 1; i < n; i++) {
            sscanf(s[i].id, "%d", &k);
            if (s[i].a == s[i - 1].a) {
                sscanf(s[i - 1].id, "%d", &l);
                pos[k][j] = pos[l][j];
            } else
                pos[k][j] = i + 1;
        }
    }
    for (int i = 0; i < m; i++) {
        int k;
        char id[8];
        cin >> id;
        sscanf(id, "%d", &k);
        if (pos[k][0] == 0)
            cout << "N/A" << endl;
        else
            myFunction(k);
    }

    return 0;
}