#include <iostream>
#include <list>

using namespace std;

void	print_list(list<char> lst, list<char>::iterator iter)
{
	for (iter = lst.begin(); iter != lst.end(); iter ++)
		cout << *iter;
	cout << endl;
}

int	main(void)
{
	int						num;
	string					str;

	cin >> num;
	for (int i = 0; i < num; i ++)
	{
		list<char>				lst;
		list<char>::iterator	iter;
		iter = lst.end();
		cin >> str;
		for (int j = 0; j < str.length(); j ++)
		{
			if (str[j] == '<' && iter != lst.begin())
				iter --;
			else if (str[j] == '>' && iter != lst.end())
				iter ++;
			else if (str[j] == '-' && iter != lst.begin())
				iter = lst.erase(-- iter);
			else if (str[j] != '<' && str[j] != '>' &&str[j] != '-')
				lst.insert(iter, str[j]);
		}
		print_list(lst, iter);
	}
	return (0);
}