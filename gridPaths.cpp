#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    const int M = 1e9 + 7;
    int n; 
    std::cin >> n;
 
    std::vector<std::vector<char>> grid(n, std::vector<char>(n, '.'));
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    
    for (int i=0; i < n; ++i){
        for (int j=0; j < n; ++j){
            char c;
            std::cin >> c;
            grid[i][j] = c;
        }
    }
    
    dp[0][0] = 1;
    for (int i=0; i < n; ++i){
        for (int j=0; j < n; ++j){
            if (grid[i][j] != '*'){
                if (i)
                    dp[i][j] += dp[i-1][j];
                if (j)
                    dp[i][j] += dp[i][j-1];
                dp[i][j] %= M;
            }
            else {
                dp[i][j] = 0;
            }
            //std::cout << dp[i][j] << " ";
        }
        //std::cout << "\n";
    }
    
    std::cout << dp[n-1][n-1] << "\n";
    
    return 0;
}