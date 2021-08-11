#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 


ll power(ll a,ll b)    //Avoid overflows by %M some given in problem statement
{
    ll result=1LL;
    while(b>0)
    {
        if(b%2==1) result*=a;
        a*=a;
        b/=2;
    }
    return result;
}


int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
}