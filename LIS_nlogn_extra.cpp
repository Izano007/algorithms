#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> give_me_LIS(vector<int> &X)
{
    int N = X.size();
    vector<int> P(N,-69),M(N+1,-69);
    int L = 0;
    for (int i = 0; i < N; i++)
    {
        int lo = 1, hi = L;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (X[M[mid]] < X[i]) lo=mid+1;
            else hi=mid-1;
        }
        int newL=lo;
        //cout<<newL<<endl;
        P[i]=M[newL-1];
        M[newL]=i;
        if(newL>L) L=newL;
    }
    vector<int> subseq(L);
    int k=M[L];
    for(int i=L-1;i>=0;i--)
    {
        subseq[i]=X[k];
        k=P[k];
    }
    //for(int i=0;i<N;i++) cout<<P[i]<<" ";
    //cout<<endl;
    //for(int i=0;i<=N;i++) cout<<M[i]<<" ";
    //cout<<endl;
    return subseq;
}

int main()
{
    fastio;
    int N;
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; i++)
        cin >> seq[i];
    vector<int> s=give_me_LIS(seq);
    for(int i=0;i<(int)s.size();i++) cout<<s[i]<<" ";
    cout<<endl;
    return 0;
}
