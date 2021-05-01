#include<iostream>

int main(int arg, char** argc){

	long long int n;
	std::cin >> n ;
	std::cout << n << " ";
	while(n!=1){
		if (n%2 == 1){
			n = n*3+1;
		}
		else {
			n/=2;
		}

		std::cout << n << " " ;
	}
	//std::cout << "\n";
	return 0;
}
