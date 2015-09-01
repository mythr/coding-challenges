#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <string>

using namespace std;

const int MAX = 1024;
const int NO_EDGE = -1;
const int BORDER = 'a' - 'A';

//Graph with pair of (node, weight)
vector< pair<int, int> > graph[MAX];
//Array with node names for output
char node[MAX];
int d[MAX];

void dijkstra(int start, int destination){
	int node;
	int nextNode;
	int nodeCost;
	int edgeWeight;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > queue;

	memset(d, NO_EDGE, sizeof(d));
	queue.push(pair<int, int>(start, 0));

	while(!queue.empty()){
		node = queue.top().first;
		nodeCost = queue.top().second;
		queue.pop();

		if(d[node] < nodeCost) continue;
		if(node == destination)
			return;

		for(int i = 0; i < graph[node].size(); i++){
			nextNode = graph[node][i].first;
			edgeWeight = graph[node][i].second;

			if(d[nextNode] > d[node] + edgeWeight){
				d[nextNode] = d[node] + edgeWeight;
				queue.push(pair<int,int>(nextNode, d[nextNode]));
			}
		}
	}
}

int main(){
	int lines;
	int weight = 0;
	string currentLine;
	char last = - 1;
	cin >> lines;
	for(int i = 0; i < lines; i++){
		cin >> currentLine;
		currentLine.erase(currentLine.find(':'),1);
		//Reset graph
		for(int k = 0; k < currentLine.size(); k++) graph[i].clear();
		char currentStation; 
		//Create the graph
		for(char c : currentLine){
			if(last == -1){
				last = c;
				currentStation = c;
			}
			if(last < BORDER && c < BORDER)
			{
				weight = 3;
				currentStation = c;
			}
			else if(last < BORDER && c >= BORDER)
				weight = 0;
			else if(last >= BORDER && c >= BORDER)
				weight = 1;
			if(c != '='){
				graph[(int)(last + currentStation - 'A')].push_back(pair<int,int>(c,weight));
				graph[(int)(c + currentStation - 'A')].push_back(pair<int,int>(last,weight));
			}
			
		}
	}
	dijkstra(0,3);
	for(int i = 0; i < MAX; i++)
		{
			cout << d[i-'A'] << endl;
		}

	/*
	string in;
	while(cin >> in){
		if(cin.peek() == '#')
			break;
		char startStation,endStation,start,end;
		startStation = in[0];
		start = in[1];
		endStation = in[2];
		end = in[3];
		dijkstra(startStation+start-'A',endStation+end-'A');
		for(int i = 0; i < MAX; i++)
		{
			if(d[i] != NO_EDGE)
				cout << (char)d[i] + 'A' << endl;
		}
	}
	*/
}