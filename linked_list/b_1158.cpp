#include <iostream>
#include <list>

using namespace std;

int	main(void)
{
	list<int>			lst;
	list<int>::iterator iter;
	int					n, k;
	int					tmp;

	cin >> n >> k;
	tmp = 0;
	for (int i = k + 1; i <= n; i ++)
		lst.push_back(i);
	for (int i = 1; i < k; i ++)
		lst.push_back(i);
	iter = lst.begin();
	cout << "<" << k << ", ";
	for (int i = 0; i < 25; i ++)
	{
		if (iter == lst.end())
		{
			cout << "lst ";
			iter ++;
		}
		if (iter == lst.begin())
		{
			cout << "fst ";
			++ iter;
			lst.erase(++ iter);
		}
		cout << *iter << ", ";
		iter ++;
	}
	// while(!lst.empty())
	// {
	// 	tmp ++;
	// 	if (iter == lst.end())
	// 		iter = lst.begin();
	// 	else
	// 		iter ++;
	// 	if (tmp == k)
	// 	{
	// 		tmp = 0;
	// 		cout << ", " << *iter;
	// 		lst.erase(iter);
	// 	}
	// }
	cout << ">";
}