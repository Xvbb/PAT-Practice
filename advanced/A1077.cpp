#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d\n", &n);
    char a[110][260];
    char c;
    int flag = 1, count = 0;
    for(int i = 0; i < n; i++) {
        fgets(a[i], 260, stdin);
    }

    int len_0 = strlen(a[0]) - 1;
    for(int k = len_0 - 1; k >= 0; k--) {
        c = a[0][k];
        if(c == ' ') {
            break;
        }
        for(int i = 1; i < n; i++) {
            int len = strlen(a[i]) - 1;
            // 当前比较位到尾字符的距离，小于a[0]
            int m = len_0 - 1 - k;
            if(m >= len) {
                flag = 0;
                break;
            }
            else{
                if(a[i][len - 1 - m] == c) {
                    continue;
                } else {
                    flag = 0;
                    break;
                }
            }   
        }
        if(flag) {
            count++;
        } else {
            break;
        }
    }
    if(count == 0)  printf("nai");
    else {
        for(int i = len_0 - count; i < len_0; i++) {
            if(a[0][i] != ' ')  printf("%c", a[0][i]);
        }
    }
    return 0;
}