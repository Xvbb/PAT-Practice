#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

int low_1=0 , high_1;
int Merge(ElementType A[], int N, int k){
    int low = low_1, high = N-1;
    int pivot = A[low];
    while(low < high){
        for(int i = high; pivot<A[high]&&low<high; i--) high--;
        A[low] = A[high];
        for(int i = low; pivot>A[low]&&low<high; i++) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    if(low == k) return A[low];
    if(low < k) {
        low_1=low+1;
        low=Merge(A, N, k);
    }
    if(low > k){
        low_1= 0;
        low=Merge(A,low, k);
    }
    return low;
}

ElementType Median( ElementType A[], int N ){ 
    int k = N/2;
    int mid = Merge(A,N,k);
    return A[mid];
}


