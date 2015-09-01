#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int countOverlap(string s1, string s2){
	string::iterator first = s1.begin();
	string::iterator second = s2.begin();
	int maxN = 0;
	int current = 0;
	for(int i = 0; i < s1.size(); i++)
	{
		second = s2.begin();
		first = s1.begin() + i;
		while(second != s2.end() && first != s1.end()){
				if(*first == *second)
				current++;
			first++;
			second++;
		}
		maxN = max(maxN, current);
		current = 0;
		//Flytta ut den här loopen för att gå igenom hela s1
		first = s1.begin();
		second = s2.end() - i;
		while(second != s2.end() && first != s1.end()){
			if(*first == *second)
				current ++;
			first++;
			second++;
		}
		maxN = max(maxN, current);
		current = 0;
		first = s1.begin();
		second = s2.begin();
		
		while(second != s2.end() && first != s1.end()){
				if(*first == *second)
				current++;
			first++;
			second++;
		}
		maxN = max(maxN, current);
		current = 0;
		
	}
	
	return maxN;
}

int main(){
	int testcases = 0;
	cin >> testcases;
	for(int i = 0; i < testcases; i++){
		int nWords = 0;
		cin >> nWords;
		vector<string> strings;
		int maxN = 0;
		for(int j = 0; j < nWords; j++){
			string currString;
			cin >> currString;
			strings.push_back(currString);
		}
		for(int j = 0; j < nWords; j++){
			for(int k = j + 1; k < nWords; k++){
				int curr = countOverlap(strings.at(j),strings.at(k));
				maxN = max(curr,maxN);
				curr = countOverlap(strings.at(k),strings.at(j));
				maxN = max(curr,maxN);			
			}
		}
		cout << maxN << endl;
	}
	return 0;
}