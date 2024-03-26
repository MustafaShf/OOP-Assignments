#include<iostream>
#include<fstream>
using namespace std;

// fstreambase
//ifstream   -->derived from fstreambase
//ofstream   -->derived from fstreambase

//open file
// 1-using constructer
// 2-using member func

class pointLess
{
    public:
    int row;
    int col;
    int **ptr;
    void nonSense(const string &file)
    {
        ifstream infile;
        infile.open(file);
        infile>>row>>col;
    ptr=new int*[row];
    for(int i=0;i<row;i++)
    {
        ptr[i]=new int[col];
    }
    //cout<<row<<Col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            infile>>ptr[i][j];
        }
    }
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
           cout<<ptr[i][j]<<" ";
        }
        cout<<"\n";
    }
    infile.close();


    }
};


int main()
{
   pointLess obj;
   obj.nonSense("file.txt");
   

    return 0;
}