#include <iostream>
#include <vector>

using namespace std;

int main(){
	int set = 0;
	int tmp = 0;
	while(cin >> tmp){
		if(tmp == 0)
			break;
		set++;
		int nStacks = tmp;
		int sum = 0;
		int avg = 0;
		int minimum = 0;
		vector<int> heights = {};
		
		for(int i = 0; i < nStacks; i++){
			cin >> tmp;
			heights.push_back(tmp);
		}

		
		for(int i : heights)
			sum += i;
		avg = sum / nStacks;

		for(int i : heights)
		{
			if(i - avg > 0)
				minimum += i - avg;
		}

		cout << "Set #" << set << endl;
		cout << "The minimum number of moves is " << minimum << "." << endl;
		cout << endl;


	}
		return 0;
}