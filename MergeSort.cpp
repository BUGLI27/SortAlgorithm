#include <vector>
#include <iostream>
using namespace std;

void Merge(int A[], int low, int mid, int high) {
    int i, j, k;
    int temp[high - low + 1];

    for (i = low, j = mid + 1, k = 0; i <= mid && j <= high; k++) {
        if (A[i] <= A[j])
            temp[k] = A[i++];
        else 
            temp[k] = A[j++];
    }
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= high)
        temp[k++] = A[j++];

    // 将temp赋值给原数组
    for (i = low, k = 0; i <= high; i++, k++)
        A[i] = temp[k];
}

void MergeSort(int A[], int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid); // 左部分归并排序
        MergeSort(A, mid+1, high); // 右部分归并排序
        Merge(A, low, mid, high); // 归并
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

    MergeSort(test, 0, n-1);

    // 排序后打印
    printNums(test, n);

    return 0;
}
