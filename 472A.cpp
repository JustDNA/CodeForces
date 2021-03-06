// math,number theory
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<long> primes(int n){
	vector<long> v;
    long primes[n+1];
    for (long i=0; i<=n; i++) {
        primes[i]=1;
    }
    primes[0] = primes[1] = 1;
    for (long i=2; i<=sqrt(n); i++) {
        for (long j=i+i; j<=n; j=j+i) {
            primes[j] = 0;
        }
    }
    //cout << primes[3] << endl;
    for (long i=0; i<=n; i++) {
        if (primes[i]==0) {
			v.push_back(i);
        }
    }
	return v;
}

int main(){
	long n;
	cin >> n;
	if(n < 12 || n > 1000000){
		return 0;
	}
	vector<long> v = primes(n);
	long i=0,j=v.size()-1;
	while(i<j){
		if(v[i] + v[j] == n){
			cout << v[i] << " " << v[j] << endl;
			return 0;
		}else if(v[i] + v[j] < n){
			i++;
		}else{
			j--;
		}
	}
	return 0;
}
