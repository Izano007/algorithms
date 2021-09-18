#include <bits/stdc++.h>
using namespace std;

const int mxN = 100;
const int add_cost = 1;   //cost of addition
const int del_cost = 1;   //cost of deletion
const int trans_cost = 1; //cost of transition

//costs can be taken from input

int edit_dist(string &initials, string &finals)
{
    vector<vector<int>> dp(mxN, vector<int>(mxN));
    int m = initials.length();
    int n = finals.length();
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (initials[j - 1] == finals[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1] + add_cost, min(dp[i - 1][j] + del_cost, dp[i - 1][j - 1] + trans_cost));
        }
    }
    return dp[n][m];
}

int main()
{
    string initials, finals;
    cin >> initials >> finals;
    cout << "Total cost: " << edit_dist(initials, finals) << endl;
}
