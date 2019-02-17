#include <cstdio>

int main(int argc, char const *argv[])
{
    int pa, pb, pc, aa, ab, ac;
    scanf("%d.%d.%d %d.%d.%d", &pa, &pb, &pc, &aa, &ab, &ac);
    int p = pc + 29 * pb + 17 * 29 * pa;
    int s = ac + 29 * ab + 17 * 29 * aa;
    
    if(s - p < 0) {
        printf("-");
        int temp = s;
        s = p;
        p = temp;
    }
    int a = (s - p) / (29 * 17);
    int c = (s - p) % 29;
    int b = (s - p) % (29 * 17) / 29; 

    
    printf("%d.%d.%d", a, b, c);
    return 0;
}
