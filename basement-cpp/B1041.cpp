#include <cstdio>
#include <cstring>

typedef struct data{
    long long c;
    int b;
}data;

int main(int argc, char const *argv[])
{
    int n, m;
    int a, b;
    long long c;
    scanf("%d", &n);
    data s[1010];
    for(int i = 0; i < n; i++) {
        scanf("%lld %d %d", &c, &a, &b);
        s[a].b = b;
        s[a].c = c;
    }
    scanf("%d", &m);
    int d;
    for(int i = 0; i < m; i++) {
        scanf("%d", &d);
        printf("%lld %d\n", s[d].c, s[d].b);
    }
    
    return 0;
}
