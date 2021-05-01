#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

typedef long long ll;

int main(int argc, char** argv){
    int n; 
    std::cin >> n;
    std::vector<std::vector<ll>> vec;
 
    for (int i=0; i < n; ++i){
        ll a, b;
        std::cin >> a >> b;
        vec.push_back({2*a, 1, i});
        vec.push_back({2*b+1, -1, i});
    }
    std::sort(vec.begin(), vec.end());

    int maxVal = -1;
    int sum = 0;

    for (int i=0; i < vec.size(); ++i){
        sum += vec[i][1];
        maxVal = std::max(sum, maxVal);
    }
    
    std::cout << maxVal << std::endl;
    ll r=0;
    std::vector<std::vector<ll>> res;

    for (int i=0; i < vec.size(); ++i){
        if (vec[i][1] > 0) {
            //std::cout << ++r << " ";
            res.push_back({vec[i][2], ++r, vec[i][0]});
        }
        else { --r;}
    }

    std::sort(res.begin(), res.end());
    for (int i=0; i < res.size(); ++i){
        //std::cout << res[i][1] << "," << res[i][0] << "," <<  res[i][2]/2 << "      ";
        std::cout << res[i][1] << " "; 
    }
 
    return 0;
}