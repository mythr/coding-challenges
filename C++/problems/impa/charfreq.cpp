#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool pairCompare(const pair<char,int>& firstPair, const pair<char,int>& secondPair){
	return firstPair.second < secondPair.second; 
}

int main(){
	string letters = "ABCDEFGHIKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvxyz";
	string currline;

	while(getline(cin,currline)){
		vector<pair<char,int> > occurances;
		int maxCount = 0;

		for(char i : letters){
			int currCount = count(currline.begin(), currline.end(), i);
			if(currCount > maxCount)
			{
				maxCount = currCount;
				occurances.push_back(make_pair(i, maxCount));
			}
			
			else if(currCount == maxCount && currCount > 0){
				occurances.push_back(make_pair(i, maxCount));
			}
		}

		sort(occurances.begin(),occurances.end(),pairCompare);
		for(auto pair : occurances){
			if(pair.second == maxCount)
				cout << pair.first;
		}
		cout << " " << maxCount << endl;
		
	}
	return 0;
}