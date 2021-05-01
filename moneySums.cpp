#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    int n;
    std::cin >> n;
    int maxSum = 1e5;
    std::vector<int> x(n,0);

    for(int i=0; i < n; ++i){
        std::cin >> x[i];
    }
    
    std::vector<int> dp(1e5, 0);
    dp[0]=1;
    for (int i=0; i < n; ++i){
        for (int j=maxSum; j ; --j){
            if (j >= x[i])
                dp[j] |= dp[j-x[i]];
        }
    }

    std::vector<int> res;
    for (int di=1; di<=maxSum; ++di){
        if (dp[di]) res.push_back(di);
    }

    std::cout << res.size() << "\n";
    for (auto ri : res)
        std::cout << ri << " ";
    std::cout << "\n";

    return 0;
}