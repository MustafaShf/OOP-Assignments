#include<iostream>
using namespace std;

int** compress(int**image, int rows, int cols, int value)
{
    int count=0;
    int **ptr=nullptr;
    ptr=new int*[rows];
    for(int i=0;i<rows;i++)
    {
        count=0;
        for(int j=0;j<cols;j++)
        {
            if(image[i][j]==value)
            {
                count++;
            }
        }
        *(ptr+i)=new int[count+1];
        *(*(ptr+i)+0)=count;
        for(int k=1,j=0;k<=count;j++)
        {
            if(*(*(image+i)+j)==value)
            {
                *(*(ptr+i)+k)=j;
                k++;
            }
        }

    }
    return ptr;
}

int main()
{
    int **image = 0;
    int **compImgPtr=nullptr;
    int rows = 5;
    int cols=5;
    int value;
    int imageData[5][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1}
    };
    
    image = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        image[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            image[i][j] = imageData[i][j];
        }
    }
    cout<<"Enter Value 0 or 1: ";
    cin>>value;
    compImgPtr=compress(image,rows,cols,value);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<=compImgPtr[i][0];j++)
        {
            cout<<compImgPtr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}