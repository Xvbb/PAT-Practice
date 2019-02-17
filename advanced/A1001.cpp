#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    int c = a + b;
    if(c == 0)  printf("0");
    else{
        int count = 0, j = 0;
    char s[20];
    char symbol = c >= 0 ? '+' : '-';
    c = c > 0? c : -c;
    while(c) {
        s[count] = c % 10 + '0';
        if((count - j) % 3 == 2 && c / 10 != 0) {
            j++;
            s[++count] = ',';
        }
        count++;
        c /= 10;
    }
    if(symbol == '-')   printf("-");
    for(int i = strlen(s) - 1; i >= 0 ; i--)  printf("%c", s[i]);
    }
    
    return 0;
}
