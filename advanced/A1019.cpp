#include <cstdio>

int main(int argc, char const *argv[])
{
     int a,b;
    int c[10000];
    int count = 0;
    int flag = 1;
    scanf("%d%d", &a, &b);
    if (a == 0) {
        printf("No\n0");
    } else {
        while(a){
            c[count++] = a % b;
            a /= b;
        }
        for(int i = 0; i < count / 2; i++) {
            if(c[i] !=  c[count - 1 - i]) {
                printf("No\n");
                flag = 0;
                break;
            }
        }
        if(flag)    printf("Yes\n");
        for(int i = count - 1; i >= 0; i--) {
            printf("%d", c[i]);
            if(i != 0)  printf(" ");
        }
    }
    return 0;
}