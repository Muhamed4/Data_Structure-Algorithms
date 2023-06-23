#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n;cin >> n;
	queue<int>a, b;
	for(int i = 0; i < n;i++) {
		int x;cin >> x;
		a.push(x);
	}
	for(int i = 0; i < n;i++){
		int x;cin >> x;
		b.push(x);
	}
	int ans = 0;
	while(!b.empty()){
		if(a.front() == b.front()){
			a.pop();
			b.pop();
		}
		else{
			int x = a.front();
			a.pop();
			a.push(x);
		}
		++ans;
	}
	cout << ans << '\n';
}