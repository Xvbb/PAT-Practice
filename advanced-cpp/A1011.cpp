#include <cstdio>

char A[3] = {'W', 'T', 'L'};

int main(int argc, char const *argv[])
{
    int map[3];
    double a, b, c, ans = 1;
    for(int i = 0; i < 3; i++) {
        scanf("%lf %lf %lf", &a, &b, &c);
        if(a > b && a > c)  {
            ans *= a;
            map[i] = 0;
        }
        if(b > a && b > c) {
            ans *= b;
            map[i] = 1;
        }
        if(c > a && c > b) {
            ans *= c;
            map[i] = 2;
        }
    }
    for(int i = 0; i < 3; i++) {
        printf("%c", A[map[i]]);
        if(i < 2)   printf(" ");
    }
    printf(" %.2f", (ans*0.65-1)*2);
    return 0;
}
