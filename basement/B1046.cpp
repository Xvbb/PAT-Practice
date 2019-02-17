#include <cstdio>

int main(int argc, char const *argv[])
{
    int T;
    int a,b,c,d;
    int count_1 = 0, count_2 = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &a, &b, &c ,&d);
        if(a + c == b && b == d)  continue;
        else if (a + c == b) count_2++;
        else if (a + c == d) count_1++;
    }
    printf("%d %d", count_1, count_2);
    return 0;
}
