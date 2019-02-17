#include <cstdio>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n / 100; i++) {
        printf("B");
    }
    n %= 100;
    for(int i = 0; i < n / 10; i++) {
        printf("S");
    }
    for(int i = 0; i < n % 10; i++) {
        printf("%d", i + 1);
    }
    return 0;
}
