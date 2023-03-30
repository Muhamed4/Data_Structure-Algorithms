#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    int n;cin >> n;
    int *a = new int[n], *b = new int[n];
    long long sum1 = 0 , sum2 = 0;
    int cnt1 = 0 , cnt2 = 0;
    for(int i = 0 ; i < n;i++){
        cin >> a[i];
        if(a[i] == -1)cnt1++;
        else sum1 += a[i];
    }
    for(int i = 0 ; i < n;i++){
        cin >> b[i];
        if(b[i] == -1)cnt2++;
        else sum2 += b[i];
    }
    if(cnt1 == 2 && cnt2 == 0){
        if(sum1 > sum2)cout << 0 << '\n';
        else cout << (sum2 - sum1) + 1 << '\n';
    }
    else if(cnt1 == 1 && cnt2 == 1){
        cout << "Infinite" << '\n';
    }
    else if(cnt1 == 0 && cnt2 == 2){
        if(sum2 > sum1)cout << 0 << '\n';
        else cout << (sum1 - sum2) + 1 << '\n';
    }
    else if(cnt1 == 1 && cnt2 == 0){
        if(sum1 > sum2)cout << 0 << '\n';
        else cout << 1 << endl;
    }
    else{
        if(sum2 > sum1)cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    delete[] a;
    delete[] b;
    a = b = nullptr;
}