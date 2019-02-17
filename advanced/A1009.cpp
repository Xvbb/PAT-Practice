#include <cstdio>

int main(int argc, char const *argv[])
{
    int n_1, n_2;
    double e;
    int r;
    int count = 0;
    double a[1001] = {0}, b[1001] = {0}, c[2001]= {0};
    scanf("%d", &n_1);
    for(int i = 0; i < n_1; i++) {
        scanf("%d %lf", &r, &e);
        a[r] += e;
    }
    scanf("%d", &n_2);
    for(int i = 0; i < n_2; i++) {
        scanf("%d %lf", &r, &e);
        b[r] += e;
    }
    for(int i = 0; i < 1001; i++){
        if(a[i] != 0) {
            for(int j = 0; j < 1001; j++) {
                if(b[j] != 0) {
                    c[i+j] += a[i] * b[j];
                }
            }
        }
    }
    
    for(int i = 0; i < 2001; i++) {
        if(c[i] != 0) {
            count++;
        }
    }
    printf("%d", count);
    for(int i = 2000; i >= 0; i--) {
        if(c[i] != 0.0) {
            printf(" %d %.1f", i, c[i]);
        }
    }
    return 0;
}
