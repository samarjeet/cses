#include<iostream>
#include<vector>
#include<fstream>

int M = 1e9 + 7; 

class Triplet{
public:
    int a, b,c;
};

int modpow(int a, int b, int M ){    
    if (b == 0) return 1 % M;
    long long x = modpow(a, b/2, M);
    x = (x*x) % M;
    if (b & 1)  x = (x*a) % M;
    
    return x;
}

int main(int argc, char **argv){
    int n;
    std::cin >> n;
    std::vector<Triplet> vec(n);

    for (int i=0; i<n; ++i){
        int a, b, c;
        std::cin >> a >> b >> c;
        vec[i] = {a,b,c};
    }

    /*
    std::ifstream fin; fin.open("exp.out");
    std::vector<int> correct(n);
    for(int i=0; i < n; ++i){
        fin >> correct[i] ;
    }
    */

    for (int i=0; i< n; ++i){     
        auto exp = modpow(vec[i].b, vec[i].c, M-1); 
        int ans = modpow(vec[i].a , exp, M);
        //std::cout << vec[i].a << " " << vec[i].b << " " << vec[i].c << " " << ans << " " << correct[i] << "\n";
        //if (ans != correct[i]) break;
        std::cout << ans << "\n";
    }
    return 0;
} 