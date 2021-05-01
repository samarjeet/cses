#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
#define INF 1e7

int maxDigit(int n){
    std::vector<int> digits;
    while (n > 0){
        digits.push_back(n%10);
        n/=10;
    }
    //int maxDigit = std::max(digits.begin(), digits.end());
    auto result = std::max_element(digits.begin(), digits.end());

    return digits[result - digits.begin()];
    //return result;
}

int main(int argc, char** argv){
    const int M = 1e9 + 7;

    unsigned int n;
    std::cin >> n;

    int steps = 0;
    while(n > 0){
        //std::cout << n << "\n";
        int m = maxDigit(n);
        n -= m;
        ++steps;
    }

    std::cout << steps << "\n";
    return 0;
}