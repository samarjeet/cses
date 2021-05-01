#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    const int M = 1e9 + 7;
    unsigned int n; 
    std::cin >> n;
 
    std::vector<int> dp;
    dp.push_back(1);
    
    for (int i=1; i <= n; ++i){
        dp.push_back(0);
        for (int j=1; j <= std::min(i, 6); ++j) {
            dp[i] = (dp[i] + dp[i-j]) % M;
        }
    }
    std::cout << dp[n] << std::endl;
 
    return 0;
}