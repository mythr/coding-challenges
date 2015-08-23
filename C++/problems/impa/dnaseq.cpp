#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct StringInv
{
	string s;
	int inversions;
	bool operator<(const StringInv& rhs) const{
		return inversions < rhs.inversions;
	}

};

int countInversions(string s){

	int inversions = 0;

	for(int i = 0; i < s.length(); i++){
		for(int j = i+1; j < s.length(); j++){
			if(s.at(i) > s.at(j))
				inversions++;
		}
	}

	return inversions;
}

int main(){
	int datasets = 0;
	int sLength = 0;
	int nStrings = 0;
	string currString;
	StringInv current;

	cin >> datasets;

	for(int i = 0; i < datasets; i++)
	{
		cin >> sLength;
		cin >> nStrings;
		StringInv* array = new StringInv[nStrings];
		getline(cin,currString);
		for(int j = 0; j < nStrings; j++)
		{
			getline(cin,currString);
			current.s = currString;
			current.inversions = countInversions(currString);
			array[j] = current;
		}
		stable_sort(array, array + nStrings);
		for(int k = 0; k < nStrings; k++)
			cout << array[k].s << endl;

		delete [] array;
		if(i != datasets - 1)
			cout << endl;

	}


	return 0;

}