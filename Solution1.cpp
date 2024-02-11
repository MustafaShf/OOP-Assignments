#include<iostream>
using namespace std;

void createandpopulate(int arr[][6], int row, int col, int **&ptr)
{
    
    ptr=new int*[row];
    int count;
    for(int i=0;i<row;i++)
    {
        count=0;
        for(int j=0;j<col;j++)
        {
            if(*(*(arr+i)+j)!=0)
            {
                count++;
            }
        }
        //cout<<"this is count"<<count<<endl;
        *(ptr + i)=new int[count+1];
        *(*(ptr+i)+0)=count;
        for(int k=1,j=0;k<=count;j++)
        {
            if(*(*(arr+i)+j)!=0)
            {
                *(*(ptr+i)+k)=*(*(arr+i)+j);
                k++;
            }
        }
    }
    
}

int main()
{
    int **ptr = 0;
    int rows = 5;
    int cols=6;
    int arr[5][6] = {
        {2, 3, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 2, 0, 2},
        {5, 0, 0, 0, 10, 0}
    };
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------------"<<endl;
    createandpopulate(arr,rows,cols,ptr);
    for(int i=0;i<rows;i++)
    {
        for(int j=1;j<=*(*(ptr+i)+0);j++)
        {
            cout<<*(*(ptr+i)+j)<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<rows;i++)
    {
        delete[] *(ptr + i); 
        ptr[i] = nullptr;
    }
    delete []ptr;
    return 0;
}