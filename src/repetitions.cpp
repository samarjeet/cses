#include <iostream>
#include<string>

int main(int argc, char** argv){

	std::string seq;
	std::cin >> seq;
	auto len = seq.size();

	char prev = seq[0];
	size_t maxLen = 1;
	size_t currenLen = 1;	
	for(int i=1; i < len; ++i) {
		if (seq[i] == prev) {
			currenLen++;
			if (currenLen > maxLen) maxLen = currenLen;
		}
		else currenLen =1;
		prev = seq[i];
	}

	std::cout << maxLen; 
	return 0;
}
