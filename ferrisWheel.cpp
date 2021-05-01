#include<iostream>
#include<vector>
#include<algorithm>

void print(std::vector<long> nums){
    for (auto num : nums){
        std::cout << num << " ";
    }
    std::cout << "\n";
}
int main(int argc, char** argv){
    int n;
    long long int maxWeight;
    std::vector<long> weights;

    std::cin >> n >> maxWeight;
    for (int i=0; i < n; ++i){
        long w;
        std::cin >> w;
        weights.push_back(w);
    }

    std::sort(weights.begin(), weights.end());
    //print(weights);

    int count =0;

    for (int i=0, j = n-1; i<j;){
        while (i <j && weights[i] + weights[j] > maxWeight) 
            j--;
        if (i >= j)
            break;
        ++count;
        ++i; --j;
    }

    std::cout << n-count << std::endl;

    return 0;
}