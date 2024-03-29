#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

vector<ll> A;
vector<ll> tree;

void build(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = A[start];
		return;
	}
	int mid = start + (end - start) / 2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int start, int end, int idx, int val)
{
	if (start == end)
	{
		tree[node] = val;
		A[start] = val;
		return;
	}
	int mid = start + (end - start) / 2;
	if (start <= idx && idx <= mid)
	{
		update(2 * node, start, mid, idx, val);
	}
	else
	{
		update(2 * node + 1, mid + 1, end, idx, val);
	}
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
	if (end < l || start > r)
		return;
	if (start >= l && r >= end)
	{
		tree[node] = val;
		A[start] = val;
		return;
	}
	int mid = start + (end - start) / 2;
	updateRange(2 * node, start, mid, l, r, val);
	updateRange(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int start, int end, int l, int r)
{
	if (end < l || start > r)
		return 0;
	if (start >= l && r >= end)
		return tree[node];
	int mid = start + (end - start) / 2;
	ll x1 = query(2 * node, start, mid, l, r);
	ll x2 = query(2 * node + 1, mid + 1, end, l, r);
	return x1 + x2;
}

struct seg_tree   // Segtree for range update and single point query
{
    int N;
    vector<ll> tree;
    seg_tree(int n) : N(n)
    {
        while (__builtin_popcount(N) != 1)
            N++;
        tree.resize(2 * N);
    }

    void updateQuery(int node, int start, int end, int l, int r, ll val)
    {
        if (end < l || start > r)
            return;
        if (start >= l && r >= end)
        {
            tree[node] += val;
            return;
        }
        int mid = start + (end - start) / 2;
        updateQuery(2 * node, start, mid, l, r, val);
        updateQuery(2 * node + 1, mid + 1, end, l, r, val);
        // tree[node] = tree[2 * node] + tree[2 * node + 1];   // Uncomment for range sum query single point update
    }

    ll sumQuery(int node, int start, int end, int l, int r)
    {
        if (end < l || start > r)
            return 0;
        if (start >= l && r >= end)
            return tree[node];
        int mid = start + (end - start) / 2;
        ll x1 = sumQuery(2 * node, start, mid, l, r);
        ll x2 = sumQuery(2 * node + 1, mid + 1, end, l, r);
        return x1 + x2 + tree[node];   // Comment for range sum query single point update
        // return x1+x2;    // Uncomment for range sum query single point update
    }

    void update(int l, int r, ll val)
    {
        updateQuery(1, 0, N - 1, l, r, val);
    }

    ll query(int l, int r)
    {
        return sumQuery(1, 0, N - 1, l, r);
    }
};


void solve()
{
	int n, q;
	cin >> n >> q;
	A.clear();
	A.resize(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	while (__builtin_popcount(n) != 1)
	{
		A.push_back(0);
		n++;
	}
	tree.clear();
	tree.resize(2 * n);
	build(1, 0, n - 1);
	//for(int i=0;i<(int)A.size();i++) cout<<A[i]<<" ";
	//cout<<endl;
	//for(int i=0;i<(int)tree.size();i++) cout<<tree[i]<<" ";
	//cout<<endl;
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1) //update type = 1
		{
			int index, value;
			cin >> index >> value;
			index--;
			update(1, 0, n - 1, index, value);
		}
		else //query type = 2
		{
			int L, R;
			cin >> L >> R;
			L--;
			R--;
			cout << query(1, 0, n - 1, L, R) << endl;
		}
	}
}

int main()
{
	fastio;
	int t = 1;
	//cin>>t;
	while (t--)
		solve();
	return 0;
}
