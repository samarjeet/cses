#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int main(int argc, char** argv){
    int n;
    std::cin >> n;
    std::vector<ll> x(n,0);
    std::vector<int> length(n,1);

    for(int i=0; i < n; ++i) std::cin >> x[i];
    
    for (int i=0; i < n; ++i ) {
        for (int j=0; j < i; ++j) {
            if (x[j] < x[i])
                length[i] = std::max(length[i], length[j]+1);
        }
    }

    std::cout << length[std::max_element(length.begin(), length.end()) - length.begin()] << std::endl;

    //for (auto a : length) std::cout << a << " ";
        
    return 0;
}




