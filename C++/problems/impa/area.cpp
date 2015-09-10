#include <iostream>

using namespace std;

const int MAX = 100;

int main(){
	int plots[MAX][MAX];
	int testcases, N, M, K;
	cin >> testcases;
	for(int t = 1; t <= testcases; t++){
		cin >> N >> M >> K;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cin >> plots[i][j];
				if(i > 0){
					plots[i][j] += plots[i - 1][j];
				}
			}
		}
		int maxArea = 0;
		int maxCost = 0;
		for(int i = 0; i < N; i++){
			for(int j = i; j < N; j++){
				int cost = 0;
				int area = 0;
				int start = 0;
				for(int k = 0; k < M; k++){
					int colSum = plots[j][k];
					if(i > 0)
						colSum -= plots[i - 1][k];
					cost += colSum;
					if(cost > K){
						while(cost > K){
							cost -= plots[j][start];
							if(i > 0)
								cost += plots[i - 1][start];
							start++;
						}
					}
					area = (k - start + 1) * (j - i + 1);
					if(area == maxArea){
						if(cost < maxCost){
						 	maxCost = cost;
						}
					}
					if(area > maxArea){
						maxArea = area;
						maxCost = cost;
					}
				}
			}
		}

		cout << "Case #" << t << ": " << maxArea << " " << maxCost << endl;

	}

	return 0;
}