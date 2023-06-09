#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <char>    s;
string          str;
int             r;
int             ord;

int recur(int len)
{
    int res;
    int tmp;

    res = 0;
    while (ord < len)
    {
        if (str[ord] == '(' || str[ord] == '[')
        {
            s.push(str[ord]);
            ord ++;
            tmp = recur(len);
            ord ++;
            res += tmp;
        }
        else if (!s.empty() && str[ord] == ')' && s.top() == '(')
		{
			s.pop();
            if (res == 0)
                res ++;
			return (res * 2);
		}
        else if (!s.empty() && str[ord] == ']' && s.top() == '[')
		{
			s.pop();
            if (res == 0)
                res ++;
			return (res * 3);
		}
		else
		{
			r = 0;
			break ;
		}
    }
	if (ord == len && !s.empty())
		r = 0;
    return (res);
}

int main()
{
    int     tmpsum;
    int     tmpmul;
    int     res;

    cin >> str;
    r = 1;
    res = recur(str.length());
    if (r == 1)
        cout << res;
    else
        cout << "0";
}