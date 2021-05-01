#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    const int M = 1e9 + 7;
    unsigned int n, x; 
    std::cin >> n >> x;
 
    std::vector< int> c;
    
    for (int i=1; i <= n; ++i){
        int ci;
        std::cin >> ci;
        c.push_back(ci);
    }

    std::vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for (auto ci : c){
        for (int i=1; i <= x; ++i){
            if (i-ci >= 0) {
                dp[i] =  (dp[i] + dp[i-ci]) % M ;
            }
        }
    }
    std::cout << dp[x] << std::endl;
    return 0;
}