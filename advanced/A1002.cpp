#include <cstdio>

int main(int argc, char const *argv[])
{
    int n_1, n_2;
    int x, count = 0;
    double r;
    double a[1010] = {0};
    scanf("%d", &n_1);
    for(int i = 0; i < n_1; i++) {
        scanf("%d%lf", &x, &r);
        a[x] += r;
    }
    scanf("%d", &n_2);
    for(int i = 0; i < n_2; i++) {
        scanf("%d%lf", &x, &r);
        a[x] += r;
    }

    for(int i = 0; i <= 1000; i++) {
        if(a[i] != 0) count++;
    }
    printf("%d", count);
    for(int i = 1000; i >= 0; i--) {
        if(a[i] != 0) {
            printf(" %d %.1f", i, a[i]);
        }
    }
    return 0;
}
