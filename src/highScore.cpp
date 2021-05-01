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
        distance.resize(n, INF);

        for (int i=0; i < m; ++i){
            int s, e; 
            ll l;
            std::cin >> s >> e >> l;
            edges.push_back({s-1,e-1, -l});
        }
    }

    void printInput(){
        for (auto elem : edges){
            std::cout << elem.x << " " << elem.y << " " << elem.z << "\n";        
        }
    }


    void bellmanFord(){
        distance[0]=0;
        for (int i=0; i < n; ++i){
            for(auto e:edges){
                distance[e.y] = std::min(distance[e.y], distance[e.x] + e.z);
            }
        }
        for (auto d : distance) std::cout << d << " ";
        std::cout << "\n";
        ll last_d = distance[n-1];

        for (auto e:edges){
            distance[e.y] = std::min(distance[e.y], distance[e.x] + e.z);
        }

        for (auto d : distance) std::cout << d << " ";
        std::cout << "\n";
        

        if (distance[n-1] != last_d) std::cout << "-1\n";
        else std::cout << -distance[n-1] << "\n";
    }

    void floydWarshall(){
        //distance.resize(n, )
    }
private:
    int n, m;
    class Tuple{
        public:
            int x, y;
            ll z;
        Tuple(int x, int y, ll z) :x(x), y(y), z(z){}
    };

    std::vector<Tuple> edges;    
    std::vector<std::pair<int, int>> queries;

    
    std::vector<ll> distance; // (n, std::vector<ll>(n, INF));
};

int main(int argc, char** argv){
    Graph g;
    g.readInput();
    //g.printInput();
    //g.djikstra();
    //g.floydWarshall();
    g.bellmanFord();

    return 0;
}
