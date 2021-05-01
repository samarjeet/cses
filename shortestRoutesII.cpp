#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
typedef long long int ll;
#define INF 1e16

class Graph{
public:
    Graph () {}

    void readInput(){
        std::cin >> n >> m >> q;
        adj.resize(n);

        
        distance.resize(n, std::vector<ll>(n, INF));

        for (ll i=0; i < m; ++i){
            int s, e; 
            ll l;
            std::cin >> s >> e >> l;
            adj[s-1].push_back({e-1, l});
            //adj[e-1].push_back({s-1, l});
            if (l < distance[e-1][s-1]) {
                distance[e-1][s-1]=l;
                distance[s-1][e-1]=l;
            }
        }

        for (int i=0; i < q; ++i){
            int a, b;
            std::cin >> a >> b;
            queries.push_back({a-1,b-1});
        }
    }

    void printInput(){
        for (int i=0; i< n; ++i){
            for (auto elem : adj[i]){
                std::cout << i << " " << elem.first << " " << elem.second << "\n";        
            } 
        }
    }

    void print(std::vector<std::vector<ll>> d){
        for (auto row: d) {
            for (auto elem : row ){
                std::cout << elem << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void floydWarshall(){
        
        for (int i=0; i < n; ++i){
            distance[i][i] = 0;
        }

        for (int k=0; k < n; ++k){
            for (int i=0; i<n; ++i){
                for (int j=0; j<n; ++j){
                    distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
                    //std::cout << distance[i][j] << "\n";

                }
            }
            //print(distance);
        }

        for (auto q : queries){
            int i = q.first;
            int j = q.second;


            if (distance[i][j] == INF) std::cout << -1 << "\n";
            else {
                std::cout << distance[i][j] << "\n";
            }
        }

    }
private:
    int n, q;
    ll m;

    std::vector<std::vector<std::pair<int, ll>>> adj;    
    std::vector<std::pair<int, int>> queries;

    
        std::vector<std::vector<ll>> distance; // (n, std::vector<ll>(n, INF));
};

int main(int argc, char** argv){
    Graph g;
    g.readInput();
    //g.printInput();
    //g.djikstra();
    g.floydWarshall();

    return 0;
}