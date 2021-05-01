#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    //const int M = 1e9 + 7;
    int n, x; 
    std::cin >> n >> x;

    std::vector<int> h(n, 0), s(n,0);
    std::vector<std::vector<int>> hs(n, std::vector<int>(2, 0));

    for (int i=0; i < n; ++i){
        std::cin >> h[i];
        hs[i][0] = h[i];
    }
    for (int i=0; i < n; ++i){
        std::cin >> s[i];
        hs[i][1] = s[i];
    }

    std::sort(hs.begin(), hs.end());
    /*std::vector<std::vector<int>> result(x+1, std::vector<int>(n+1, 0));
    
    for (int k=1; k<=n; ++k){
        for (int price=1; price <= x; ++price){
            if (price - hs[k-1][0] >= 0)
                result[price][k] = std::max(result[price - hs[k-1][0]][k-1] + hs[k-1][1], result[price][k-1] );
        }
    }
    */

    std::vector<int> res(x+1, 0);
    for (int k=1; k<=n; ++k){
        for (int price=x; price >= hs[k-1][0]; --price){
            res[price] = std::max(res[price-hs[k-1][0]] + hs[k-1][1], res[price]);
        }
    }
    
    std::cout << res[x] << "\n";
    return 0;
}