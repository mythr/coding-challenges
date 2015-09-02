#include <iostream>

using namespace std;

const int MAX = 200;
const int MIDDLE = 100;

char input[MAX][MAX];
int output[MAX][MAX];

int main(){
	int rows, cols;
	static int runs = 1;
	while(cin >> rows >> cols){
		if(rows == 0 && cols == 0)
			break;
		for(int i = MIDDLE; i < rows + MIDDLE; i++){
			for(int j = MIDDLE; j < cols + MIDDLE; j++){
				char tmp;
				cin >> tmp;
				input[i][j] = tmp;
				output[i][j] = 0;
			}
		}
		for(int i = MIDDLE; i < rows + MIDDLE; i++){
			for(int j = MIDDLE; j < cols + MIDDLE; j++){
				if(input[i][j] == '*')
				{
					output[i][j] = '*';
					output[i][j+1] += 1;
					output[i+1][j+1] += 1;
					output[i-1][j+1] += 1;
					output[i][j-1] += 1;
					output[i+1][j-1] += 1;
					output[i-1][j-1] += 1;
					output[i+1][j] += 1;
					output[i-1][j] += 1;

				}
			}
		}
		if(runs != 1)
			cout << endl;
		cout << "Field #" << runs <<":" << endl;
		for(int i = MIDDLE; i < rows + MIDDLE; i++){
			for(int j = MIDDLE; j < cols + MIDDLE; j++){
				if(input[i][j] == '*')
					cout << '*';
				else
					cout << output[i][j];
			}
			cout << endl;
		}
		runs++;
	}
	

	return 0;
}