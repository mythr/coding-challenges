#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int longestCommonSubstring(string& s1, string& s2){
	int *curr = new int [s2.size()];
	int *prev = new int [s2.size()];
	int *swap = nullptr;
	int maxSubstr = 0;

	for(int i = 0; i < s1.size(); i++)
	{
		for(int j = 0; j < s2.size(); j++)
		{
			if(s1.at(i) != s2.at(j)){
				curr[j] = 0;
			}
			else{
				if(i == 0 || j == 0){
					curr[j] = 1;
				}
				else{
					curr[j] = 1 + prev[j-1];
				}
				maxSubstr = max(maxSubstr, curr[j]);
			}
		}
		swap = curr;
		curr = prev;
		prev = swap;
	}

	


	delete [] curr;
	delete [] prev;
	return maxSubstr;
}

int equalPositionChars(string& s1, string& s2){
	string::iterator first = s1.begin();
	string::iterator second = s2.begin();
	int equalChars = 0;
	while(first != s1.end() && second != s2.end())
	{
		if(*first == *second)
		{
			equalChars++;
		}
		first++;
		second++;
	}
	return equalChars;
}
/*
int main(){
	string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR";
	string s2 = "ERTGERTYHRTYHSDFVRISDFSLSDFMLGSKLKFOKDFPSLDPFANDMERFCWERAXQWQWEVHMLKLG";
	cout << longestCommonSubstring(s1,s2);
	return 0;
}
*/

int main(){
	int testcases = 0;
	cin >> testcases;
	for(int i = 0; i < testcases; i++){
		int nWords = 0;
		cin >> nWords;
		int maxCandies = 0;
		vector<string> strings;
		for(int j = 0; j < nWords; j++){
			string currString;
			cin >> currString;
			strings.push_back(currString);
		}
		for(int j = 0; j < nWords; j++){
			for(int k = j + 1; k < nWords; k++){
				
				int currEnd = strings.at(k).length();
				int prevEnd = strings.at(j).length();
				int iterations = 1;
				int currPos = 1;
				int prevPos = prevEnd - 1;
				while(prevPos > 0 && currPos < currEnd){
					string curr = strings.at(k).substr(currPos, iterations);
					string prev = strings.at(j).substr(prevPos, iterations);
					cout << "Prev: " << prev << "\nCurr: " << curr << endl;
					currPos++;
					prevPos--;
					iterations++;
					int currCandies = equalPositionChars(prev,curr);
					cout << "CurrCandies is: " << currCandies << endl;
					maxCandies = max(maxCandies,currCandies);
					}
					int currIterations = iterations;
					cout << "Second loop" << endl;
				while(prevPos > 0){
					string prev = strings.at(j).substr(prevPos, iterations);
					cout << "Prev: " << prev << "\nCurr: " << strings.at(k) << endl;
					prevPos--;
					iterations++;
					int currCandies = equalPositionChars(prev,strings.at(k));
					cout << "CurrCandies is: " << currCandies << endl;
					maxCandies = max(maxCandies,currCandies);
				}
				while(currPos < currEnd){
					string curr = strings.at(k).substr(currPos, currIterations);
					cout << "Prev: " << strings.at(j) << "\nCurr: " << curr << endl;
					currPos++;
					currIterations++;
					int currCandies = equalPositionChars(strings.at(j),curr);
					cout << "CurrCandies is: " << currCandies << endl;
					maxCandies = max(maxCandies,currCandies);

				}
					
					//int currCandies = longestCommonSubstring(strings.at(k),strings.at(j));
					//maxCandies = max(maxCandies, currCandies);
				
			}
		}
		cout << maxCandies << endl;
	}
	return 0;
}


