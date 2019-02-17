#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
string s;
int a[30];
void stringToArray()
{
    a[30] = { 0 };
    int len = s.size() - 1;
    int i = 0;
    while (len--) {
        a[i++] = a[len] - '0';
    }
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

    cin >> s;
    int count = 0;
    int len = s.size();
    stringToArray();
    if()
    while(len > 0){
        if(s[len - 1] > "1")
            count = count + 1;
    }

    return 0;
}