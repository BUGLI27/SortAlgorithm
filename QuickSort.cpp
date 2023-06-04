#include <vector>
#include <iostream>
using namespace std;

// 用第一个元素将待排序序列划分为左右两个部分
int Partition(int A[], int low, int high)
{
    int pivot = A[low]; // 第一个元素作为枢纽
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

// 快速排序
void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotPos = Partition(A, low, high);
        QuickSort(A, low, pivotPos - 1);
        QuickSort(A, pivotPos + 1, high);
    }
}

void printNums(int nums[], int n)
{
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main()
{
    int test[12] = {4, 2, 7, 10, 3, 9, 100, 64, 77, 92, 101, 50};

    int n = sizeof(test) / sizeof(test[0]);

    // 排序前打印
    printNums(test, n);

    QuickSort(test, 0, n - 1);

    // 排序后打印
    printNums(test, n);

    return 0;
}
