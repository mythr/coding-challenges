#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_WEIGHT = 10001;

class Edge;

struct Node{
	string name;
	vector<Edge> edges;
	int level = MAX_WEIGHT;
};

typedef pair<map<string, Node>::iterator, bool> map_ret;

class Edge{
	Node src;
	Node dest;
	int weight;
public:
	Edge(Node& from, Node& to,int w){
		src = from;
		dest = to;
		weight = w;
	}
	Node& getTo(){
		return dest;
	}
	int getWeight(){
		return weight;
	}

};

void addNodes(string firstName, string secondName, int weight, map<string, Node>& nodes){
	Node first, second;
	first.name = firstName;
	second.name = secondName;
	map_ret ret;
	Edge e = *(new Edge(first,second,weight));
	first.edges.push_back(e);
	ret = nodes.insert(make_pair(firstName, first));
	if(!ret.second){
		ret.first -> second.edges.push_back(e);
	}
	e = *(new Edge(second,first,weight));
	second.edges.push_back(e);
	ret = nodes.insert(make_pair(secondName, second));
	if(!ret.second){
		ret.first -> second.edges.push_back(e);
	}
}

int BFS(string start, string dest, map<string,Node>& nodes){
	queue<string> q;
	vector<int> maxWeights;
	q.push(start);
	while(!q.empty()){
		string nodeName = q.front();
		Node node = nodes.find(nodeName) -> second;
		int currentLevel = node.level;
		q.pop();
		for(Edge e : node.edges){
			string nextNode = e.getTo().name;
			int nextLevel = nodes.find(nextNode) -> second.level;
			if(nextLevel != MAX_WEIGHT)
				continue;
			nodes.find(nextNode) -> second.level = min(e.getWeight(),currentLevel);
			if(nextNode == dest){
				maxWeights.push_back(min(e.getWeight(),currentLevel));
				break;
			}
			else
			{
				q.push(nextNode);
			}
		}
	}
	int MAX = 0;
	for(int i : maxWeights){
		MAX = max(MAX,i);
	}
	return MAX;
}

int main(){
	map<string, Node> nodes;
	int n, r,tons = 0;
	int scenario = 1;
	while(cin >> n >> r){
		if(n == 0 && r == 0)
			break;
		nodes.clear();
		for(int i = 0; i < r; i++){
			string first, second;
			int weight;
			cin >> first >> second >> weight;
			addNodes(first,second,weight,nodes);
		}
		
		string start, end;
		cin >> start >> end;
		tons = max(tons, BFS(start, end, nodes));
		cout << "Scenario #" << scenario << endl << tons << " tons" << endl;
		scenario++;
		cout << endl;
	}


	return 0;
}