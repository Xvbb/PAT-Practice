#include <bits/stdc++.h> 
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int price[25];
int my_to_int(string s)
{
    stringstream ss;
    int a;
    ss.clear();
    ss << s;
    ss >> a;
    return a;
}
int my_to_int(char s[])
{
    int k;
    sscanf(s, "%d", &k);
    return k;
}
typedef struct data {
    string name;
    int mon;
    int day;
    int hour;
    int min;
    string flag;
} d1, d2;

bool cmp(data d1, data d2)
{
    if (d1.name != d2.name)
        return d1.name < d2.name;
    else if (d1.mon != d2.mon)
        return d1.mon < d2.mon;
    else if (d1.day != d2.day)
        return d1.day < d2.day;
    else if (d1.hour != d2.hour)
        return d1.hour < d2.hour;
    else
        return d1.min < d2.min;
}
int calculate_price(int day, int hour, int min, int pre_day, int pre_hour, int pre_min)
{
    int total_price = 0;
    // 同日
    if (pre_day == day) {
        if (pre_hour == hour) {
            total_price += (min - pre_min) * price[hour];
        } else {
            total_price += (60 - pre_min) * price[pre_hour];
            for (int i = pre_hour + 1; i < hour; i++)
                total_price += price[i] * 60;
            total_price += min * price[hour];
        }

    } else {
        total_price += (60 - pre_min) * price[pre_hour];
        for (int i = pre_hour + 1; i < 24; i++)
            total_price += price[i] * 60;
        for (int i = 0; i < hour; i++)
            total_price += price[i] * 60;
        total_price += min * price[hour];
        for (int i = pre_day + 1; i < day; i++)
            for (int j = 0; j < 24; j++)
                total_price += price[j] * 60;
    }
    return total_price;
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

    for (int i = 0; i < 24; i++) {
        cin >> price[i];
    }
    int n, index = 0;
    data s[1001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> s[i].name;
        scanf("%d:%d:%d:%d", &s[i].mon, &s[i].day, &s[i].hour, &s[i].min);
        cin >> s[i].flag;
    }
    sort(s, s + n, cmp);
    string prename, preflag;
    int is_new = 0, new_flag = 1;
    int mon = 0, day = 0, hour = 0, min = 0;
    int ans = 0;
    double total_price = -1.00;
    for (int i = 0; i < n; i++) {
        if (s[i].flag == "off-line") {
            if (is_new == 0) {
                prename = s[i].name;
                continue;
            } else if (prename != s[i].name) {
                is_new = 0;
                new_flag = 1;
            } else {
                ans = (s[i].day - day) * 60 * 24 + (s[i].hour - hour) * 60 + (s[i].min - min);
                if (new_flag == 1) {
                    if (total_price != -1) {
                        printf("Total amount: $");
                        printf("%.2f\n", total_price);
                        ans = 0;
                        total_price = 0;
                        index = 0;
                    }
                    cout << s[i].name << " ";
                    printf("%.02d\n", s[i].mon);
                    total_price = 0;
                    new_flag = 0;
                    index++;
                }
                printf("%.02d:", day);
                printf("%.02d:", hour);
                printf("%.02d ", min);
                printf("%.02d:", s[i].day);
                printf("%.02d:", s[i].hour);
                printf("%.02d ", s[i].min);
                double temp_price = 1.00 * calculate_price(s[i].day, s[i].hour, s[i].min, day, hour, min) / 100;
                printf("%d $%.2f\n", ans, temp_price);
                total_price += temp_price;
                is_new = 0;
                continue;
            }
        }
        //
        else if (is_new == 1) {
            if (prename != s[i].name) {
                index = 0;
                is_new = 1;
            }
            prename = s[i].name;
            mon = s[i].mon;
            day = s[i].day;
            hour = s[i].hour;
            min = s[i].min;
            new_flag = 1;
        } else {
            if (index != 0 && prename != s[i].name) {
                // printf("Total amount: $");
                // printf("%.2f\n", total_price);
                ans = 0;
                //total_price = 0;
                index = 0;
                is_new = 0;
                new_flag = 1;
            }
            prename = s[i].name;
            preflag = s[i].flag;
            mon = s[i].mon;
            day = s[i].day;
            hour = s[i].hour;
            min = s[i].min;
            is_new = 1;
        }
    }
    printf("Total amount: $%.2f", total_price);
    return 0;
}