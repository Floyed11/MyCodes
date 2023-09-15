// 高精度加法
// Created by hengxin on 17-10-3.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b) {
    string res = "";
    int carry = 0;
    for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
        int temp = carry;
        if (i >= 0)
            temp += a[i] - '0';
        if (j >= 0)
            temp += b[j] - '0';

        res += to_string(temp % 10);
        carry = temp / 10;
    }

    if (carry != 0)
        res += to_string(carry);

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    int c=a % b;
    cout<<(c)<<endl;
    //cout << add(a, b) << endl;
    return 0;
}

// Path: test.cpp
// 高精度加法
// Created by hengxin on 17-10-3.
