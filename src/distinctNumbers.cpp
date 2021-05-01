#include<iostream>
#include<vector>
#include<algorithm>

int main(int argc, char** argv){
	int n;
	std::vector<long long int> x;
	std::cin >> n;
	for (int i=0; i<n; ++i){
		long long int xi;
		std::cin >> xi;
		x.push_back(xi);
	}

	std::sort(x.begin(), x.end(), std::greater<long long int>());

	int distinct =1;
	for(int i=1; i<n;++i){
		if (x[i] != x[i-1]) distinct++;
	}
	std::cout << distinct ;

	return 0;
}
