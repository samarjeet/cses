#include<iostream>
#include<vector>

int main(int argc, char** argv){
	size_t size;
	std::vector<long long int> nums;
	std::cin >> size;
	for(int i=0; i < size; ++i){
		int ni;
		std::cin >> ni;
		nums.push_back(ni);
	}
	long long int turns = 0;
	for (int i=1; i<size; ++i){
		if (nums[i] < nums[i-1]){
			turns += (nums[i-1]-nums[i]);
			nums[i] = nums[i-1];
		}
	}
	std::cout << turns;
	return 0;
}
