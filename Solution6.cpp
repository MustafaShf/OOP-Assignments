#include<iostream>
using namespace std;
int* len = nullptr;
string** createandpopulate(char *sen, int& rows)
{
    string** ptr = nullptr;
    rows = 0;
    for (int i = 0; *(sen+i)!='\0'; i++)
    {
        if (*(sen + i) == '#' || *(sen + i+1) == '\0')
            rows++;
    }
    ptr = new string * [rows] {nullptr};
    len = new int[rows] {0};
    int index = 0;
    int length = 0;
    for (int i = 0; *(sen + i) != '\0'; i++)
    {
        if (*(sen + i) == '#' || *(sen + i+1) == '\0')
        {    
            if (index >= 0 && index < rows) {
                *(ptr+index) = new string[length + 1];
               
                //cout << "Created one D of len " << length + 1 << endl;
                *(len+index) = length + 1;
                index++;
                length = 0;
            }
        }
        else if (*(sen + i) == ' ')
        {
            length++;
        }
    }
    index = 0;
    int j = 0;
    string value = "";
    for (int i = 0; *(sen + i) != '\0'; i++)
    {
        if (*(sen + i) == '#')
        {
            *(*(ptr+index)+j) = value;
            //cout << "copied at # "<<ptr[index][j] << endl;
            j=0;
            index++;
            value = "";
        }
        else if (*(sen + i+1) == '\0')
        {
            value += *(sen + i);
            *(*(ptr+index)+j)  = value;
            //cout << "copied at # "<<ptr[index][j] << endl;
            j=0;
            index++;
            value = "";
        }
        else if (*(sen + i) == ' ')
        {
            if (index >= 0 && index < rows) {
                *(*(ptr+index)+j)  = value;
                //cout << "copied at space " << ptr[index][j] << endl;
                j++;
                value = "";
            }
        }
        else
        {
            value += *(sen + i);
        }
    }
    return ptr;
}
int main()
{
    int row = 0;
    string checkSyno;
    char sen[200]="abandon discontinue vacate#absent missing unavailable#cable wire#calculate compute determine measure#safety security refuge";
    string **ptr= createandpopulate(sen, row);
    cout<<"Enter Word to search\n";
    cin>>checkSyno;
    for(int i=0;i<row;i++)
    {
        if(checkSyno==*(*(ptr+i)+0))
        {
            cout<<*(*(ptr+i)+(len[i]-1));
        }
    }
    for(int i=0;i<row;i++)
    {
        delete[]*(ptr+i);
        *(ptr+i)=nullptr;

    }
    delete[]ptr;
    delete[] len;
    len = nullptr;


    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < len[i]; j++)
    //     {
    //         cout << ptr[i][j]<<" ";
    //     }
    //     cout << endl;
    // }

}