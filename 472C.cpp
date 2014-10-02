//greedy
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct name{
		char first[50],last[50];
};

struct rank{
	int indx, wordPos;
};

bool compare(rank a,rank b)
{
	return a.wordPos<b.wordPos;
}

int main(){
	int n;
	cin >> n;
	if(n<1 || n>100000){
		return 0;
	}
	name names[n];
	for(int i=0; i<n; i++){
		cin >> names[i].first;
		cin >> names[i].last;
	}
	rank ranks[n];
	for(int i=0; i<n; i++){
		cin >> ranks[i].wordPos;
		ranks[i].indx = i;
	}
	sort(ranks,ranks+n,compare);
	for(int j=0; j<n; j++){
		cout << ranks[j].wordPos << " " << names[ranks[j].indx].first << " " << names[ranks[j].indx].last << endl;
	}
	int j=0;
	char * low;
	if(strcmp(names[ranks[0].indx].first,names[ranks[0].indx].last)>0){
		low = names[ranks[0].indx].last;
	}else{
		low = names[ranks[0].indx].first;
	}
	while(j++ < n){
		if((strcmp(low, names[ranks[j].indx].first) > 0) && (strcmp(low, names[ranks[j].indx].last) > 0)){
			cout << "NO" << endl;
			return 0;
		}else if(strcmp(names[ranks[j].indx].last, names[ranks[j].indx].first) <= 0){
			if(strcmp(low, names[ranks[j].indx].last) <= 0){
				low = names[ranks[j].indx].last;
			}else{
				low = names[ranks[j].indx].first;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
