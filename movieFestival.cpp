#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    int n;
    std::cin >> n;
    std::vector<std::vector<ll>> vec;

    for (int i=0; i < n; ++i){
        ll a, b;
        std::cin >> a >> b;
        vec.push_back({b,a});
    }

    std::sort(vec.begin(), vec.end());
    int ans = 0, l =0;
    for (auto v : vec){
        if (v[1] >= l) {
            ++ans;
            l = v[0];
        }
    }

    std::cout << ans << "\n";
    return 0;
}