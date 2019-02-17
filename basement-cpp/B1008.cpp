#include <cstdio>

void reveal(int a[], int low, int high){
    for(int i = low, k = high; i < k; i++, k--) {
       int temp = a[i];
       a[i] = a[k];
       a[k] = temp;
    }
}
int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    int a[N];
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    if(M != 0 || N != 0 || M % N != 0){
        reveal(a, 0, N-1);
        reveal(a, 0, M%N-1);
        reveal(a, M%N, N-1);
    }
    for(int i = 0; i < N; i++) {
        printf("%d", a[i]);
        if(i < N-1) printf(" ");
    }
    return 0;
}
