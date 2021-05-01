#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    std::string str1, str2;
    std::cin >> str1 >> str2;
    int n = str1.length(), m = str2.length();

    //std::cout << n << " " << m ;

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

    for (int i=0; i <=n; ++i){
        dp[i][0] = i;
    }
    for (int i=0; i <=m; ++i){
        dp[0][i] = i;
    }

    for (int i=1; i <=n; ++i ){
        for (int j=1; j <= m; ++j){
            dp[i][j] = std::min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] + ( (str1[i-1] == str2[j-1]) ? 0 : 1)});
        }
    }

    /*
    for (auto dpi : dp){
        for (auto dpij : dpi){
            std::cout << dpij << " ";
        }
        std::cout << "\n";
    }*/
    std::cout << dp[n][m] << "\n";
    
    return 0;
}