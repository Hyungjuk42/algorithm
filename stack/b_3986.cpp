#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack <char>	s;

int main()
{
	int 	n;
	int		res;
	string	str;

	cin >> n;
	res = 0;
	for (int i = 0; i < n; i ++)
	{
		cin >> str;
		s = stack <char> (); 
		for (int j = 0 ; j < str.length(); j ++)
		{
			if (!s.empty() && s.top() == str[j])
				s.pop();
			else
				s.push(str[j]);
		}
		if (s.empty())
			res ++;
	}
	cout << res << '\n';
}