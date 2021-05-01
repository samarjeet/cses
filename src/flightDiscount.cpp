#include<iostream>
#include<vector>
#include<queue>

// Applying Djikstra's algorithm first


typedef long long int ll;
#define INF 1e16


class Graph{

public:
    Graph(){}
    void readInput(){
        std::cin >> n >> m;
        adj.resize(n);

        for (int i=0; i < m; ++i){
            int a, b;
            ll c;
            std::cin >> a >> b >> c; --a; --b;
            //pq.push({a, b, c});
            adj[a].push_back({c, b});
        }
    }

    void printInput(){
        int i=0;
        for (auto row : adj){
            for (auto elem : row){
                std::cout << i << " " << elem.second << " " << elem.first << "\n";
            }
            //std::cout << 
            ++i;
        }

    }

    void dijkstras(){
        std::vector<ll> distance(n, INF);
        distance[0] = 0;

        std::vector<bool> processed(n, false);

        std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> pq;
        pq.push({0,0});

        while(! pq.empty()){
            auto top = pq.top(); pq.pop();
            
            auto a = top.second;
            processed[a] = true;
            
            for (auto elem : adj[a]){
                auto b = elem.second; 
                auto w = elem.first;

                if (processed[b]) continue;

                if (distance[b] > distance[a] + w ) distance[b] = distance[a] + w;
                pq.push({distance[b], b});
            }
        }

        std::cout << "\n";
        for (auto elem : distance){
            std::cout << elem << " "; 
        }
        std::cout << "\n";
    }


private:
    int n, m;
    std::vector<std::vector<std::pair<ll, int>>> adj;
};

int main(int argc, char** argv){

    Graph g;
    g.readInput();
    //g.printInput();
    g.dijkstras();

    return 0;
}