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
        return stu1.de + stu1.cai > stu2.de + stu2.cai;
    else if (stu1.de != stu2.de)
        return stu1.de > stu2.de;
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
    vector<student> v1, v2, v3, v4;
    cin >> n >> l >> h;
    for (int i = 0; i < n; i++) {
        student s;
        cin >> s.id >> s.de >> s.cai;
        if (s.de >= h && s.cai >= h) {
            v1.push_back(s);
        } else if (s.de >= h && s.cai >= l) {
            v2.push_back(s);
        } else if (s.de >= s.cai && s.de >= l && s.cai >= l) {
            v3.push_back(s);
        } else if (s.de >= l && s.cai >= l) {
            v4.push_back(s);
        }
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    sort(v3.begin(), v3.end(), cmp);
    sort(v4.begin(), v4.end(), cmp);
    cout << v1.size() + v2.size() + v3.size() + v4.size() << endl;
    for (vector<student>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << (*it).id << " " << (*it).de << " " << (*it).cai << endl;
    }
    for (vector<student>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << (*it).id << " " << (*it).de << " " << (*it).cai << endl;
    }
    for (vector<student>::iterator it = v3.begin(); it != v3.end(); it++) {
        cout << (*it).id << " " << (*it).de << " " << (*it).cai << endl;
    }
    for (vector<student>::iterator it = v4.begin(); it != v4.end(); it++) {
        cout << (*it).id << " " << (*it).de << " " << (*it).cai << endl;
    }
    return 0;
}