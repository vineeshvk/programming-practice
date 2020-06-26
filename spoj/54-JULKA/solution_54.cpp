#include <iostream>
#include <string>

using namespace std;
string removeTrailingZeros(string num);

string division(string num, int div)
{
    string newNum = "";
    string carry = "0";
    for (int i = 0; i < num.size(); i++)
    {
        string digit = carry + num.at(i);

        int temp = stoi(digit);
        if (temp == 0)
        {
            newNum += "0";
        }
        else if (temp < div)
        {
            if (i == num.size() - 1)
            {
                int digit = (int)(temp / div);
                newNum += to_string(digit);
            }
            else
                newNum += "0";
            carry = to_string(temp);
        }
        else if (temp % div == 0)
        {
            string val = to_string(temp / div);
            newNum += val;
            carry = "0";
        }
        else
        {
            string val = to_string((int)(temp / div));
            newNum += val;
            carry = to_string(temp % div);
        }
    }
    return removeTrailingZeros(newNum);
}

string removeTrailingZeros(string num)
{
    int i;
    for (i = 0; i < num.size(); i++)
    {
        if (num.at(i) != '0')
            break;
    }
    if (i < 0)
        return num;

    return i == num.size() ? "0" : num.substr(i);
}

//considering num1 >= num2
string sub(string num1, string num2)
{

    string newNum = "";
    int carry = 0;
    int i1 = num1.size() - 1, i2 = num2.size() - 1;

    while (i1 >= 0)
    {
        int digit;
        int n1 = num1.at(i1) - '0';

        if (i2 < 0)
        {
            if (carry != 0)
            {
                if (n1 < carry)
                    n1 = stoi("1" + to_string(n1));
                else
                    carry = 0;
                n1--;
            }
            newNum = to_string(n1) + newNum;
        }
        else
        {
            int n2 = num2.at(i2) - '0';

            if (carry != 0)
            {
                if (n1 < carry)
                {
                    n1 = stoi("1" + to_string(n1));
                    n1 -= carry;
                }
                else
                {
                    n1 -= carry;
                    carry = 0;
                }
            }

            if (n1 < n2)
            {
                n1 = stoi("1" + to_string(n1));
                carry = 1;
            }

            newNum = to_string(n1 - n2) + newNum;
        }

        i1--;
        i2--;
    }
    return removeTrailingZeros(newNum);
}

//considering num1 >= num2
string add(string num1, string num2)
{
    string newNum = "";
    int carry = 0;
    int i1 = num1.size() - 1, i2 = num2.size() - 1;
    while (i1 >= 0)
    {
        int digit;
        int n1 = num1.at(i1) - '0';

        if (i2 < 0)
            digit = n1 + carry;
        else
        {
            int n2 = num2.at(i2) - '0';
            digit = n1 + n2 + carry;
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
void appleCount(string total, string more)
{
    string half = division(total, 2);
    string diff = division(more, 2);
    diff = diff == "" ? "0" : diff;

    int totalDig = total.at(total.size() - 1) - '0';
    int isOdd = totalDig % 2 != 0;

    if (total == more)
    {
        cout << total << "\n"
             << 0 << "\n";
        return;
    }

    cout << add(half, isOdd ? add(diff, "1") : diff) << "\n"
         << sub(half, diff) << "\n";
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        string total;
        string more;
        cin >> total >> more;
        appleCount(total, more);
    }
    return 0;
}

