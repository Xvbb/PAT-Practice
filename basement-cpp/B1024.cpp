#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    // char symbol_1, symbol_2;
    // char s[10010], copy[10010];
    // scanf("%c", &symbol_1);
    // scanf("%s", s);
    // int len = strlen(s);
    // int pos = 0;
    // int i = 0;
    // for(; i < len; i++) {
    //     if(s[i] == 'E') {
    //         symbol_2 = s[i + 1];
    //         for (int j = 0; j < len - i - 1; j++) {
    //             copy[j] = s[j + i + 2];
    //         }
    //         break;
    //     }
    // }

    // int n;
    // int count = 0;
    // sscanf(copy, "%d", &n);
    // if(symbol_1 == '-') printf("-");
    // if(n == 0)  {
    //     for(int j = 0; j < i; j++)  printf("%c", s[j]);
    //     printf("\n");
    // } else{
    //     if(symbol_2 == '+') {
    //         printf("%c", s[0]);
    //         if(n < i - 3) {
    //             int k = 2;
    //             while(n--) {
    //                 printf("%c", s[k++]);
    //             }
    //             printf(".");
    //             for (int j = k; j < i; j++) {
    //                 printf("%c", s[j]);
    //             }
    //         } else {
                
    //             for (int j = 2; j < i; j++) printf("%c", s[j]);
    //             for (int j = i - 1; j <= n; j++) {
    //                 printf("0");
    //                 count++;
    //             }
    //             printf("\n输出了%d个0\n", count);
    //         }    
    //     } else {
    //         printf("0.");
    //         for(int j = 0; j < n - 1; j++)    {
    //             printf("0");
    //             count++;
    //         }
    //         printf("%c", s[0]);
    //         for(int j = 2; j < i; j++)  printf("%c", s[j]);
    //         printf("\n输出了%d个0\n", count);
    //     }
    // }
    
    char s[10010], s2[5];
    int e = 0;
    char c,d;
    int k = 0, m = 0;
    scanf("%c", &c);
    scanf("%s", s);
    int len = strlen(s);
    while(s[k++] != 'E');
    d = s[k];
    for(int i = k + 1; i < len; i++) {
        s2[m] = s[i];
        m++;
    }
    sscanf(s2, "%d", &e);
    if(c == '-')    printf("-");
    if(e == 0) printf("%s", s);
    else {
        if(d == '-') {
            printf("0.");
            for (int i = 0; i < e - 1; i++)    printf("0");
            printf("%c", s[0]);
            for(int i = 2; i < k - 1; i++)    printf("%c", s[i]);
        } else {
            if(k - 3 > e) {
                printf("%c", s[0]);
                for(int i = 2; i < 2 + e; i++) printf("%c", s[i]);
                printf(".");
                for(int i = 2 + e; i < k - 1; i++)    printf("%c", s[i]);
            } else {
                printf("%c", s[0]);
                for(int i = 2; i < k - 1; i++)  printf("%c", s[i]);
                while(k - 3 < e) {
                    printf("0");
                    k++;
                }
            }
        }
    }
    return 0;
}