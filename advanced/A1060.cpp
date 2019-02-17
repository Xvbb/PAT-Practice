#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int getSize(string a){
    return a.find(".") == string::npos ? -1 : a.find(".");
}

void initString(string &s){
    string a = s;
    int len = getSize(a);
    int pos = s.find(".");
    if(pos != string::npos) {
        s.erase(pos, 1);
        a.erase(pos, 1);
    }
    for(int i = 0; i < s.size() - 1; i++){
        if(s.substr(i, 1).compare("0") == 0)   a.erase(0, 1);
        else                        break;
    }
    s = a;
}
void check(string &a) {
    int flag = 1;
    for(int i = 0; i < a.size(); i++){
        if(a.substr(i, 1) != "0" && a.substr(i, 1) != ".") {
            flag = 0;
            break;
        }
    }
    if(flag)    a = "";
}
string getNew(string a, int n, int old){
    string A = "0.";
    int e = a.size();
    int flag = 1;
    if(a == "") {       
        for(int i = 0; i < n; i++)  A += "0";
        A += "*10^0";
        return A;
    }
    A += a.substr(0, n);
    if(a.size() < n) {
        for(int i = 0; i < n - a.size(); i++)   A += "0";
    }
    A += "*10^";
    if(old != 0) {
        e = a.size() - old;
    }
    A += to_string(e);
    return A;
}
int main(int argc, char const *argv[])
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    // 获取小数点之后的位数
    int len_1 = getSize(a) == -1 ? 0 : a.size() - getSize(a) - 1;
    int len_2 = getSize(b) == -1 ? 0 : b.size() - getSize(b) - 1;
    check(a);
    check(b);
    // 从左往右去除0和小数点
    initString(a);
    initString(b);
    string A = getNew(a, n, len_1);
    string B = getNew(b, n, len_2);
    if(A == B)  cout << "YES " + A;
    else        cout << "NO " + A + " " + B;
    return 0;
}
