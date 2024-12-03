#include <bits/stdc++.h>
using namespace std;

void cong(const string &num1, const string &num2)
{
    string s1 = num1;
    string s2 = num2;

    // Cân bằng độ dài hai chuỗi bằng cách thêm '0' vào đầu chuỗi ngắn hơn
    while (s1.size() < s2.size())
    {
        s1 = '0' + s1;
    }
    while (s1.size() > s2.size())
    {
        s2 = '0' + s2;
    }

    int n = s1.size();
    string result = "";
    int carry = 0;

    // Cộng từ phải sang trái
    for (int i = n - 1; i >= 0; --i)
    {
        int ss = (s1[i] - '0') + (s2[i] - '0') + carry;
        result.push_back((ss % 10) + '0'); // Lấy phần đơn vị
        carry = ss / 10;                   // Lấy phần dư
    }

    // Nếu còn dư, thêm vào kết quả
    if (carry)
    {
        result.push_back(carry + '0');
    }

    // Đảo ngược chuỗi kết quả
    reverse(result.begin(), result.end());

    // In kết quả
    cout << result << endl;
}

int main()
{
    cong("757345", "236235435634");
    return 0;
}
