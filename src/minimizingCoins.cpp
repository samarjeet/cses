#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    const int M = 1e9 + 7;
    unsigned int n, x; 
    std::cin >> n >> x;
 
    std::vector<int> c;
    
    for (int i=1; i <= n; ++i){
        int ci;
        std::cin >> ci;
        c.push_back(ci);
    }

    std::vector<int> dp;
    dp.push_back(0);
    for (int i=1; i <= x; ++i){
        dp.push_back(INF);
        for (auto ci : c){
            if (i-ci >= 0) {
                dp[i] = std::min(dp[i], dp[i-ci] + 1 );
            }
        }
    }
    if (dp[x] < INF)
        std::cout << dp[x] << std::endl;
    else 
        std::cout << -1 << std::endl;
    return 0;
}