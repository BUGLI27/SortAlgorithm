#include <vector>
#include <iostream>
using namespace std;

void DirectInsertSort(int A[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            int temp = A[i];
            for (j = i - 1; j >= 0 && A[j] > temp; j--)
            {
                A[j + 1] = A[j];
            }
            A[j + 1] = temp;
        }
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

    DirectInsertSort(test, n);

    // 排序后打印
    printNums(test, n);

    return 0;
}
