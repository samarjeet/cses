#include<iostream>
#include<vector>


int main(int argc, char** argv){

	int n;
	std::vector<int> nums;

	std::cin >> n;

	if (n>1 && n <4) {
		std::cout <<  "NO SOLUTION";
		return 0;
	}
	for(int i=0; i<n;++i){
			nums.push_back(0);
	}

	for (int i=0; i < n/2; ++i){
		//nums[i]=2*i+ 1;  
		// 5 .. nums[1]=3 nums[3]=4
		// 6 ... nums[2]=5 nums[3]=6
		//nums[n-i-1] = 2*i +2;
		nums[i] = 2*(i+1);
		nums[n/2+i] = 2*i + 1;
	}
	if (n%2) nums[n-1] = n;
	else nums[n-1] = n-1;

	for (auto i : nums){
		std::cout << i << " ";
	}
	return 0;
}
