#include<iostream>
#include<vector>
#include<algorithm>

typedef long long int ll;
#define INF 10e9

class Graph {
public:
    Graph() {}

    void readInput(){
        std::cin >> n >> m;

        for (int i=0; i < m; ++i){
            int a, b;
            ll c;
            std::cin >>  a >> b >> c; --a; --b; 
            edges.push_back({a, b, c});
        }
    }

    void printInput(){
        for (auto edge : edges){
            std::cout << edge.a << " " << edge.b << " " << edge.w << "\n";  
        }
    }

    void negativeCycles(){

        // Use the Bellman-Ford algorithm
        std::vector<ll> distance(n, INF);
        std::vector<int> parent(n, -1);

        distance[0]=0;
        
        int x = -1;
        for (int i=0; i < n; ++i){
            x = -1;    
            for (auto edge : edges) {
                if (distance[edge.b] > distance[edge.a] + edge.w){
                    distance[edge.b] = distance[edge.a] + edge.w;
                    parent[edge.b] = edge.a;
                    x = edge.b;
                }
            }
        }

        if ( x == -1){
            std::cout << "NO\n";
        }
        else {
            std::cout << "YES\n";
            for (int i=0; i < n; ++i) x = parent[x];
            std::vector<int> cycle;

            for(int v = x;; v = parent[v]){
                cycle.push_back(v);
                if (v==x && cycle.size() > 1) break;
            }

            std::reverse(cycle.begin(), cycle.end());
            for (auto node : cycle) std::cout << node + 1 << " "; 
            std::cout << "\n";
        }
    }
private:
    int n, m;
    class Edge{
        public:
        int a, b;
        ll w;
    };
    std::vector<Edge> edges;
};

int main(int argc, char** argv){

    Graph g;
    g.readInput();
    //g.printInput();
    g.negativeCycles();

    return 0;
}