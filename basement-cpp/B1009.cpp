#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    // PTA单点测试版本
    /* char a[90][90];
    int num  = 0;
    while(scanf("%s", a[num]) != EOF) {
        num++;
    }
    for(int i = num - 1; i > 0; i--){
        printf("%s", a[i]);
        if(i == 0) printf(" ");
    } */

    // 常规console输入版本
    char a[90][90];
    char str[90];
    fgets(str, 100, stdin);
    int len = strlen(str), row = 0, h = 0;
    for(int i = 0; i < len; i++){
        if(str[i] != ' ') {
            if(str[i] != '\n') {
                a[row][h++] = str[i];
            } else {
                a[row][h++] = '\0';
            } 
        } else {
            a[row][h] = '\0';
            row++;
            h = 0;
        }
    }
    
    for(int i = row; i >= 0; i--){
        printf("%s", a[i]);
        if(i > 0)  printf(" ");
    }
    return 0;
}
