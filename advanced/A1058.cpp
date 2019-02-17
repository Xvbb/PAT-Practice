#include <cstdio>

int main(int argc, char const *argv[])
{
    int a, b, c, d, e, f, aa, bb, cc;
    scanf("%d.%d.%d", &a, &b, &c);
    scanf("%d.%d.%d", &d, &e, &f);
    cc = c + f;
    if(cc / 29) {
        cc %= 29;
        bb = b + e + 1;
        if(bb / 17) {
            aa = a + d + 1;
            bb %= 17;
        } else {
            aa = a + d;
        }
    } else {
        bb = b + e;
        if(bb / 17) {
            aa = a + d + 1;
            bb %= 17;
        } else {
            aa = a + d;
        }
    }
    printf("%d.%d.%d", aa, bb, cc);
    return 0;
}