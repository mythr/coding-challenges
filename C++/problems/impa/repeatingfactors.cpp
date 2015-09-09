#include<iostream>
#include<string>
using namespace std;

long long pow(long long a, int n){
	long long ret = 1;
	while (n--) ret *= a;
	return ret;
}

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a%b);
}

long long toLong(string s){
	long long ret = 0;
	for (char ch : s){
		ret *= 10;
		ret += (ch - '0');
	}
	return ret;
}

int main(){
	int j;
	string num;
	int Case = 1;
	while (cin >> j && j != -1){
		cin >> num;
		if (j == 0) { num.push_back('0'); j++; }
		num = num.substr(2);
		int k = num.size() - j;
		long long numerator = toLong(num) - toLong(num.substr(0, k));
		long long denominator = pow(10, k + j) - pow(10, k);
		long long g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;
		cout << "Case " << Case++ << ": ";
		cout << numerator << '/' << denominator << endl;
	}
	return 0;
}