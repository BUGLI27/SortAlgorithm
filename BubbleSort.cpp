#include <vector>
#include <iostream>
using namespace std;

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        bool flag = false; // 记录本趟冒泡是否发生交换
        for (int j = n - 1; j > i; j--) {
            if (A[j-1] > A[j]) {
                swap(A[j-1], A[j]);
                flag = true;
            }
        }
        // 若没发生交换，说明已有序
        if (!flag) 
            return;
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

    BubbleSort(test, n);

    // 排序后打印
    printNums(test, n);

    return 0;
}
