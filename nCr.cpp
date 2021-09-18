#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
ll inv[MAX], fact[MAX], invfact[MAX];

void init()
{
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = (inv[MOD % i] * (MOD - MOD / i)) % MOD;
        invfact[i] = (invfact[i - 1] * inv[i]) % MOD;
    }
}

ll nCr(ll n, ll r)
{
    ll ans = ((fact[n] * invfact[r]) % MOD * invfact[n - r]) % MOD;
    return ans;
}

void solve()
{
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
}
int main()
{
    fastio;
    init();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
