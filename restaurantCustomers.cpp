#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    int n;
    std::cin >> n;
    std::vector<std::vector<ll>> s;
    for (int i = 0; i < n ; ++i){
        ll a,b;
        std::cin >>  a >> b;
        s.push_back({a, 1});
        s.push_back({b, -1});
    }
    std::sort(s.begin(), s.end());
    int ans = 0, c=0;
    for (auto a : s){
        c += a[1];
        ans = std::max(c, ans);
    }

    std::cout << ans;

    return 0;
}