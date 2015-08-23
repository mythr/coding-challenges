#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(long int n){
	long int num = n;
	long int rev = 0;
	long int dig = 0;
	while(num > 0){
		dig = num % 10;
		rev = rev * 10 + dig;
		num /= 10;
	}
	if(n == rev)
		return true;
	else
		return false;
}

long int reverse(long int n){
	long int rev = 0;
	long int dig = 0;
	while(n > 0){
		dig = n % 10;
		rev = rev * 10 + dig;
		n /= 10;
	}
	return rev;
}

int main(){
	int testcases;
	cin >> testcases;

	for(int i = 0; i < testcases; i++)
	{
		int iterations = 0;
		long int result = 0;
		cin >> result;
		if(result/10 == 0){
			cout << iterations << " " << result << endl;

		}
		else{
			while(true)
			{
				if(result == reverse(result))
				{
					break;
				}
				result += reverse(result);
				iterations++;
			}
			cout << iterations << " " << result << endl;

		}
		
	}
	return 0;
}