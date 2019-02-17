#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
    char n[1001];
    int a[11][2] = {0};
    scanf("%s", n);
    int len = strlen(n);
    if(strcmp(n, "0") == 0)  printf("0:1");
    else { 
        for(int i = 0; i < len; i++) {
            a[n[i] - '0'][0]++;
            a[n[i] - '0'][1] = 1;
        }
        for(int i = 0; i < 11; i++) {
            if(a[i][1] == 1) {
                printf("%d:%d", i, a[i][0]);
                if(i != 10) printf("\n");
            }
        }
    }
    return 0;
}
