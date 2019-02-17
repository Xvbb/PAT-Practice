#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
char symbol[5] = { '+', '-', '*', '/' };
LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void myPrint(LL up, LL down, LL rest)
{
    if (abs(up) > abs(down) && rest != 0) {
        if ((up < 0 && down > 0) || (up > 0 && down < 0))
            printf("(%lld %lld/%lld)", up / down, abs(up % down), abs(down));
        else
            printf("%lld %lld/%lld", up / down, up % down, down);
    } else if (rest == 0) {
        if ((up < 0 && down > 0) || (up > 0 && down < 0))
            printf("(%lld)", up / down);
        else
            printf("%lld", up / down);
    } else {
        if ((up < 0 && down > 0) || (up > 0 && down < 0))
            printf("(%lld/%lld)", -abs(up), abs(down));
        else
            printf("%lld/%lld", up, down);
    }
}
void simplify(LL a, LL b)
{
    if (a == 0)
        printf("0");
    else if (b == 0)
        printf("Inf");
    else {
        int gys = gcd(abs(a), abs(b));
        a /= gys;
        b /= gys;
        LL rest = a % b;
        myPrint(a, b, rest);
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

    LL up = 0, down = 1, gys, rest, gysUp, gysDown;
    LL a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);

    // +
    up = c * b + a * d;
    down = b * d;
    simplify(a, b);
    printf(" + ");
    simplify(c, d);
    printf(" = ");
    simplify(up, down);
    printf("\n");

    // -
    up = a * d - c * b;
    down = b * d;
    simplify(a, b);
    printf(" - ");
    simplify(c, d);
    printf(" = ");
    simplify(up, down);
    printf("\n");

    // *
    up = a * c;
    down = b * d;
    simplify(a, b);
    printf(" * ");
    simplify(c, d);
    printf(" = ");
    simplify(up, down);
    printf("\n");

    // /
    up = a * d;
    down = b * c;
    simplify(a, b);
    printf(" / ");
    simplify(c, d);
    printf(" = ");
    simplify(up, down);
    printf("\n");

    return 0;
}