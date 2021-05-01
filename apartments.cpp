#include<iostream>
#include<vector>
#include<algorithm>

bool acceptable(long long int size, long long int req, long long int k){

	//std::cout << size << " " << req << "\n";
	return (size >= req -k) && (size <= req+k);
}
int main(int argc, char** argv){
	int n, m;
	long long int k;
	std::cin >> n >> m >> k;
	std::vector<long long int> sizes, reqs;

	for (int i=0; i< n; ++i){
		int r;
		std::cin >> r;
		reqs.push_back(r);
	}

	for (int i =0 ; i < m; ++i) {
		int s;
		std::cin >> s;
		sizes.push_back(s);
	}

	std::sort(reqs.begin(), reqs.end());
	std::sort(sizes.begin(), sizes.end());

	int rpos = 0;
	int spos = 0;

	int count = 0;
	while(rpos < n and spos < m){
		if (acceptable(sizes[spos], reqs[rpos], k)){
			count++;
			rpos++; spos++;
		}
		else if (reqs[rpos] > sizes[spos]+k){
			spos++;
		}
		else if (reqs[rpos] < sizes[spos]-k){
			rpos++;
		}
	}

	std::cout << count << std::endl;
	return 0;
}
