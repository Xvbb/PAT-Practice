#include <cstdio>

int main(int argc, char const *argv[])
{
    int a, b;
    int ans;
    int hour, minute, second;
    scanf("%d %d", &a, &b);
    ans = (b - a) / 100 + ((b - a) % 100 < 50 ? 0 : 1);
    second = ans % 60;
    minute = ans % 3600 / 60;
    hour = ans / 3600;
    printf("%02d:%02d:%02d\n", hour, minute, second);
    return 0;
}
