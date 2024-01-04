#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;cin >> n;
    int arr[5]{1, 2, 3, 4, 5};
    for(int i = 0; i < n;i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    int t = 1;//cin >> t;
    for(int i = 1; i <= t;i++){
        solve();
    }
    return 0;
}