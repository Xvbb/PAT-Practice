#include <cstdio>
#include <cstring>
char out[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','k'};
int main(int argc, char const *argv[])
{
    char a[110], b[110];
    scanf("%s %s", a, b);
    int len_1 = strlen(a);
    int len_2 = strlen(b);
    
    //int k = len_2;
    //int j = len_1;
    // int m = 0;
    // while(k >= 0 && j >= 0) {  
    //     if (m % 2 == 0) {
    //         b[k] = '0' + ((a[j] - '0') + (b[k] - '0')) % 13;
    //     } else {
    //         b[k] = ((b[k] - '0')-(a[j] - '0'))< 0 ? 10 + (b[k] - a[j]) + '0': b[k] - a[j] + '0';
    //     }
    //     k--;
    //     j--;
    //     m++;
    // }
    // if(len_1 > len_2) {
    //     for(int i = 0; i < len_1 - len_2; i++)  printf("0");
    // }
    // for(int i = 0; i < len_2; i++) {
    //     printf("%c", out[b[i] - '0']);
    // }
    return 0;
}
