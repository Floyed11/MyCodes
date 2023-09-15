#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nums[100010];
    int n = 0;
    while (cin >> nums[++n])
        ;
    long long dp[n + 5], ans;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i - 1] > 0)
            dp[i] = dp[i - 1] + nums[i];
        else
            dp[i] = nums[i];
        if (i == 1 || dp[i] > ans)
        {
            ans = dp[i];
        }
    }
    cout << ans << endl;
    return 0;
}