#include <vector>
#include <iostream>
using namespace std;

void ShellSort(int A[], int n)
{
    int d, i, j;
    for (d = n / 2; d >= 1; d /= 2)
    {
        for (i = d; i < n; i++)
        {
            if (A[i] < A[i - d])
            {
                int temp = A[i];
                for (j = i - d; j >= 0 && A[j] > temp; j -= d)
                {
                    A[j + d] = A[j];
                }
                A[j + d] = temp;
            }
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

    ShellSort(test, n);

    // 排序后打印
    printNums(test, n);

    return 0;
}
