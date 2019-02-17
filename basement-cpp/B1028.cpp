#include <cstdio>

typedef struct data{
    char name[6];
    int year, month, day;
}data;

int compare(int a, int b, int c){
    if (a >= 1815 && a <= 2013) return 1;
    if (a == 1814 && b > 9) return 1;
    if (a == 1814 && b == 9 && c >= 6)  return 1;
    if (a == 2014 && b < 9) return 1;
    if (a == 2014 && b == 9 && c<= 6)   return 1; 
    return 0;
}
int main(int argc, char const *argv[])
{
    int n;
    int age;
    int min = 0, max = 0, oldest = 0, yougest = 0;
    int flag = 1, count = 0;
    scanf("%d", &n);
    data a[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", a[i].name, &a[i].year, &a[i].month, &a[i].day);
        if(compare(a[i].year, a[i].month, a[i].day)){
            count++;
            age = a[i].year * 10000 + a[i].month * 100 + a[i].day;
            if(flag) {
                max = i;
                min = i;
                oldest = age;
                yougest = age;
                flag = 0;
            }
            if(age > yougest) {
                yougest = age;
                min = i;
            }
            if(age < oldest) {
                oldest = age;
                max = i;
            }
        }    
    }
    if(count == 0) {
        printf("0");
    } else{
        printf("%d %s %s", count, a[max].name, a[min].name);
    }
    return 0;
}
