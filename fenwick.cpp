#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
	
const int MOD=1e9+7;
	
struct binary_indexed_tree{
	int N;
	vector<ll> bit;
	binary_indexed_tree(int n):N(n){
		bit.resize(N+1,0);
	}
	
	ll addition(ll x,ll y){
		return (x+y)%MOD;
	}
	
	void update(int x,ll a){
		x++;
		for(x;x<=N;x+=(x&-x)) bit[x]=addition(bit[x],a);
	}
	
	ll query(int x){
		ll res=0;
		x++;
		for(x;x>0;x-=(x&-x)) res=addition(res,bit[x]);
		return res;
	}
};

void solve(){
	int n;
	cin>>n;
	binary_indexed_tree bit(n);
}

int main()
{
	fastio;
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}
