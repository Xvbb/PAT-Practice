#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
    int n;
    char a;
    scanf("%d %c", &n, &a);
    int k = (int)sqrt((n+1)/2);
    for(int i = 0; i < k; i++){
        for(int m = i; m >0; m--)   printf(" ");
        for (int j = 2 * (k - i) -1; j > 0; j--){
            printf("%c", a);
        }
        printf("\n");
    }
    for(int i = 1; i < k; i++) {
        for(int m = k - i - 1; m >0; m--)   printf(" ");
        for (int j = 2 * i + 1; j > 0; j--){
            printf("%c", a);
        }
        printf("\n");
    }
    printf("%d", n - 2 * k * k + 1);

    return 0;
}
