#include <cstdio>
#include <cstring>

typedef struct data{
    char id[15];
    char pwd[15];
    //int isModify = 0;
}data;

int main(int argc, char const *argv[])
{
    int n;
    int count = 0, flag = 0;
    scanf("%d", &n);
    int a[n];
    data in[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %s", in[i].id, in[i].pwd);
        flag = 0;
        for(int j = 0; j < strlen(in[i].pwd); j++) {
            if(in[i].pwd[j] == '1') {
                in[i].pwd[j] = '@';
                flag = 1;
            }    
            if(in[i].pwd[j] == '0') {
                in[i].pwd[j] = '%';
                flag = 1;
            }    
            if(in[i].pwd[j] == 'l') {
                in[i].pwd[j] = 'L';
                flag = 1;
            }    
            if(in[i].pwd[j] == 'O') {
                in[i].pwd[j] = 'o';
                flag = 1;
            }
        }
        if(flag) {
            a[count] = i;
            count = count + 1;
        }
    }
    if(n != 1 && count == 0)    printf("There are %d accounts and no account is modified", n);
    else if(n == 1 && count == 0)   printf("There is 1 account and no account is modified");
    else {
        printf("%d\n", count);
        for(int i = 0; i < count; i++) {
            printf("%s %s", in[a[i]].id, in[a[i]].pwd);
            if(i < count - 1)   printf("\n");
        }
        
    }
    return 0;
}