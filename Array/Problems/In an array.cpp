#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    int n, k, x, y;cin >> n >> k >> x >> y;
    int *a = new int[n], *frq = new int[1001];
    for(int i = 0; i < n;i++){
        cin >> a[i];
        frq[a[i]]++;
    }
    long long ans = 0;
    for(int i = 1; i <= 1000;i++){
        if(!frq[i])continue;
        for(int j = i;j <= 1000;j++){
            if(!frq[j])continue;
            int xx = (i + j) % k;
            int yy = (i * j) % k;
            if(xx == x && yy == y){
                if(i == j)ans += (1ll*frq[i] * (frq[i] - 1) / 2);
                else ans += (1ll*frq[i] * frq[j]);
            }
        }
    }
    cout << ans << '\n';
    delete[] a;
    delete[] frq;
    a = frq = nullptr;
}