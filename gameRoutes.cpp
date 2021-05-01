#include<iostream>
#include<vector>
#include<algorithm>

typedef long long int ll;
#define INF 10e5
#define MOD 10e9 + 7
 
class Graph {
public:
    Graph() {}

    void readInput(){
        std::cin >> n >> m;
        //edges.resize(m);
        adj.resize(n);
        state.resize(n, 0);

        for (int i=0; i < m; ++i){
            int a, b;
            std::cin >> a >> b; --a; --b; 
            //edges.push_back({a,b});
            adj[a].push_back(b);
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

    void dfs(int i){
        if (state[i] == 2) return;
        if (state[i] == 1) {
            std::cout << "Can't do topo sort\n";
            return;
        }
        state[i] = 1;
        for (auto child : adj[i]){
            dfs(child);
        }

        state[i] = 2;
        sorted.push_back(i);
    }

    void dynamicProgram(){
        const unsigned int M = 1000000007;

        // Topological sort based on distance
        for(int i=0; i < n; ++i){
            dfs(i);
        }
        
        std::reverse(sorted.begin(), sorted.end());

        //for (auto node : sorted) std::cout << node + 1 << " " ; std::cout << "\n";
        
        // dynamic
        std::vector<ll> ans(n,0); 
        int i=0;
        while(sorted[i] != 0){
            ans[sorted[i]] = -1;
            ++i;
        }
        ans[sorted[i]] = 1;

        while ( i < n){
            int node = sorted[i];
            for (auto des : adj[sorted[i]]){
                if (ans[des] != -1){
                    ans[des] += ans[sorted[i]];
                    ans[des] %= (M);
                }
            }
            ++i;
        }
        i=0;
        while(sorted[i] != 0){
            ans[sorted[i]] = 0;
            ++i;
        }
        //for (auto a : ans ) std::cout << a << " "; std::cout << "\n";
        
        std::cout << ans[n-1] << "\n";
    }

private:
    int n, m;
    std::vector<std::vector<int>> adj;
    //std::vector<std::pair<int, int>> edges;
    std::vector<int> state;
    std::vector<int> sorted;
};

void test(){
    ll i = -1;
    std::cout << i % (10^9 +7);
}
int main(int argc, char** argv){
    //test();
    Graph g;
    g.readInput();
    //g.printInput();
    g.dynamicProgram();

    return 0;
}