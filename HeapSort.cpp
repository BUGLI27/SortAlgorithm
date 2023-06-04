#include <vector>
#include <iostream>
using namespace std;

// 维护堆的性质
// 维护下标为i的节点为大根堆
void heapify(int A[], int n, int i) {
    int largest = i;
    int lson = i * 2 + 1;
    int rson = i * 2 + 2;
    if (lson < n && A[lson] > A[largest])
        largest = lson;
    if (rson < n && A[rson] > A[largest])
        largest = rson;
    // 节点发生改变
    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void HeapSort(int A[], int n)
{
    // 建堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    
    // 排序
    for (int i = n - 1; i > 0; i--) {
        swap(A[i], A[0]);
        heapify(A, i, 0);
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

    HeapSort(test, n);

    // 排序后打印
    printNums(test, n);

    return 0;
}
