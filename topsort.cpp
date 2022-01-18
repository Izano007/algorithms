#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define All(a) a.begin(), a.end()
#define pii pair<int, int>
#define rep(i, x, n) for (int i = x; i < n; i++)
#define pb push_back
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
int indeg[MAX];
int mark[MAX];

void init()
{
	rep(i, 0, MAX)
	{
		adj[i].clear();
		indeg[i] = 0;
		mark[i] = -1;
	}
}

void solve_iterative()
{
	int n, m;
	cin >> n >> m;
	rep(i, 0, m)
	{
		int x, y;
		cin >> x >> y; // assuming input vertices 1-indexed
		x--;
		y--;
		adj[x].pb(y);
		indeg[y]++;
	}
	stack<int> st;
	rep(i, 0, n) if (indeg[i] == 0) st.push(i);
	vector<int> topsort;
	while (!st.empty())
	{
		int u = st.top();
		topsort.pb(u);
		st.pop();
		for (auto x : adj[u])
		{
			indeg[x]--;
			if (indeg[x] == 0)
				st.push(x);
		}
	}
	if ((int)topsort.size() < n)
		cout << "Cycle Exists\n";
	rep(i, 0, (int)topsort.size()) cout << topsort[i] << " ";
	cout << '\n';
}

bool dfs(int u, vector<int> &a)
{
	if (mark[u] != -1)
		return mark[u];
	mark[u] = 1;
	for (auto x : adj[u])
	{
		if (dfs(x, a))
			return true;
	}
	mark[u] = 0;
	a.pb(u);
	return false;
}

void solve_dfs()
{
	int n, m;
	cin >> n >> m;
	rep(i, 0, m)
	{
		int x, y;
		cin >> x >> y; // assuming input vertices 1-indexed
		x--;
		y--;
		adj[x].pb(y);
	}
	vector<int> tsort;
	rep(i, 0, n)
	{
		if (dfs(i, tsort))
		{
			cout << "Cycle Exists\n";
			return;
		}
	}
	reverse(begin(tsort), end(tsort));
	rep(i, 0, (int)tsort.size()) cout << tsort[i] << " ";
	cout << '\n';
}

int main()
{
	fastio;
	init();
	solve_iterative();
	// solve_dfs();
	return 0;
}
