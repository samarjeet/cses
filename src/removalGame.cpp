#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    int n;
    std::cin >> n;
    std::vector<ll> x(n,0);

    for(int i=0; i < n; ++i) std::cin >> x[i];
    
    ll fs = 0, ss = 0;
    for (int i=0, j =n-1; i <j; ){
        fs += std::max({x[i], x[j]});
        if (x[i] > x[j]) i++; else j--;
        std::cout << fs << " " ;
        ss += std::max({x[i], x[j]});
        if (x[i] > x[j]) i++; else j--;
    }

        
    return 0;
}