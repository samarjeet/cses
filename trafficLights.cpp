#include<iostream>
#include<map>
#include<set>

#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    ll x;
    int n; 
    std::cin >> x >> n;
    std::set<ll> pos;

    std::map<ll, int> mp;
    pos.insert(0);
    pos.insert(x);

    mp[x] = 1; 
 
    for (int i=0; i < n; ++i){
        ll p;
        std::cin >> p;

        //auto it = std::lower_bound(pos.begin(), pos.end(), p);
        
        auto it = pos.lower_bound(p);
        int r = *it;
        --it;
        auto l = *it;

        --mp[r-l]; 
        if (!mp[r-l]) mp.erase(r-l);
        
        pos.insert(p);

        ++mp[r-p];
        ++mp[p-l];

        std::cout << ((--mp.end())->first) << " ";

    }
    return 0;
}