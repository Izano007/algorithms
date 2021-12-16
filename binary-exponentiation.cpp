#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;

ll power(ll a, ll b) //Avoid overflows by %M some given in problem statement
{
    ll result = 1LL;
    while (b > 0)
    {
        if (b % 2 == 1)
            result *= a;
        result = result % M;
        a *= a;
        a = a % M;
        b /= 2;
    }
    return result;
}

// Any number(n) of 2 can be checked using n&(n-1)==0 in O(1) time.

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
}
