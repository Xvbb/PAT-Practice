#include <cstdio>

typedef struct student{
    char name[11];
    char sex;
    char id[11];
    int grade;
}student;

int main(int argc, char const *argv[])
{
    int n;
    int min_grade = 0, max_grade = 0, min = 0, max = 0;
    int flag_1 = 1, flag_2 = 1;
    int count_1 = 0, count_2 = 0;
    scanf("%d", &n);
    student s[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %c %s %d", s[i].name, &s[i].sex, s[i].id, &s[i].grade);
        if(s[i].sex == 'M'){
            count_1++;
            if(flag_1) {
                min = i;
                min_grade = s[i].grade;
                flag_1 = 0;
            } else if(s[i].grade < min_grade){
                min = i;
                min_grade = s[i].grade;
            }
        } else{
            count_2++;
            if(flag_2) {
                max = i;
                max_grade = s[i].grade;
                flag_2 = 0;
            } else if(s[i].grade > max_grade){
                max = i;
                max_grade = s[i].grade;
            }
        }
    }
    if(count_2) printf("%s %s\n", s[max].name, s[max].id);
    else        printf("Absent\n");
    if(count_1) printf("%s %s\n", s[min].name, s[min].id);
    else        printf("Absent\n");
    if(count_1 && count_2)  printf("%d", s[max].grade - s[min].grade);
    else                    printf("NA");
    return 0;
}
