#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);      

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;

typedef struct student{
    string id;
    int grade;
    int rank;
    int pos;
}stu1, stu2;

bool cmp(student stu1, student stu2){
    if(stu1.grade != stu2.grade) return stu1.grade > stu2.grade;
    else    return stu1.id < stu2.id;
}
#define LOCAL_XBB
int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, k = 0;
    cin >> n;
    student stu[30001];
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
           cin >> stu[k + j].id >> stu[k + j].grade;
           stu[k + j].pos  = i + 1;
        }
        sort(stu + k, stu + k + a, cmp);
        stu[k].rank = 1;
        for(int j = k + 1; j < k + a; j++) {
            if(stu[j].grade == stu[j - 1].grade)    stu[j].rank = stu[j - 1].rank;
            else stu[j].rank = j - k + 1;
        }
        k += a;
    }
    sort(stu, stu + k, cmp);
    cout << k << endl;
    int r = 1;
    for(int i = 0; i < k; i++) {
        cout << stu[i].id << " ";
        if(i == 0)  cout << 1 << " ";
        else {
            if(i > 0 && stu[i].grade != stu[i - 1].grade)    r = i + 1;
            cout << r << " ";
        }
        cout << stu[i].pos << " " << stu[i].rank << endl;

    }
    return 0;
}