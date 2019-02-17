#include <cstdio>

int main(int argc, char const *argv[])
{
    int n;
    int count = 0;
    scanf("%d",&n);
    //n = 3;
    while(n!=1){
        count++;
        if(n%2==0){
            n/=2;
        } else{
            n = 3*n/2;
        }
    }
    printf("%d",count);
    return 0;
}
