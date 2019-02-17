#include <cstdio>
#include <cstring>
char date[7][4] = {"MON", "TUE", "WED", "THE", "FRI", "SAT", "SUN"};

int main(int argc, char const *argv[])
{
    char s1[61], s2[61], s3[61], s4[61];
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);
    scanf("%s",s4);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    int len4 = strlen(s4);
    char day, hour;
    int min; 
    int find_day = 0, find_hour = 1,find_min = 0;
    int count = 0;
    int flag_1 = 1, flag_2 = 1;
    for(int i = 0; i < len1 && i < len2; i++) {
        // 找到第一个相同的大写字母后，找第二个.调整代码块顺序，避免第一次找到后跟着进行，重复操作并导致错误
        if(!find_hour && ((s1[i] >= 'A' && s1[i] <= 'N')|| (s1[i] >= '0' && s1[i] <= '9'))){
            if(s2[i] == s1[i]) {
                hour = s1[i];
                break;
            }
        }
        // 找第一个相同的大写字母
        if(!find_day && s1[i] >= 'A' && s1[i] <= 'G') {
            if(s2[i] == s1[i]) {
                day = s1[i];
                find_day = 1;
                find_hour = 0;
            }
        } 
    }
    for(int i = 0; i < len3 && i < len4; i++) {
        if((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')) {
            if(s4[i] == s3[i]) {
                min = i;
                find_min = 1;
                break;
            }
        }
    }
    printf("%s", date[day - 'A']);
    if(hour >= '0' && hour <= '9')  printf(" %02d:", hour - '0');
    else    printf(" %d:", hour - 'A' + 10);
    printf("%02d", min);
    return 0;
}
