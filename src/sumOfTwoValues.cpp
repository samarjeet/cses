#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    int n; ll x;
    std::cin >> n >> x;

    std::vector<std::vector<ll>> vec;

    for (ll i=0; i < n; ++i){
        ll a;
        std::cin >> a;
        vec.push_back({a, i});
    }

    std::sort(vec.begin(), vec.end());
    int i=0, j=n-1;
    while (i < j ){
        if (vec[i][0] + vec[j][0] > x ) --j;
        else if (vec[i][0] + vec[j][0] < x ) ++i;
        else break;
    }

    if (i>=j) std::cout << "IMPOSSIBLE";
    else {
        std::cout << vec[i][1]+1 << " " << vec[j][1]+1 << std::endl;
    }

    return 0;
}