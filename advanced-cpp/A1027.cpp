#include <cstdio>

void change(int a){
    int count = 0;
    int b[2] = {0,0};
    if(a == 0) printf("00");
    else {
        while(a) {
            b[count++] = a % 13;
            a /= 13;
        }
        if(count == 1) {
            printf("0");
        } 
        while(count > 0) {
            if(b[count - 1] == 10)  printf("A");
            else if(b[count - 1] == 11)  printf("B");
            else if(b[count - 1] == 12)  printf("C");
            else    printf("%d", b[count - 1]);
            count--;
        }
    }
}
int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("#");
    change(a);
    change(b);
    change(c);
    return 0;
}
