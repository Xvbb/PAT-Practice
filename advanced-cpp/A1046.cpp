#include <cstdio>

int main(int argc, char const *argv[])
{
    int n,m;
    int dis_1, dis_2, sum = 0, acc = 0;
    scanf("%d", &n);
    int a[n];
    long dis[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
        dis[i] = sum;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &dis_1, &dis_2);
        if(dis_1 == dis_2) {
            printf("0");
        } else {
            if (dis_1 > dis_2) {
                int temp = dis_1;
                dis_1 = dis_2;
                dis_2 = temp;
            }
            if(dis_1 == 1)  acc = dis[dis_2 - 2];
            else            acc = dis[dis_2 - 2] - dis[dis_1 - 2];
            printf("%d", acc > (sum - acc) ? sum - acc : acc);
        }
        if(i < m - 1) printf("\n"); 
    }
    return 0;
}
