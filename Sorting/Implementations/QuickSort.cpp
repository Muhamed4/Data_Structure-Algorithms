#include <iostream>
#include <algorithm>
#include "QuickSort.h"

int DSA::Sort(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        do
        {
            ++i;
        } while (arr[i] <= pivot);

        do
        {
            --j;
        } while (arr[j] > pivot);
        if (i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);

    return j;
}

int DSA::SortV1(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    int pivot = arr[mid];
    int i = mid, j = high;
    while (i < j)
    {
        do
        {
            ++i;
        } while (arr[i] <= pivot);

        do
        {
            --j;
        } while (arr[j] > pivot);
        if (i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);

    return j;
}

int DSA::Partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int idx = low;
    for (int i = low; i <= high - 1; i++)
    {
        if (arr[i] <= pivot)
        {
            std::swap(arr[i], arr[idx]);
            ++idx;
        }
    }
    std::swap(arr[idx], arr[high]);
    return idx;
}

void DSA::QuickSortv01(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int PIndex = Partition(arr, low, high);
    QuickSortv01(arr, low, PIndex - 1);
    QuickSortv01(arr, PIndex + 1, high);
}

void DSA::QuickSort(int arr[], int low, int high)
{

    if (low >= high)
        return;
    int pivot = SortV1(arr, low, high);
    QuickSort(arr, low, pivot);
    QuickSort(arr, pivot + 1, high);
}