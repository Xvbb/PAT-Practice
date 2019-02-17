#include <cstdio>

char compare(int b, int c, int j){
    return b >= c ? (b >= j ? 'B' : 'J') : (c >= j ? 'C' : 'J');
}
int main(int argc, char const *argv[])
{
    int n;
    char a, b, c;
    int count_win1 = 0, count_win2 = 0, count_lose1 = 0, count_lose2 = 0, 
        count_ac = 0, count_aj = 0, count_ab = 0,
        count_bc = 0, count_bj = 0, count_bb = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("\n%c %c", &a, &b);
        if(a == 'C') {
            if (b == 'J') {
                count_win1++;
                count_lose2++;
                count_ac++;
            } else if(b == 'B') {
                count_lose1++;
                count_win2++;
                count_bb++;
            }
        }
        if(a == 'B') {
            if(b == 'C') {
                count_win1++;
                count_lose2++;
                count_ab++;
            } else if(b == 'J') {
                count_lose1++;
                count_win2++;
                count_bj++;
            }
        } 
        if(a == 'J') {
            if(b == 'B') {
                count_win1++;
                count_lose2++;
                count_aj++;
            } else if(b == 'C') {
                count_lose1++;
                count_win2++;
                count_bc++;
            }
        }
    }
    printf("%d %d %d\n", count_win1, n - count_win1 - count_lose1, count_lose1);
    printf("%d %d %d\n", count_win2, n - count_win2 - count_lose2, count_lose2);
    printf("%c %c", compare(count_ab, count_ac, count_aj), compare(count_bb, count_bc, count_bj));
    return 0;
}
