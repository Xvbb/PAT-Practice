#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    char a[255];
    int flag = 1;
    scanf("%s", a);
    int lenth = strlen(a);
    for (int i = 0, k = lenth -1; i < lenth / 2 && i < k; i++, k--){
        if(a[i] == a[k]) continue;
        flag = 0;
        printf("NO\n");
        break;
    }
    if(flag)  printf("YES\n");

    return 0;
}
