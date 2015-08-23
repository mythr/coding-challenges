#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<long long int> hashmat = {};
	vector<long long int> opponent = {};
	long long int tmp;
	int turn = 0;
	while(cin >> tmp)
	{
		if(turn % 2 == 0)
		{
			hashmat.push_back(tmp);
		}
		else if(turn % 2 != 0){
			opponent.push_back(tmp);
		}
		turn ++;
	}
	long long int result = 0;
	
	for(int i = 0; i < opponent.size(); i++){
		result = opponent.at(i) - hashmat.at(i);
		if(result < 0)
			result *= -1;
		cout << result << endl;
	}
	return 0;
}