#include<iostream>
#include<vector>
#include<algorithm>

int main(int argc, char** argv){
    int n;
    std::cin >> n;
    std::vector<long long> nums(n);
    for (int i=0; i < n; ++i) std::cin >> nums[i] ;
    std::sort(nums.begin(), nums.end());

    //  I can create all sums < misSum
    long long minSum = 1;
    for (auto num : nums){
        if (minSum < num) break;
        else minSum += num;
    }
    std::cout << minSum << "\n";
    return 0;
}