#include<iostream>
#include<vector>
#include<algorithm>


void dfs(int i, int j, int n, int m, std::vector<std::vector<int>> &visited, std::vector<std::vector<char>> &house ){
    
    if (visited[i][j] || house[i][j] == '#') return ; 
    visited[i][j] = 1;
    if (i+1 < n) dfs(i+1, j, n, m, visited, house);
    if (i-1 >= 0) dfs(i-1, j, n, m, visited, house);
    if (j+1 < m) dfs(i, j+1, n, m, visited, house);
    if (j-1 >= 0) dfs(i, j-1, n, m, visited, house);
}

int main(int argc, char** argv){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> house(n, std::vector<char>(m, ' '));
    std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));

    for (int i=0; i < n; ++i){
        for (int j=0; j < m; ++j){
            std::cin >> house[i][j];
        }
    }

    int rooms = 0;
    for (int i=0; i < n; ++i){
        for (int j=0; j < m; ++j){
            if (! visited[i][j] && house[i][j] == '.') {
                //std::cout << i << " " << j << "\n";
                ++rooms;
                dfs(i, j, n, m, visited, house);
            }
        }
    }

    std::cout << rooms << "\n";
    return 0;
}