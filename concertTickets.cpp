#include<iostream>
#include<vector>
#include<algorithm>

void print(std::vector<long> nums){
    for (auto num : nums){
        std::cout << num << " ";
    }
    std::cout << "\n";
}

typedef long long ll;

int main(int argc, char** argv){
    int m, n;
    std::vector<ll> h; //, t;

    std::cin >> n >> m;
    for(int i =0; i < n; ++i){
        ll a;
        std::cin >> a;
        h.push_back(a);
    }

    std::sort(h.begin(), h.end());

    for(int i =0; i < m; ++i){
        ll a;
        std::cin >> a;
        int j = h.size()-1;
        while ( j >= 0 ){
            if (h[j] <= a) break;
            --j;
        }
        if (j!=-1) {
            std::cout << h[j] << "\n";
            h.erase(h.begin() + j);
        }
        else {
            std::cout << j << "\n"; 
        }
    }



    return 0;
}