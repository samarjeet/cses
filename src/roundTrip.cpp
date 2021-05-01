#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

typedef long long int ll;
#define INF 1e5
#define MOD 1e9 + 7
 
class Graph {
public:
    Graph() {}

    void readInput(){
        std::cin >> n >> m;
        //edges.resize(m);
        adj.resize(n);
        visited.resize(n, false);
        lastTwo = {-1, -1};

        for (int i=0; i < m; ++i){
            int a, b;
            std::cin >> a >> b; --a; --b; 
            //edges.push_back({a,b});
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    void printInput(){
        std::cout << "\n";
        /*
        for (auto edge : edges){
            std::cout << edge.first << " " << edge.second << "\n";
        }
        */
        for (int i=0; i<n; ++i){
            std::cout << i << " -> " ;
            for (auto node : adj[i]){
                std::cout << node << " " ;
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void dfs(int i, std::pair<int, int> prev){
        if (visited[i]) return;
        
        std::pair<int, int> prev1;
        prev1.second = prev.first;
        prev1.first = i;

        for (auto child : adj[i]){
            if (child != prev.first && child != prev.second)
                dfs(child, prev1);
        }


        /*
        if (state[i] == 2) return;
        if (state[i] == 1) {
            std::cout << "Can't do topo sort\n";
            return;
        }
        state[i] = 1;

        state[i] = 2;
        sorted.push_back(i);
        */
    }

    void process(){
        dfs(0, {-1,-1});
    }


private:
    int n, m;
    std::vector<std::vector<int>> adj;
    //std::vector<std::pair<int, int>> edges;
    std::vector<bool> visited;
    std::pair<int, int> lastTwo;
};

int main(int argc, char** argv){
    Graph g;
    g.readInput();
    g.printInput();

    return 0;
}