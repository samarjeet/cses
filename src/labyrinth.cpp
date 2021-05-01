#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

class Graph{
public:
	Graph(){
		visitedA = false;
		visitedB = false;
	}

	void readInput(){
		std::cin >> n >> m;
		matrix.resize(n, std::vector<char>(m, ' '));
		visited.resize(n, std::vector<int>(m, 0));
		
		
		bfsVisited.resize(n, std::vector<int>(m, 0));
		bfsAdded.resize(n, std::vector<int>(m, 0));
		depth.resize(n, std::vector<int>(m, 0));

		for (int i=0; i < n; ++i){
			for (int j=0; j < m; ++j){
				std::cin >> matrix[i][j];

				if (matrix[i][j] == 'A' ) indexA = {i,j};
				if (matrix[i][j] == 'B' ) indexB = {i,j};
			}
		}
	}

	void printInput(){
		for (auto row : matrix){
			for (auto elem : row) {
				std::cout << elem; // << " ";
			}
			std::cout << "\n";
		}
	}

	void dfs(int i, int j){
		if (matrix[i][j] == '#' ||  visited[i][j]) return;
		visited[i][j] = 1;
		if (i-1 >= 0) dfs(i-1, j);
		if (j-1 >= 0) dfs(i, j-1);
		if (i+1 < n) dfs(i+1, j);
		if (j+1 < m) dfs(i, j+1);
	}

	void connectedComponents(){
		int components = 0;
		for (int i=0; i<n; ++i){
			for (int j=0; j < m; ++j){
				if (matrix[i][j] == '#') continue;
				if (!visited[i][j]) {
					dfs(i, j);
					++components;
				}
			}
		}
		std::cout << components << "\n";
	}

	void bfs(int i, int j){ 
		
		bfsVisited.resize(n, std::vector<int>(m, 0));
		bfsAdded.resize(n, std::vector<int>(m, 0));
		depth.resize(n, std::vector<int>(m, 0));

		std::queue<std::pair<int, int>> queue;
		std::vector<std::vector<std::pair<int, int>>> parent;
		parent.resize(n, std::vector<std::pair<int, int> >(m, {-1, -1}));

		queue.push({i,j});
		bfsAdded[i][j] = 1;

		std::vector<int> di = {-1, 1, 0, 0};
		std::vector<int> dj = {0, 0, -1, 1};
		
		//std::vector<char> di = {'U', 'D', 'L', 'R'};

		while( ! queue.empty()){
			auto front = queue.front();
			queue.pop();

			i = front.first; 
			j = front.second;

			bfsVisited[i][j] = 1;
			if (matrix[i][j] == 'A') {visitedA = true;  }
			if (matrix[i][j] == 'B') {visitedB = true;  }
			
			if ( matrix[i-1][j] != '#' && bfsAdded[i-1][j] == 0 && i-1 >=0) { queue.push({i-1, j}); bfsAdded[i-1][j]=1; depth[i-1][j] = depth[i][j]+1; parent[i-1][j] = {i,j}; }
			if ( matrix[i+1][j] != '#' && bfsAdded[i+1][j] == 0 && i+1 < n) { queue.push({i+1, j}); bfsAdded[i+1][j]=1; depth[i+1][j] = depth[i][j]+1; parent[i+1][j] = {i,j}; }
			if ( matrix[i][j-1] != '#' && bfsAdded[i][j-1] == 0 && j-1 >=0) { queue.push({i, j-1}); bfsAdded[i][j-1]=1; depth[i][j-1] = depth[i][j]+1; parent[i][j-1] = {i,j}; }
			if ( matrix[i][j+1] != '#' && bfsAdded[i][j+1] == 0 && i+1 < m) { queue.push({i, j+1}); bfsAdded[i][j+1]=1; depth[i][j+1] = depth[i][j]+1; parent[i][j+1] = {i,j}; }
		}

		if ( (visitedA && ! visitedB) || (!visitedA && visitedB)) std::cout << "NO";
		else if (visitedA && visitedB) {
			std::cout << "YES\n";

			std::cout << depth[indexB.first][indexB.second]  << "\n"; 

			for (auto v = indexB; v != indexA; v = parent[v.first][v.second] ) {
				std::cout << v.first << " " << v.second << "\n";
			}
		}

	}

	void labyrinth(){
		bfs(indexA.first, indexA.second);
	}
private:
	int n, m;
	std::vector<std::vector<char>> matrix;
	std::vector<std::vector<int>> visited; 
	
	bool visitedA ;
	bool visitedB ;

	std::pair<int, int> indexA;
	std::pair<int, int> indexB;

	std::vector<std::vector<int>> bfsAdded, bfsVisited;
	std::vector<std::vector<int>>  depth; 
};

int main(int argc, char** argv){
	Graph g;
	g.readInput();
	//g.printInput();
	//g.connectedComponents();
	g.labyrinth();
 
    return 0;
}