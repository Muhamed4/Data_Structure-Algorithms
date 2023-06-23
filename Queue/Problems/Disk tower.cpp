#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n;cin >> n;
	unordered_map<int,int>mp;
	int idx = n;
	for(int i = 0;i < n;i++){
		int x;cin >> x;
		mp[x] = 1;
		while(mp.count(idx) == 1){
			cout << idx << ' ';
			--idx;
		}
		cout << '\n';
	}
}