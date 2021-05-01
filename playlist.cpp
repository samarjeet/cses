#include<iostream>
#include<vector>
#include<map>
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

    std::map<int, int> mp;
    int ans =0;

    for(int i=0, j=0; i < n; ++i){
        while (j<n && mp[vec[j]] < 1){
            mp[vec[j]]++;
            ++j;
        }
        ans = std::max(ans, j-i);
        mp[vec[i]]--;
    }
    std::cout << ans << std::endl;
 
    return 0;
}