#include <cstdio>
#include <cstring>


char chinese[5][5] = {
    "","Shi","Bai","Qian"
};
char num[10][5] = {
    "ling", "yi", "er", "san", "si", "wu",
    "liu", "qi", "ba", "jiu"
};
// 形参：字符串数组，起始位，长度
// 返回值：非0个数
int function(char s[],int flag_symbol, int len) {
    int flag_zero = 0, flag_more = 1, flag_first = 1;
    int count = 0;
    for(int i = flag_symbol; i < flag_symbol + len; i++) {
        // 处理数据中间为0的情况
        if(s[i] != '0') {
            count++;
            if(flag_zero) {
                if(flag_more && flag_first) {
                    printf("ling");
                    flag_more = 0;
                } else{
                    printf(" ling");
                }
                flag_zero = 0;
            }
            // 处理后续全0情况，无空格
            if(i == flag_symbol) {
                printf("%s", num[s[i] - '0']);
                printf(" ");
                flag_first = 0;
            } else {
                printf(" %s", num[s[i] - '0']);
            }
            if(i < flag_symbol + len - 1 && i != flag_symbol)   printf(" ");
            printf("%s", chinese[flag_symbol + len - i - 1]);
        } else {
            flag_zero = 1;
        }
    }
    return count;
}
// 亿和万位后判断是否补空格
int complete(char s[], int start, int len, int repeat) {
    for(int i = start; i < start + len; i++) {
        if(s[i] != '0' && i != repeat) {
            printf(" ");
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    char s[11];
    int len, flag_symbol = 0, flag_zero = 0;
    scanf("%s", s);
    if(s[0] == '0') {
        printf("ling");
        return 0;
    }
    if(s[0] == '-') {
        printf("Fu ");
        len = strlen(s) - 1;
        flag_symbol++;
    } else {
        len = strlen(s);
    }
    if(len == 1) {
        printf("%s", num[s[flag_symbol] - '0']);
        return 0;
    }
    if(len == 9) {
        printf("%s", num[s[flag_symbol] - '0']);
        printf(" Yi");
        // -800000008空格出错,最后一位参与判断2次
        int repeat = complete(s, flag_symbol + 1, 8, -1);
        if(function(s, flag_symbol + 1, 4)) printf(" Wan");
        complete(s, flag_symbol + 5, 4, repeat);
        function(s, flag_symbol + 5, 4);
    }
    if(len >= 5 && len <= 8) {
        int count = function(s, flag_symbol, len - 4);
        if(count == 1)  printf("Wan");
        else            printf(" Wan");
        complete(s, flag_symbol + len - 4, 4, -1);
        function(s, flag_symbol + len - 4, 4);
    }
    if(len <= 4 && len > 1) {
        function(s, flag_symbol, len);
    }
    
    
    
    return 0;
}