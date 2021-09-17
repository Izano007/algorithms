#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 1;

int edges, nodes, id[MAX];
pair<ll, pair<int, int>> p[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
        id[i] = i;
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int pp = root(x);
    int qq = root(y);
    id[pp] = id[qq];
}

int kruskal()
{
    int x, y;
    ll cost, minCost = 0;
    for (int i = 0; i < edges; i++)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if (root(x) != root(y))
        {
            minCost += cost;
            union1(x, y);
        }
    }
    return minCost;
}

int main()
{
    int x, y;
    ll ans, wt;
    init();
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        cin >> x >> y >> wt;
        p[i] = make_pair(wt, make_pair(x, y));
    }
    sort(p, p + edges);
    ans = kruskal();
    cout << ans << endl;
    return 0;
}
