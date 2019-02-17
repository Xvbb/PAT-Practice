#include <cstdio>

int main(int argc, char const *argv[])
{
    int n,i=0;
    long a,b,c;
    scanf("%d",&n);
    int A[n];
    while(i<n){
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a + b > c){
            A[i++] = 1;
        }else {
            A[i++] = 0;
        }
    }
    for(int k = 0; k < n; k++){
        printf("Case #%d: ", k+1);
        if(A[k]){
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}
