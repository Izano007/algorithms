#include <bits/stdc++.h>
using namespace std;

int minPath(int n, vector<vector<int>> &edges, int src, int des)
{
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    vector<int> dist(n, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        if (dist[x[1]] != INT_MAX)
            continue;
        dist[x[1]] = x[0];
        for (auto y : adj[x[1]])
        {
            if (dist[y.first] == INT_MAX)
            {
                pq.push({x[0] + y.second, y.first});
            }
        }
    }
    return dist[des];
}

int totalPaths(int n, vector<vector<int>> &edges, int src, int des) //maybe less complexity as no loop inside while(good way)
{
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    vector<int> dist(n, INT_MAX);
    vector<int> paths(n);
    dist[0] = 0;
    paths[0] = 1;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        if (dist[x[1]] < x[0]) //has to be less than otherwise if (<=) then paths is not updated correctly
            continue;
        for (auto y : adj[x[1]])
        {
            if (dist[y.first] > dist[x[1]] + y.second)
            {
                dist[y.first] = dist[x[1]] + y.second;
                paths[y.first] = paths[x[1]];
                pq.push({dist[y.first], y.first});
            }
            else if (dist[y.first] == dist[x[1]] + y.second)
            {
                paths[y.first] += paths[x[1]];
            }
        }
    }
    return paths[n - 1];
}

int totalPaths_myway(int n, vector<vector<int>> &edges, int src, int des) //my way a bit slow maybe due to loop in while
{
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    vector<int> dist(n, INT_MAX);
    vector<int> paths(n);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 1});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        int sum = x[2];
        while (!pq.empty() && pq.top()[1] == x[1] && pq.top()[0] == x[0])
        {
            sum += pq.top()[2];
            pq.pop();
        }

        if (dist[x[1]] != INT_MAX)
            continue;
        dist[x[1]] = x[0];
        paths[x[1]] = sum;

        for (auto y : adj[x[1]])
        {
            if (dist[y.first] == INT_MAX)
            {
                pq.push({x[0] + y.second, y.first, paths[x[1]]});
            }
        }
    }
    return paths[des];
}

int main()
{
    int n, k1, k2;
    vector<vector<int>> roads{{}, {}, {}};
    cout << minPath(n, roads, k1, k2) << endl;
    cout << totalPaths(n, roads, k1, k2) << endl;
}