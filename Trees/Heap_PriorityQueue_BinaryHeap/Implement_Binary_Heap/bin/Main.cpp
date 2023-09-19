#include <bits/stdc++.h>

using namespace std;

class MaxHeap
{
private:

    int *arr;
    int maxSize;
    int heapSize;

public:

    MaxHeap(int maxSize);
    
    void MaxHeapify(int);

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int LChild(int i)
    {
        return (2 * i + 1);
    }

    int RChild(int i)
    {
        return (2 * i + 2);
    }

    int RemoveMax();

    void IncreaseKey(int i, int newVal);

    int GetMax()
    {
        return arr[0];
    }

    int CurSize()
    {
        return heapSize;
    }

    void DeleteKey(int i);

    void InsertKey(int x);

    ~MaxHeap()
    {
        delete[] arr;
    }

};

MaxHeap::MaxHeap(int totSize)
{
    heapSize = 0;
    maxSize =  totSize;
    arr = new int[totSize];
}

void MaxHeap::InsertKey(int x)
{
    if(heapSize == maxSize)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    arr[i] = x;

    while(i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[i] , arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::IncreaseKey(int i, int newVal)
{
    arr[i] = newVal;
    while(i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::RemoveMax()
{
    if(heapSize <= 0)
        return INT_MIN;
    if(heapSize == 1){
        --heapSize;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[heapSize - 1];
    --heapSize;

    MaxHeapify(0);

    return root;
}

void MaxHeap::DeleteKey(int i)
{
    IncreaseKey(i, INT_MAX);
    RemoveMax();
}

void MaxHeap::MaxHeapify(int i)
{
    int L = LChild(i);
    int R = RChild(i);
    int Largest = i;
    if(L < heapSize && arr[L] > arr[Largest])
        Largest = L;
    if(R < heapSize && arr[R] > arr[Largest])
        Largest = R;
    if(Largest != i)
    {
        swap(arr[i], arr[Largest]);
        MaxHeapify(Largest);
    }
}
int main()
{

    MaxHeap h(15);
    cout << "Enter 6 keys\n";
    for(int i = 0; i < 6;i++){
        int x;cin >> x;
        h.InsertKey(x);
    }

    cout << "The current Size of the heap is " << h.CurSize() << "\n";

    cout << "The current maximum element is " << h.GetMax() << "\n";

    h.DeleteKey(2);

    cout << "The current Size of the heap is " << h.CurSize() << "\n";

    h.InsertKey(15);
    h.InsertKey(5);

    cout << "The current Size of the heap is " << h.CurSize() << "\n";

    cout << "The current maximum element is " << h.GetMax() << "\n";

    return 0;
}