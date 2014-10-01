#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	if(n<1 || n>2000 || k<1 || k>2000){
		return 0;
	}
	int f[n], i=n;
	while(i--){
		cin >> f[i];
		if(f[i]<2 || f[i]>2000){
			return 0;
		}
	}
	sort(f,f+n);
	i = n-1;
	long long ans = 0;
	while(i >= 0){
		ans += 2*(f[i]-1);
		i -= k;
	}
	cout << ans << endl;
	return 0;
}
