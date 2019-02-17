#include <cstdio>

int main(int argc, char const *argv[])
{
    int n;
    char a;
    scanf("%d %c", &n, &a);
    for(int i = 0; i < n; i++)  printf("%c", a);
    printf("\n");
    int b = (n % 2 == 0) ? n / 2 - 2 : n / 2 - 1;
    for (int i = 0; i < b; i++) {
        printf("%c", a);
        for (int j = 0; j < n - 2; j++) printf(" ");
        printf("%c\n", a);
    }
    for(int i = 0; i < n; i++)  printf("%c", a);
    return 0;
}
