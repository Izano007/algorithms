#include <bits/stdc++.h>
using namespace std;

const int mxN = 100;
const int add_cost = 1;   //cost of addition
const int del_cost = 1;   //cost of deletion
const int trans_cost = 1; //cost of transition

//costs can be taken from input

int edit_dist(string &initial, string &final)
{
    vector<vector<int>> dp(mxN, vector<int>(mxN));
    int m = initial.length();
    int n = final.length();
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (initial[j - 1] == final[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1] + add_cost, min(dp[i - 1][j] + del_cost, dp[i - 1][j - 1] + trans_cost));
        }
    }
    return dp[n][m];
}

int main()
{
    string initial, final;
    cin >> initial >> final;
    cout << "Total cost: " << edit_dist(initial, final) << endl;
}
