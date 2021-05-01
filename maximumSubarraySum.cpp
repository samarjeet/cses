#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    int n; 
    std::cin >> n;
    

    ll maxSum = -1e18, msf = -1e18;
    for (int i=0; i < n; ++i){
        ll x;
        std::cin >> x;
        msf = std::max(msf + x, x);
        maxSum = std::max(maxSum, msf);
        
    }
    std::cout << maxSum << std::endl;
    return 0;
}