#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int s[50] = { 0 };
bool isPrime(int a)
{
    if (a == 1)
        return false;
    if (a == 2)
        return true;
    if (a % 2 == 0)
        return false;
    int n = (int)sqrt(a);
    for (int i = 3; i <= n; i += 2) {
        if (a % i == 0)
            return false;
    }
    return true;
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

    int n, a, i = 2, index = 0, count = 1, last;
    scanf("%d", &a);
    if (a == 1) {
        printf("1=1");
        return 0;
    }
    if(isPrime(a)) {
        printf("%d=%d", a,a);
        return 0;
    }
    n = (int)sqrt(a);
    int temp = a;
    while (a) {
        if (a % i == 0) {
            s[index++] = i;
            a /= i;
            if (isPrime(a)) {
                s[index++] = a;
                break;
            }
        } else {
            do {
                i++;
            } while (isPrime(i) == false);
        }
    }
    last = s[0];
    printf("%d=%d", temp, last);
    for (int i = 1; i < index; i++) {
        if (s[i] == last)
            count++;
        else {
            if (count == 1)
                printf("*%d", s[i]);
            else
                printf("^%d*%d", count, s[i]);
            last = s[i];
            count = 1;
        }
    }
    if (count != 1)
        printf("^%d", count);

    return 0;
}