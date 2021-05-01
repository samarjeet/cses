#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main(int argc, char **argv)
{
    const int MOD = 1e9 + 7;
    int n, m;
    std::cin >> n >> m;

    std::vector<int> nums(n, 0);
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 2, 0));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }
    if (nums[0])
        dp[1][nums[0]] = 1;
    else
    {
        for (int x = 1; x <= m; ++x)
        {
            dp[1][x] = 1;
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int x = 1; x <= m; ++x)
        {
            if (nums[i - 1] == 0 || nums[i - 1] == x)
            {
                dp[i][x] = ( (dp[i - 1][x - 1] + dp[i - 1][x] ) % MOD + dp[i - 1][x + 1]) % MOD;
            }
        }
    }

    /*
    for (auto row : dp)
    {
        for (auto val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    */
    int sum = 0;
    for (int x = 1; x <= m; ++x)
    {
        sum =  (sum + dp[n][x]) % MOD;
    }

    std::cout << sum << "\n";
    return 0;
}