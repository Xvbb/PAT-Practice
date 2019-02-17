#include <cstdio>
typedef struct data{
    char id[20];
    int in;
    int out;
}data;

int main(int argc, char const *argv[])
{
    int n;
    int in_hour, in_min, in_sec, out_hour, out_min, out_sec;
    int flag = 1, min = 0, max = 0, min_no = 0, max_no = 0;
    scanf("%d", &n);
    data s[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %d:%d:%d", s[i].id, &in_hour, &in_min, &in_sec, &out_hour, &out_min, &out_sec);
        s[i].in = in_hour * 3600 + in_min *60 + in_sec;
        s[i].out = out_hour * 3600 + out_min *60 + out_sec;
        if(flag) {
            min = s[i].in;
            max = s[i].out;
            flag = 0;
        } else {
            if(s[i].in < min) {
                min = s[i].in;
                min_no = i;
            }
            if(s[i].out > max) {
                max = s[i].out;
                max_no = i;
            }
        }
    }
    printf("%s %s", s[min_no].id, s[max_no].id);
    return 0;
}