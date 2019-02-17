#include <cstdio>
//char Z[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char M[12] = {'1', '0', 'X', '9', '8' ,'7', '6', '5', '4', '3', '2'};
int data[18] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int main(int argc, char const *argv[])
{
    int n;
    int flag = 1;
    char s[19];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        int flag_2 = 0;
        int ans = 0;
        for(int i = 0; i <= 16; i++) {
            //printf("%d += %d * %d", ans, data[i], s[i] - '0');
            if(!(s[i] >= '0' && s[i] <= '9'))  {
                flag = 0;
                flag_2 = 1;
                break;
            }
            ans += data[i] * (s[i] - '0');
            //printf("=%d\n", ans);
        }

        //printf("\nans = %d\n", ans);
        if (flag_2 == 1 || ( flag_2 == 0 && s[17] != M[ans % 11])) {
            printf("%s\n", s);
            flag = 0;
        }
    }
    if(flag)    printf("All passed");   
    return 0;
}
