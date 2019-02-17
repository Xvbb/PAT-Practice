#include <cstdio>

int main(int argc, char const *argv[])
{
    int n;
    long long a, b, c;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        long long ans = a + b;
        if(a > 0 && b > 0 && ans < 0)       printf("Case #%d: true", i + 1);
        else if(a < 0 && b < 0 && ans >= 0) printf("Case #%d: false", i + 1);
        else if (a + b > c)                 printf("Case #%d: true", i + 1);
        else                                printf("Case #%d: false", i + 1);
        if(i < n - 1)                       printf("\n");
    }
    return 0;
}
