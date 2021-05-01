#include<iostream>
#include<vector>

int M = 1e9 + 7; 
 
int modpow(int a, int b ){    
    if (b == 0) return 1 % M;
    long long x = modpow(a, b/2);
    x = (x*x) % M;
    if (b & 1) x = (x*a) % M;
    
    return x;
}
 
int main(int argc, char **argv){
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> vec(n);
 
    for (int i=0; i<n; ++i){
        int a, b;
        std::cin >> a >> b;
        vec[i] = {a,b};
    } 
 
    for (int i=0; i< n; ++i){      
        std::cout << modpow(vec[i].first, vec[i].second)  << "\n";
    }
    return 0;
} 