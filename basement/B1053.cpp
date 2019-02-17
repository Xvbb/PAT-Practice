#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
#define LOCAL_XBB
typedef struct student {
    string id;
    int de;
    int cai;
} stu1, stu2;
bool cmp(student stu1, student stu2)
{
    if (stu1.de + stu1.cai != stu2.de + stu2.cai)
        return stu1.de + stu1.cai < stu2.de + stu2.cai;
    else if (stu1.de != stu2.de)
        return stu1.de < stu2.de;
    else
        return stu1.id < stu2.id;
}

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB
    int n, l, h;
    string id;
    int de, cai;
    int a = 0, b = 0, c = 0;
    //student s1[maxn], s2[maxn], s3[maxn];
    cin >> n >> l >> h;
    // for (int i = 0; i < n; i++) {
    //     cin >> id >> de >> cai;
    //     if (de >= h && cai >= h) {
    //         s1[a].id = id;
    //         s1[a].de = de;
    //         s1[a].cai = cai;
    //         a++;
    //     } else if (de >= h && cai >= l) {
    //         s2[b].id = id;
    //         s2[b].de = de;
    //         s2[b].cai = cai;
    //         b++;
    //     } else if (de >= l && cai >= l) {
    //         s3[c].id = id;
    //         s3[c].de = de;
    //         s3[c].cai = cai;
    //         c++;
    //     }
    // }
    // sort(s1, s1 + a, cmp);
    // sort(s2, s2 + b, cmp);
    // sort(s3, s3 + c, cmp);
    // cout << a + b + c << endl;
    // for (int i = 0; i < a; i++)
    //     cout << s1[i].id << " " << s1[i].de << " " << s1[i].cai << endl;
    // for (int i = 0; i < b; i++)
    //     cout << s2[i].id << " " << s2[i].de << " " << s2[i].cai << endl;
    // for (int i = 0; i < c; i++)
    //     cout << s3[i].id << " " << s3[i].de << " " << s3[i].cai << endl;

    return 0;
}