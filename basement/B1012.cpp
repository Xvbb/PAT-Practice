#include <cstdio>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[n];
    int A1 = 0,A2 = 0, A3 = 0, A4 =0,  A5 = 0;
    int count_3 = 0, count_4 = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i]%10 == 0)    {
            A1 += a[i];
        }
        if(a[i] % 5 == 1)   {
            flag = 1;
            if(++count_3 %2)  A2 += a[i];
            else          A2 -= a[i];
        }
        if(a[i] % 5 == 2)   {
            A3++;
        }
        if(a[i] % 5 == 3)   {
            A4 += a[i];
            count_4++;
        }
        if(a[i] % 5 == 4) {
            if(a[i] > A5)  A5 = a[i];
        }
    }
    double average = A4 * 1.0 / count_4;
    if (A1) printf("%d ", A1);
    else    printf("N ");
    if (flag) printf("%d ", A2);
    else    printf("N ");
    if (A3) printf("%d ", A3);
    else    printf("N ");
    if (A4) printf("%.1f ", average);
    else    printf("N ");
    if (A5) printf("%d", A5);
    else    printf("N");

    return 0;
}
