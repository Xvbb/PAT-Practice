#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);                      

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
//#define LOCAL_XBB

int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int a[10] = {0};
    int flag = 1;
    string c = "";
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < 10; i++) {
        if(a[i] != 0) {
            if(flag) {
                c += to_string(i);
                a[i] -= 1;
                while(a[0] > 0) {
                    c += "0";
                    a[0]--;
                }   
                while(a[i] > 0) {
                    c += to_string(i);
                    a[i]--;
                }   
                flag = 0;
            } else {
                while(a[i] > 0) {
                    c += to_string(i);
                    a[i]--;
                }   
            }
        }

    }
    cout << c;

    return 0;
}