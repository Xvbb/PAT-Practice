#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
    int n,school,grade, max_school = 0, max_grade =0;
    scanf("%d",&n);
    int A[n];
    memset(A, 0, sizeof(A));
    while(n--){
        scanf("%d %d", &school, &grade);
        A[school] += grade; 
        if(A[school] > max_grade) {
            max_grade = A[school];
            max_school = school;
        }
    }
    printf("%d %d", max_school, max_grade);
    return 0;
}
