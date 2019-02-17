#include <bits/stdc++.h>
#define IO                          \
    ios::sync_with_stdio(false);    \
    cin.tie(0);                     \
    cout.tie(0);                      

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
#define LOCAL_XBB

typedef struct sell{
    double amount;
    double totalPrice;
    double price;
}data1, data2;

bool cmp(sell data1, sell data2){
    if(data1.price != data2.price)  return data1.price >= data2.price;
    else return data1.amount <= data2.amount;
}

int main(){
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int a, b;
    cin >> a >> b;
    sell s[a];
    for(int i = 0; i < a; i++)  cin >> s[i].amount;
    for(int i = 0; i < a; i++)  cin >> s[i].totalPrice;
    for(int i = 0; i < a; i++)  s[i].price = 1.00 * s[i].totalPrice / s[i].amount;
    sort(s, s + a, cmp);
    double ans = 0.00;
    for(int i = 0; i < a; i++) {
        if(s[i].amount <= b) {
            ans += s[i].totalPrice;
            b -= s[i].amount;
        } else {
            ans += b * s[i].price;
            break;
        }
    }
    printf("%.2f", ans);
    return 0;
}