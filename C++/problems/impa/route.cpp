#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

//string nodename, int weight
typedef pair<string,int> Edge;
typedef unordered_map<string,list<Edge> > graph;
typedef pair<unordered_map<string,list<Edge> >::iterator,bool> insert_return;

void connectAllTransfers(string node, graph& g){
	list<Edge> edges = g.find(node) -> second;
	for(Edge e : edges){
		if (e.second == 3){
			if(e.first != node){
				list<Edge> nextEdges = g.find(e.first) -> second;
				for(Edge k : nextEdges){
					if(k.first != node){
						g.find(k.first) -> second.push_back(make_pair(node, 3));
						g.find(node) -> second.push_back(make_pair(k.first,3));
					}
				}
			}
		}
	}
}

int main()
{
	graph g;
	vector<string> transfers;
	int n;
	string s;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		s.erase(s.find(':'),1);
		string currLine = s.substr(0,1);
		string lastNode = string();
		for(int j = 1; j < s.size(); j++){
			if(s[j] == '='){
				j++;
				string newName = s.substr(j,2);
				j++;
				insert_return ret = g.insert(make_pair(newName,list<Edge>()));
				if(!lastNode.empty()){
					g.find(newName)->second.push_back(make_pair(lastNode,3));
					g.find(lastNode)->second.push_back(make_pair(newName,3));
				}
				transfers.push_back(newName);
				//currLine = newName.substr(0,1);
				//lastNode = newName;
			}
			else{
				string node = currLine + s[j];
				insert_return ret = g.insert(make_pair(node,list<Edge>()));
				if(!lastNode.empty()){
					g.find(node)->second.push_back(make_pair(lastNode,1));
					g.find(lastNode)->second.push_back(make_pair(node,1));
				}
				lastNode = node;
			}
		}
	}

	for(auto p : g){
		connectAllTransfers(p.first,g);
		list<Edge> l = g.find(p.first) -> second;
	}
	for(auto p : g){
		list<Edge> l = g.find(p.first) -> second;
		l.sort();
		list<Edge>::iterator it;
		for(it = l.begin(); it != l.end(); it++){
			Edge e = *it;
			it++;
			if(e == *it){
				l.remove(*it);
			}
			else{
				e = *it;
			}
		}
	}
	for(auto p : g){
		cout << "Node: " << p.first << endl;
		for(auto edge : p.second)
		{
			cout << edge.first << " weight: " << edge.second << endl;
		}
	}

	while(cin >> s)
	{
		if(s == "#")
			break;
	}

	return 0;
}