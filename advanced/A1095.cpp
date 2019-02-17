#include <bits/stdc++.h>
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e4 + 10;
////string转int
int my_to_int(string s)
{
    stringstream ss;
    int a;
    ss.clear();
    ss << s;
    ss >> a;
    return a;
}
////字符串数组转int
int my_to_int(char s[])
{
    int k;
    sscanf(s, "%d", &k);
    return k;
}

struct information {
    char id[8];
    int time;
    bool status;
} info[maxn], p[maxn];
bool cmp(information info1, information info2)
{
    int s = strcmp(info1.id, info2.id);
    if (s != 0)
        return s < 0;
    else if (info1.time != info2.time)
        return info1.time < info2.time;
    else
        return info1.id < info2.id;
}
bool cmptime(information info1, information info2)
{
    int s = strcmp(info1.id, info2.id);
    if (info1.time != info2.time)
        return info1.time < info2.time;
    else
        return s < 0;
}
#define LOCAL_XBB

int main()
{
#ifdef LOCAL_XBB
    freopen("_in", "r", stdin);
//  freopen("_out", "w", stdout);
#else
    IO;
#endif // LOCAL_XBB

    int n, k, valid = 0;
    map<string, int> park;
    int maxTime = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        char status[4];
        int hour, min, second;
        scanf("%s %d:%d:%d %s", info[i].id, &hour, &min, &second, status);
        info[i].status = (strcmp(status, "in") == 0 ? true : false);
        info[i].time = hour * 3600 + min * 60 + second;
    }
    sort(info, info + n, cmp);
    // valid-data
    for (int i = 0, j = 0; i < n - 1; i = j + 1) {
        j = i + 1;
        if (strcmp(info[i].id, info[j].id) == 0) {
            // true - false
            if (!(info[i].status & info[j].status) && (info[i].status & info[i].status)) {
                p[valid] = info[i];
                p[valid + 1] = info[j];
                valid = valid + 2;
                // updata park-time
                if (park.count(info[i].id) == 0) {
                    park[info[i].id] = 0;
                }
                park[info[i].id] += (info[j].time - info[i].time);
                maxTime = max(maxTime, park[info[i].id]);
                // true-true || alse-true
            } else if (info[i].status & info[j].status || info[j].status & info[j].status) {
                j = i;
            }
        } else {
            j = i;
        }
    }
    // count
    sort(p, p + valid, cmptime);
    for (int i = 0; i < k; i++) {
        int hour, min, second, time = 0, count = 0;
        scanf("%d:%d:%d", &hour, &min, &second);
        time = hour * 3600 + min * 60 + second;
        for (int j = 0; j < valid && p[j].time <= time; j++) {
            if (p[j].status == true)
                count++;
            else
                count--;
        }
        printf("%d\n", count);
    }
    // TLE
    // for (int i = 0; i < k; i++) {
    //     int hour, min, second, time = 0, count = 0;
    //     scanf("%d:%d:%d", &hour, &min, &second);
    //     time = hour * 3600 + min * 60 + second;
    //     for (int j = 0; j < valid; j = j + 2) {
    //         if (p[j].time <= time && p[j + 1].time > time)
    //             count++;
    //     }
    //     printf("%d\n", count);
    // }
    for (map<string, int>::iterator it = park.begin(); it != park.end(); it++) {
        if ((*it).second == maxTime) {
            printf("%s ", (*it).first.c_str());
        }
    }
    printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
    return 0;
}