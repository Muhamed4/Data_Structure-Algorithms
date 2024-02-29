#include <iostream>
#include <algorithm>
#include <cassert>
// #include "QuickSort.hpp"
using namespace std;
// using namespace DSA;
typedef long long ll;
#define endl '\n'

void MergeSort(int arr[], int l, int mid, int r)
{
    int sz1 = mid - l + 1;
    int sz2 = r - mid;
    int *left = new int[sz1];
    int *right = new int[sz2];
    for (int i = 0; i < sz1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < sz2; i++)
        right[i] = arr[mid + i + 1];
    int lefts = 0, righted = 0;
    for (int i = l; i <= r; i++)
    {
        if (lefts >= sz1)
        {
            arr[i] = right[righted++];
            continue;
        }
        if (righted >= sz2)
        {
            arr[i] = left[lefts++];
            continue;
        }
        if (left[lefts] < right[righted])
            arr[i] = left[lefts++];
        else
            arr[i] = right[righted++];
    }
    delete[] left;
    delete[] right;
}
// Recursion Implementation
void Sort(int arr[], int start, int end)
{
    if (end <= start)
        return;
    int mid = start + (end - start) / 2;
    Sort(arr, start, mid);
    Sort(arr, mid + 1, end);
    MergeSort(arr, start, mid, end);
}

// Bottom Up Mergesort
void Sort(int arr[], int Sz)
{
    for (int i = 1; i < Sz; i = i + i)
    {
        for (int j = 0; j < Sz - i; j += i + i)
        {
            MergeSort(arr, j, j + i - 1, min(j + i + i - 1, Sz - 1));
        }
    }
}

// 2 - Way Merge Sort
void Sort2Way(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i *= 2)
    {
        for (int left = 0; left < n - 1; left += 2 * i)
        {
            int mid = min(left + i - 1, n - 1);
            int right = min(left + 2 * i - 1, n - 1);

            MergeSort(arr, left, mid, right);
        }
    }
}

void SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i, mn = 1e9;
        for (int j = i; j < n; j++)
        {
            if (mn > arr[j])
            {
                mn = arr[j];
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

void InsertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++){        
        int value = arr[i];
        int hole = i;
        while (hole > 0 && arr[hole - 1] > value) {
            arr[hole] = arr[hole - 1];
            hole--;
        } 
        arr[hole] = value;
    }
}

void BubbleUp(int *arr, int idx){
    if(idx == 0)
        return;
    int parentIdx = (idx / 2) - (idx % 2 == 0);
    if(arr[parentIdx] < arr[idx]){
        swap(arr[parentIdx], arr[idx]);
        BubbleUp(arr, parentIdx);
    }
}

void BubbleDown(int *arr, int idx, int lastSize){

    int leftChild = idx * 2 + 1;
    int rightChild = idx * 2 + 2;
    int rootIdx = idx;

    if(leftChild < lastSize && arr[rootIdx] < arr[leftChild])
        rootIdx = leftChild;
    
    if(rightChild < lastSize && arr[rootIdx] < arr[rightChild])
        rootIdx = rightChild;

    if(rootIdx != idx){
        swap(arr[rootIdx], arr[idx]);
        BubbleDown(arr, rootIdx, lastSize);
    }
}

void HeapSort(int *arr, int n){

    for(int i = 0; i < n;i++){
        BubbleUp(arr, i);
    }

    for(int i = n - 1; i >= 0;i--){
        swap(arr[0], arr[i]);
        BubbleDown(arr, 0, i);
    }
}

void solve()
{
    int arr[] = {2, 1, 8, 4, 7, 5, 3, 9, 6};
    HeapSort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    int t = 1; // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}