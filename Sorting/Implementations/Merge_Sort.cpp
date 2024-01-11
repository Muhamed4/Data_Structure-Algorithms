#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
#define endl '\n'


void MergeSort(int arr[], int l, int mid, int r){
    int sz1 = mid - l + 1;
    int sz2 = r - mid;
    int *left = new int[sz1];
    int *right = new int[sz2];
    for(int i = 0; i < sz1;i++)left[i] = arr[l + i];
    for(int i = 0; i < sz2;i++)right[i] = arr[mid + i + 1];
    int lefts = 0, righted = 0;
    for(int i = l; i <= r;i++){
        if(lefts >= sz1){
            arr[i] = right[righted++];
            continue;
        }
        if(righted >= sz2){
            arr[i] = left[lefts++];
            continue;
        }
        if(left[lefts] < right[righted])arr[i] = left[lefts++];
        else arr[i] = right[righted++];
    }
    delete[] left;
    delete[] right;
}
// Recursion Implementation
void Sort(int arr[], int start, int end){
    if(end <= start)return;
    int mid = start + (end - start) / 2;
    Sort(arr, start, mid);
    Sort(arr, mid + 1, end);
    MergeSort(arr, start, mid, end);
}

// Bottom Up Mergesort
void Sort(int arr[], int Sz){
    for(int i = 1; i < Sz;i = i + i){
        for(int j = 0; j < Sz - i; j += i + i){
            MergeSort(arr, j, j + i - 1, min(j + i + i - 1, Sz - 1));
        }
    }
}


// 2 - Way Merge Sort
void Sort2Way(int arr[], int n){
    for(int i = 1; i <= n - 1;i *= 2){
        for(int left = 0; left < n - 1; left += 2 * i){
            int mid = min(left + i - 1, n - 1);
            int right = min(left + 2 * i - 1, n - 1);

            MergeSort(arr, left, mid, right);
        }
    }
}


void solve(){
    int n;cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n;i++)cin >> arr[i];
    Sort2Way(arr, n);
    for(int i = 0; i < n;i++)cout << arr[i] << ' ';

    delete[] arr;
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