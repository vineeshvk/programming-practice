//original solution but tle
// 11(9091a + 910b + 100c) palindrome formula
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return rev == str;
}

bool isAllNine(string str)
{
    for (char s : str)
        if (s != '9')
            return false;
    return true;
}

string add(string str)
{
    string newNum = "";
    int carry = 0;
    int i1 = str.size() - 1, i2 = 0;
    while (i1 >= 0)
    {
        int digit;
        int n1 = str.at(i1) - '0';

        if (i2 < 0)
            digit = n1 + carry;
        else
        {
            digit = n1 + 1 + carry;
        }

        newNum = to_string(digit % 10) + newNum;
        carry = digit / 10;

        i1--;
        i2--;
    }
    if (carry != 0)
        newNum = to_string(carry) + newNum;

    return newNum;
}

string addNum(string str)
{
    long long newDigits = stoll(str) + 1;
    return to_string(newDigits);
}

string revJoin(string str, bool includeLast = false, bool isAllNine = false)
{
    int ilast = includeLast ? str.size() : str.size() - 1;
    string rev = str.substr(0, ilast - (isAllNine ? 1 : 0));
    reverse(rev.begin(), rev.end());
    return str + rev;
}

bool changeMid(string str, int mid, bool even)
{
    int i = mid - (even ? 2 : 1), j = mid + 1;
    bool cm = false;

    while (i >= 0 && j < str.size() && !cm)
    {
        if (str.at(i) < str.at(j))
            cm = true;
        else if (str.at(i) > str.at(j))
            break;

        i--;
        j++;
    }

    return cm;
}

string newNextPali(string str)
{
    int mid = str.size() / 2;
    int even = str.size() % 2 == 0;

    if (str == "9")
        return "11";

    if (isPalindrome(str))
    {
        string half = str.substr(0, mid + (even ? 0 : 1));
        half = addNum(half);
        return revJoin(half, even, isAllNine(str));
    }

    char first = str.at(mid - 1), second = str.at(mid);
    if (first != second && even)
    {
        string half = str.substr(0, mid);

        if (first < second)
            half = addNum(half);

        return revJoin(half, even);
    }
    else
    {
        bool cm = changeMid(str, mid, even);
        string half = str.substr(0, mid + (even ? 0 : 1));

        if (cm)
            half = addNum(half);

        return revJoin(half, even);
    }
}

string nextPalindromeBrute(int n)
{
    while (true)
    {
        n++;
        string strN = to_string(n);
        string revN = strN;
        reverse(revN.begin(), revN.end());

        if (revN == strN)
            return revN;
    }
}

int main()
{
    int t = 1000000;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        // long long s;
        // cin >> s;
        string str = to_string(i);
        if (newNextPali(str) != nextPalindromeBrute(i))
        {

            cout << "\n"
                 << i << " original  => "
                 << nextPalindromeBrute(i)
                 << "value => "
                 << newNextPali(str) << "\n";
            return 0;
        }
        cout << i << " ";
    }
}
