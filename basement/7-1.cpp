#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a;
    int b,c;
    cin >> a;
    b = (int)(a/0.3048);
    c = (int)((a-b)*12);
    cout << b << " " << c;
    return 0;
}