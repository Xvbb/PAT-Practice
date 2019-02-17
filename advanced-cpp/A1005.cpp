#include <cstdio>
#include <cstring>

char s[10][6] = {
    "zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine"
};

int main(int argc, char const *argv[])
{
    char a[110], b[10];
    int ans = 0;
    scanf("%s", a);
    int len = strlen(a);
    for(int i = 0; i < len; i++) {
        ans += (a[i] - '0');
    }
    sprintf(b, "%d", ans);
    for(int i = 0; i < strlen(b); i++) {
        printf("%s", s[b[i] - '0']);
        if(i < strlen(b) - 1)   printf(" ");
    }
    return 0;
}
