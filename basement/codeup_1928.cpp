// 两行输入，求日期差值。
#include <cstdio>

int date[13][2]={
    {0,0},
    {31,31},{28,29},{31,31},{30,30},
    {31,31},{30,30},{31,31},{31,31},
    {30,30},{31,31},{30,30},{31,31}
};
// 判断是否闰年
int isLeap(int date){
    return (date % 4) == 0 ? 1 : 0;
}
// 较小年份在前
void compare(int &data1, int &data2){
    if(data2<data1){
        int temp = data1;
        data1 = data2;
        data2 = temp;
    }
}

int main(int argc, char const *argv[])
{
    int count_day=0,count_month=0,count_year=0;
    int date_1,date_2;
    int month_1,month_2,day_1,day_2, year_1, year_2;
    scanf("%d", &date_1);
    scanf("%d", &date_2);
    //date_1 = 20130101;
    //date_2 = 20131231;
    compare(date_1, date_2);
    year_1 = date_1 / 10000;
    month_1 = date_1 % 10000 / 100;
    day_1 = date_1 % 10000 % 100;
    year_2 = date_2 / 10000;
    month_2 = date_2 % 10000 / 100;
    day_2 = date_2 % 10000 % 100;
    // 判断童年
    if(year_1 < year_2){
        for(int i = year_1+1; i < year_2; i++){
            if(isLeap(i))  count_day += 366;
            else  count_day += 365;
        }
        int flag_1 = isLeap(year_1);
        int flag_2 = isLeap(year_2);
        // 首日期当年剩余天数
        count_day += date[month_1][flag_1] - day_1;
        while(month_1 < 12){
            month_1++;
            count_day += date[month_1][flag_1];
        }
        count_day += day_2;
        while(month_2 > 0){
            month_2--;
            count_day += date[month_2][flag_2];
        }
    } else{
        int flag = isLeap(year_1);
        if(month_1 != month_2){
            count_day += date[month_1][flag] - day_1+1;
            count_day += day_2;
            while(month_2 > month_1+1){
                month_2--;
                count_day += date[month_2][flag];
            }
        } else {
            if(day_1 == day_2) count_day = 2;
            else count_day += (day_2 - day_1 + 1);
        }
        
    }
    
    printf("\n%d\n", count_day);
    
    return 0;
}