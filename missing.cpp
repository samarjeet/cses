#include<iostream>

int main(int argn, char** argv){

	long long int n, num, sum1, sum2;

	std::cin >> n;
	sum1 = n * (n + 1)/2;
	sum2 = 0;

	for (int i=0; i < n-1; ++i){
		std::cin >> num;
		sum2 +=  num;
	}

	std::cout << sum1 - sum2;
	return 0;
}
