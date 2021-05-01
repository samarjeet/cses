#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    int a, b;
    std::cin >> a >> b;

    /*
    // Approch : Greedy algorithm : incorrect
    int min, max;
    if (a<b){
        min = a; max=b;
    } 
    else {
        min=b; max=a;
    }

    int steps=0;
    while(min != max){
        int a1 = max - min;
        if (a1 < min) {
            max = min;
            min = a1;
        }
        else {
            max = a1;
        }
        ++steps;
    }
    std::cout << steps << std::endl;

    */
    std::vector<std::vector<int>> dp(a+1, std::vector<int>(b+1, 0));   
    for (int i=1; i <= a; ++i){
        for (int j=1; j <= b; ++j){
            if (i^j)
                dp[i][j] = 1e9;
            for (int k=1; k < i; ++k)
                dp[i][j] = std::min(dp[i][j], dp[i-k][j] + dp[k][j]+1);
            
            for (int k=1; k < j; ++k)
                dp[i][j] = std::min(dp[i][j], dp[i][j-k] + dp[i][k]+1);
        }
    }
    std::cout << dp[a][b] << "\n";
    return 0;
}