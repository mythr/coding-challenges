#include <iostream>
#include <algorithm>

using namespace std;
void swap(long long int& i, long long int& j){
	long long int tmp = i;
	i = j;
	j = tmp;
}

int main(){
	long long int i,j,n;
	long long int MAX = 0;
	long long int cycles = 0;
	bool swapped = false;
	while(cin >> i >> j){
		if(i > j){
			swap(i,j);
			swapped = true;
		}
		MAX = 0;
		for(long long int k = i; k <= j; k++){
			n = k;
			cycles = 1;
			while(n != 1){
				if(n % 2 != 0)
					n = 3*n + 1;
				else if(n % 2 == 0)
					n= n/2;
				cycles++;
			}
			MAX = max(cycles,MAX);
		}
		if(swapped){
			swap(i,j);
			swapped = false;
		}
		cout << i << " " << j << " " << MAX << endl;

	}

	return 0;
}