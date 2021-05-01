#include<iostream>
#include<vector>
#include<algorithm>

int main(int argc, char** argv){
    int n;
    std::cin >> n;
    std::vector<long long> nums(n), pos(n+1, 0);
    for (int i=0; i < n; ++i) {
        std::cin >> nums[i] ;
        pos[nums[i]] = i;
    }

    int rounds = 0;
    for (auto num : nums){
        if (pos[num] >= pos[num+1]) ++rounds;
    }
    std::cout << rounds << "\n";
    return 0;
}