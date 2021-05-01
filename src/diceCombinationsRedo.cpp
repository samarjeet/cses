#include<iostream>
#include<vector>


int main(int argc, char** argv) {
	const int M  = 1e9 +7;
	int n;
	std::cin >> n;
	std::vector<int> dp(n+1, 0);
	
	dp[0] = 1;
	for(int i=0; i<n; ++i){
		for (int j=1; j<=6; ++j){
			if (i+j <=n) {
				dp[i+j] = ( dp[i+j] + dp[i]) % M;
			}
		}
	}

	//for (auto v : dp) std::cout << v << " ";
	std::cout << dp[n]<< "\n";
	return 0;
}
