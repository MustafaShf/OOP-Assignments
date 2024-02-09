#include <iostream>
using namespace std;
const int cols=5;
int *countCols=0;
void createandpopulate(int scores[][cols],int rows,int** &ptr)
{
    ptr=new int*[rows];
    countCols=new int[rows];
    
    int count=0;
    int index=0;
    for(int i=0;i<cols;i++)
    {
        count=0;
        for(int j=0;j<rows;j++)
        {
            if(scores[j][i]>=300)
            {
                count++;
            }
        }
        countCols[index]=count+1;
        *(ptr+i)=new int[count+1];
        index++;

        //cout<<count+1<<" ";
    }
    int l=0;
    int m=0;
    for(int i=0;i<cols;i++)
    {
        m=0;
        for(int j=0;j<rows;j++)
        {
            
            if(scores[j][i]>=300)
            {
                ptr[l][m]=scores[j][i];
                m++;
            }

        }
        ptr[l][m]=-1;
        l++;
    }
    
}

int main() {

    const int rows = 5; 
    //const int cols = 5; 
    int **acheivers=nullptr;
    
    int scores[rows][cols] = {
        {198, 352, 240, 286, 332}, // Australia
        {357, 281, 290, 392, 218}, // England
        {249, 408, 374, 346, 341}, // India
        {426, 451, 160, 132, 412}, // Pakistan
        {186, 195, 248, 482, 486}  // New Zealand
    };

    createandpopulate(scores,rows,acheivers);
for(int i=0;i<rows;i++)
{
    for(int j=0;j<countCols[i];j++)
    {
        cout<<acheivers[i][j]<<" ";
    }
    cout<<endl;
}
    return 0;
}
