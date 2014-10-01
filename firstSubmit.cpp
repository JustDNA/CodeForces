#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long double n,m,a;
	cin >> n >> m >> a;
	if(n < 1.0 || n > 1000000000.0 || m < 1.0 || m > 1000000000.0 || a < 1.0 || a > 1000000000.0){
			return 0;
	}
	long long count = ceil(n/a) * ceil(m/a);
	cout << count << endl;
	return 0;
}
