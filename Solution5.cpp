#include<iostream>
using namespace std;

char** personAConversation(char tokenz[][101],int &rows)
{
    int rowsOfA=0;
    int count=0;
    for(int i=0;i<rows;i++)
    {
        if(tokenz[i][0]=='A')
        {
            rowsOfA++;
        }
    }
    char **ptr=new char*[rowsOfA];
    int k=0;
    for(int i=0;i<rows;i++)
    {
        if(tokenz[i][0]=='A')
        {
            for(int j=1;tokenz[i][j] != '\0';j++)
            {
                if(tokenz[i][j]!=' ')
                {
                    count++;
                }
            }
            *(ptr+k)=new char[count+1];
            int m = 0;
            for (int j = 1; tokenz[i][j] != '\0'; j++) {
                if (tokenz[i][j] != ' ') {
                    ptr[k][m] = tokenz[i][j];
                    m++;
                }
            }
            ptr[k][m] = '\0'; 
            k++;
        }
    }
    rows=rowsOfA;
    return ptr;
    
    
    
}

int main() {
    char user;
    char sentence[101];
    char tokenz[101][101];
    int count = 0;
    char **ptr;

    while (true) {
        cout << "Which User A/B (Enter 'E' to exit): ";
        cin >> user;
        if (user == 'E')
            break;

        cout << "Sentence for " << user << ": ";
        cin.ignore(); 
        cin.getline(sentence, 101);

        tokenz[count][0] = user;
        for (int i = 0; sentence[i] != '\0'; i++) {
            tokenz[count][i + 1] = sentence[i]; 
        }

        count++;
    }
    ptr=personAConversation(tokenz,count);
    // Display the stored values
    for (int i = 0; i < count; i++) {
        for (int j = 0; ptr[i][j] != '\0'; j++) {
            cout << ptr[i][j];
        }
        cout << endl;
    }

    return 0;
}
