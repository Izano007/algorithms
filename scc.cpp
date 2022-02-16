#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
bool mark1[MAX];
int mark2[MAX];
vector<int> adj1[MAX]; // out-edges
vector<int> adj2[MAX]; // in-edges
vector<int> tsort;

void dfs(int u) // topsort but without cycle detection
{
    if (mark1[u])
        return;
    mark1[u] = true;
    for (auto x : adj1[u])
        dfs(x);
    tsort.push_back(u);
}

void dfs2(int u, int p) // marking a strongly connected component with id(p)
{
    if (mark2[u])
        return;
    mark2[u] = p;
    for (auto x : adj2[u])
        dfs2(x, p);
}

int main()
{
    // for (int i = 0; i < MAX; i++)
    // {
    //     mark1[i] = false;
    //     mark2[i] = 0;
    //     adj1[i].clear();
    //     adj2[i].clear();
    // }
    // tsort.clear();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y; // assuming 1-indexed vertices
        x--;
        y--;
        adj1[x].push_back(y);
        adj2[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        dfs(i);
    reverse(tsort.begin(), tsort.end());
    for (int i = 0; i < n; i++)
    {
        dfs2(tsort[i], tsort[i] + 1); // giving id as the first node that means representative node(mark2[i])
    }
    return 0;
}