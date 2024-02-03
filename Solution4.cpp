#include<iostream>
using namespace std;

int **getDivisors(int arr[],int n)
{
    int count=0;
    int **ptr=0;
    ptr=new int*[n];
    int *storeCount=0;
    storeCount=new int[n];
    int z=0;
    for(int i=0;i<n;i++)
    {
        count=0;
        for(int j=2;j<arr[i];j++)
        {
            if(arr[i]%j==0)
            {
                count++;

            }
        }
        *(ptr+i)=new int[count+1];
        storeCount[z]=count;
        z++;
        int k=0;
        for(int j=2;k<count;j++)
        {
            if(arr[i]%j==0)
            {
                ptr[i][k]=j;
                k++;

            }
        }
        ptr[i][k]=-1;
    }
    

 return ptr;       
}
void printDivisorArr(int **ptr,int n)
{
    for(int i=0;i<n;i++)
    {
        int j=0;
        while(true)
        {
            cout<<ptr[i][j]<<" ";
            if(*(*(ptr+i)+j)==-1) break;
            j++;
        }
        
        cout<<endl;
    }
}

int main()
{
    int n=5;
    int divisorArr[5]={5,12,15,20,27};
    int **ptr=getDivisors(divisorArr,n);
    printDivisorArr(ptr,n);


    return 0;
}
