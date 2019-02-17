#include <cstdio>

int main(int argc, char const *argv[])
{
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    long long c = a + b;
    int count = 0;
    int s[10000];
    if(c == 0)  printf("0");
    else {
        while(c) {
            s[count++] = c % d;
            c /= d;
        }
        for(int i = count - 1; i >= 0; i--) printf("%d", s[i]);
    }
    
    return 0;
}
