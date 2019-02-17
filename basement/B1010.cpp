#include <cstdio>

int main(int argc, char const *argv[])
{
    int a[1010]={0};
    int i = 0, c, d;
    int count = 0;
    while(scanf("%d%d", &c, &d) != EOF) {
        if(c == 0) {
            a[i] = 0;
            a[i + 1] = 0; 
        } else if(d == 0) {
            a[i] = 0;
            a[i + 1] = 0;
        } else {
            a[i] = c * d;
            a[i + 1] = d - 1;
            count++;
        }
        i += 2;
    }
    if (count == 0) printf("0 0");
    else {
        for(int k = 0; k < i; k = k + 2) {
            if(a[k] != 0) {
                printf("%d %d", a[k], a[k+1]);
                count--;
                if (count != 0)  printf(" ");
            }
        }
    }
    return 0;
}
