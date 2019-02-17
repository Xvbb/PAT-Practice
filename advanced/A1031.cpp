#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    char a[81];
    char temp;
    int i = 0;
    scanf("%s", a);
    int k = strlen(a);
    int n1 = (k + 2) / 3;
    int n2 = k - 2 * n1 + 2;
    for(; i < n1 - 1; i++) {
        printf("%c", a[i]);
        for(int j = 0; j < n2 - 2; j++) printf(" ");
        printf("%c\n", a[k - i - 1]);
    }
    int m = k - i;
    while(i < m) {
        printf("%c", a[i]);
        i++;
    }
    return 0;
}
