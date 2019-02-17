#include <cstdio>

int main(int argc, char const *argv[])
{
    int a,b,c,d;
    int data_1 = 0, data_2  = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while(a){
        data_1 = a % 10 == b ? data_1 * 10 + b : data_1;
        a /= 10;
    }
    while(c){
        data_2 =  c % 10 == d ? data_2 * 10 + d : data_2;
        c /= 10;
    }
    printf("%d", data_1 + data_2);
    return 0;
}
