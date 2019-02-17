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

#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    map<int, int> s;
    int team, winner;
    int grade, member;
    int max = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d-%d %d", &team, &member, &grade);
        if (s.find(team) == s.end()) {
            s[team] = 0;
        }
        s[team] += grade;
        if (s[team] > max) {
            max = s[team];
            winner = team;
        }
    }
    printf("%d %d", winner, max);
    return 0;
}