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
        std::cin >> n >> m;
        adj.resize(n);

        for (int i=0; i < m; ++i){
            int s, e; 
            ll l;
            std::cin >> s >> e >> l;
            adj[s-1].push_back({e-1, l});
        }
    }

    void printInput(){

        for (int i=0; i< n; ++i){
            for (auto elem : adj[i]){
                std::cout << i << " " << elem.first << " " << elem.second << "\n";        
            } 
        }
    }

    void djikstra(){
        std::vector<ll> distance(n, INF);
        distance[0] = 0;
        
        std::vector<bool> processed(n, false);
        std::priority_queue<std::pair<ll, int>> q;

        q.push({0,0});

        while (! q.empty()) {
            int a = q.top().second;
            //std::cout << q.top().first << " " << q.top().second << "\n";
            q.pop();   
            if (processed[a]) continue;
            processed[a] = true;

            for (auto elem : adj[a]){
                int b = elem.first;
                ll l = elem.second;

                if (distance[a] + l < distance[b]) {
                    distance[b] = distance[a] + l;
                    q.push({-distance[b], b});
                }
            }
        }

        for (auto d : distance) {
            std::cout << d << " " ;
        }
        std::cout <<"\n";
        
    }
private:
    int n, m;

    std::vector<std::vector<std::pair<int, ll>>> adj;    
};

int main(int argc, char** argv){
    Graph g;
    g.readInput();
    //g.printInput();
    g.djikstra();

    return 0;
}