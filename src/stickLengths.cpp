#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    int n; 
    std::cin >> n;
    std::vector<ll> vec;
 
    for (int i=0; i < n; ++i){
        ll x;
        std::cin >> x;
        vec.push_back(x);        
    }
    std::sort(vec.begin(), vec.end());
    ll med = vec[n/2];

    ll sum=0ll;

    for(int i=0; i < n; ++i){
        sum += std::abs(med - vec[i]);
    }
 
    std::cout << sum << std::endl;
    return 0;
}