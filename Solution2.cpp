#include <iostream>
using namespace std;

void fillarr(int rows, int *colCountArr, int **&ptr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colCountArr[i]; j++)
        {
            cout << "ptr[" << i << "][" << j << "]" << endl;
            cin >> *(*(ptr + i) + j);
        }
    }
}

void sort(int n, int *oneD)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (oneD[j] > oneD[j + 1])
            {
                // Swap elements
                int temp = oneD[j];
                oneD[j] = oneD[j + 1];
                oneD[j + 1] = temp;
            }
        }
    }
}
int twoDemToOneDem(int *oneD, int *colCountArr, int totalNumofCols, int rows, int **&ptr)
{

    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < *(colCountArr + i); j++)
        {
            *(oneD + k) = *(*(ptr + i) + j);
            k++;
        }
    }
    return k;
}
void showArr(int rows, int *colCountArr, int **&ptr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < *(colCountArr + i); j++)
        {

            cout << *(*(ptr + i) + j) << " ";
        }
        cout << endl;
    }
}
int main()
{
    int rows;
    int cols;
    int totalNumofCols = 0;
    cout << "Enter Number of rows: ";
    cin >> rows;
    int *colCountArr = 0;
    // store number of columns in a dynamic arr colcountArr
    colCountArr = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter Num of cols for row " << i << " : ";
        cin >> *(colCountArr + i);
        totalNumofCols += *(colCountArr + i);
    }
    // making a dynamic columns size array
    int **ptr = 0;
    ptr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        *(ptr + i) = new int[*(colCountArr + i)];
    }
    // filling the array
    fillarr(rows, colCountArr, ptr);
    showArr(rows, colCountArr, ptr);
    //---------One Dimension-------
    int *oneD = new int[totalNumofCols];
    int k = twoDemToOneDem(oneD, colCountArr, totalNumofCols, rows, ptr);
    //----------Sorting
    sort(totalNumofCols, oneD);
    //---------------------
    for (int i = 0; i < k; i++)
    {
        cout << *(oneD + i) << " ";
    }

    return 0;
}