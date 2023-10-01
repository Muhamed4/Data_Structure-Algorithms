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
    maxSize = totSize;
    arr = new int[totSize];
}

void MaxHeap::InsertKey(int x)
{
    if (heapSize == maxSize)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    arr[i] = x;

    while (i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::IncreaseKey(int i, int newVal)
{
    arr[i] = newVal;
    while (i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::RemoveMax()
{
    if (heapSize <= 0)
        return INT_MIN;
    if (heapSize == 1)
    {
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
    if (L < heapSize && arr[L] > arr[Largest])
        Largest = L;
    if (R < heapSize && arr[R] > arr[Largest])
        Largest = R;
    if (Largest != i)
    {
        swap(arr[i], arr[Largest]);
        MaxHeapify(Largest);
    }
}

void swap(int *x, int *y);

class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:

    MinHeap(int capacity);

    void Heapify(int);

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getmin() { return harr[0]; }

    void deleteKey(int i);

    void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[capacity];
}

void MinHeap::insertKey(int k){
    if(heap_size == capacity){
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    ++heap_size;
    int i = heap_size - 1;
    harr[i] = k;

    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val){
    harr[i] = new_val;
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){
    if(heap_size <= 0)
        return INT_MAX;
    if(heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    Heapify(0);

    return root;
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::Heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l] < harr[i])
        smallest = l;
    if(r < heap_size && harr[r] < harr[i])
        smallest = r;
    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        Heapify(smallest);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{

    // MaxHeap h(15);
    // cout << "Enter 6 keys\n";
    // for (int i = 0; i < 6; i++)
    // {
    //     int x;
    //     cin >> x;
    //     h.InsertKey(x);
    // }

    // cout << "The current Size of the heap is " << h.CurSize() << "\n";

    // cout << "The current maximum element is " << h.GetMax() << "\n";

    // h.DeleteKey(2);

    // cout << "The current Size of the heap is " << h.CurSize() << "\n";

    // h.InsertKey(15);
    // h.InsertKey(5);

    // cout << "The current Size of the heap is " << h.CurSize() << "\n";

    // cout << "The current maximum element is " << h.GetMax() << "\n";


    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getmin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getmin();

    priority_queue<int>big;


    return 0;
}