#include <cstdio>

int main(int argc, char const *argv[])
{
    int n;
    int no, grade;
    int max_no = 0, max_grade = 0;
    int a[10001] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &no, &grade);
        a[no] += grade;
        if (a[no] > max_grade)  {
            max_grade = a[no];
            max_no = no;
        }
    }
    printf("%d %d", max_no, max_grade);
    return 0;
}
