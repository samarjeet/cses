#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    int n; 
    std::cin >> n;
    std::vector<ll> tops;
 
    for (int i=0; i < n; ++i){
        ll x;
        std::cin >> x;
        int pos = std::upper_bound(tops.begin(), tops.end(), x) - tops.begin();
        if (pos == tops.size()) tops.push_back(x);
        else tops[pos] = x;
    }
    std::cout << tops.size() << std::endl;
 
    return 0;
}