#include <iostream>
#include <vector>

using namespace std;
using Graph = vector< vector<int> >;
int 	n, m;
int		res;
bool	*chk;

void dfs(Graph &g, int n)
{
	for (int i : g[n])
	{
		if (chk[i] == 0)
		{
			chk[i] = 1;
			dfs(g, i);
		}
	}
}

int main()
{
	int u, v;

	cin >> n >> m;
	Graph	g(n + 1);
	chk = new bool[n + 1]{};
	for (int i = 0; i < m; i ++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++)
	{
		if (chk[i] == 0)
		{
			res ++;
			chk[i] = 1;
			dfs(g, i);
		}
	}
	cout << res;
}