#include <iostream>

using namespace std;

void transform(string exp);
int operatorValue(char c);

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string exp;
        cin >> exp;
        transform(exp);
        cout << "\n";
    }
    return 0;
}

void transform(string exp)
{
    char transExp[exp.size()];
    int tTop = -1;

    char symbols[exp.size()];
    int sTop = -1;

    for (int i = 0; i < exp.size(); i++)
    {
        char ele = exp[i];
        if (ele == '(')
        {
            symbols[++sTop] = '(';
        }
        else if (ele == ')')
        {
            while (symbols[sTop] != '(')
                transExp[++tTop] = symbols[sTop--];
            sTop--;
        }
        else if (isalnum(ele))
        {
            transExp[++tTop] = ele;
        }
        else
        {
            if (operatorValue(ele) <= operatorValue(symbols[sTop]))
            {
                char temp = symbols[sTop];
                symbols[sTop] = ele;
                symbols[++sTop] = temp;
            }
            else
                symbols[++sTop] = ele;
        }
    }

    while (sTop != -1)
    {
        transExp[++tTop] = symbols[sTop--];
    }

    for (int i = 0; i <= tTop; i++)
    {
        cout << transExp[i];
    }
}

int operatorValue(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
