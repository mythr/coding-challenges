#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 10001;
const int MAX_CITIES = 250;

typedef pair<map<string,int>::iterator,bool> map_return;

int graph[MAX_CITIES][MAX_CITIES];

int bfs(int start, int end){
	priority_queue<pair<int, int> > q;
	q.push(make_pair(start,INF));
	pair<int,int> p;
	int visited[MAX_CITIES];
	for(int i = 0; i < MAX_CITIES; i++){
		visited[i] = -1;
	}
	while(true){
		p = q.top();
		q.pop();
		if(p.first == end)
			return p.second;
		for(int i = 0; i < MAX_CITIES; i++){
			if(graph[p.first][i] != INF){
				if(min(p.second,graph[p.first][i]) > visited[i]){
					visited[i] = min(p.second,graph[p.first][i]);
					q.push(make_pair(i,visited[i]));
				}
			}
		}

	}
}

int main(){
	map<string, int> nodes;
	int n, r,tons,source,dest;
	int scenario = 1;
	while(cin >> n >> r){
		nodes.clear();
		for(int i = 0; i < MAX_CITIES; i++)
			for(int j = 0; j < MAX_CITIES; j++)
				graph[i][j] = INF;

		if(n == 0 && r == 0)
			break;

		int id = 0;
		for(int i = 0; i < r; i++){
			string first, second;
			int weight,a,b;
			cin >> first >> second >> weight;
			map_return ret = nodes.insert(make_pair(first,id));
			if(ret.second){
				a = id;
				id++;
			}
			else{
				a = ret.first -> second;
			}
			ret = nodes.insert(make_pair(second,id));
			if(ret.second){
				b = id;
				id++;
			}
			else{
				b = ret.first -> second;
			}
			graph[a][b] = weight;
			graph[b][a] = weight;
		}
		
		string start, end;
		cin >> start >> end;
		source = nodes.find(start) -> second;
		dest = nodes.find(end) -> second;
		cout << "Scenario #" << scenario << endl << bfs(source,dest) << " tons" << endl;
		scenario++;
		cout << endl;
	}


	return 0;
}