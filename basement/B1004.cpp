#include <cstdio>

typedef struct student{
    char name[11];
    char num[11];
    int grade;
}stu;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    stu s[n];
    int max_grade = 0, min_grade = 0, max_no = 0, min_no = 0;
    int flag = 1;
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", s[i].name, s[i].num, &s[i].grade);
        if(flag) {
            min_grade = s[i].grade;
            flag = 0;
        }
        if(s[i].grade > max_grade)  {
            max_no = i;
            max_grade = s[i].grade;
        } else if(s[i].grade < min_grade) {
            min_no = i;
            min_grade = s[i].grade;
        }
    }
    printf("%s %s\n", s[max_no].name, s[max_no].num);
    printf("%s %s\n", s[min_no].name, s[min_no].num);
    return 0;
}
