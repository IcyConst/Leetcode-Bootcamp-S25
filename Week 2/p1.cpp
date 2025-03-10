#include<iostream>

using namespace std;

// 8. String to Integer (atoi)
// It seems simple, but we need to consider many situations...

int myAtoi(string s) {
    long long cur = 0;
    int ans = 0;
    int mul = 1;
    bool num = false;
    bool pos = false;
    bool nonzero = false;
    int numlength = 0;
    for(int i = 0;i < s.length(); i++){
        if(s[i] == ' ' && !num && !pos) continue;
        if((num || pos) && (s[i] < '0' || s[i] > '9')) break;
        if((s[i] < '0' || s[i] > '9') && s[i] != '+' && s[i] != '-') break;
        if(s[i] == '-') {
            mul = -1;
            pos = true;
        }
        if(s[i] == '+') pos = true;
        if(s[i] >= '0' && s[i] <= '9') {
            num = true;
            cur = cur * 10 + s[i] - '0';
            if(s[i] > '0') nonzero = true;
            if(nonzero) numlength++;
        }
        if(numlength >= 12) break;
    }
    if(mul == 1 && (cur >= 2147483647)) ans = 2147483647;
    else if(mul == -1 && (cur >= 2147483648)) ans = -2147483648;
    else ans = int(cur) * mul;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int a = myAtoi(s);
    cout << a << endl;
    return 0;
}