#include <bits/stdc++.h>
using namespace std;

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
{

    int n = a.size();
    int m = b.size();
    int dp[n + 1][m + 1] = {};
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}