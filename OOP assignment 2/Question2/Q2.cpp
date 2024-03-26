#include<iostream>
#include<fstream>
using namespace std;
class SparseMatrix {
private:

	int rows; 
	int cols; // Number of columns in the matrix
	int** sparseMatrix; //Compressed Matrix

public:
	// Constructors
	SparseMatrix()
	{
		rows = 0;
		cols = 0;
		sparseMatrix = nullptr;
	}
	SparseMatrix(const string& file)
	{
		ifstream fileIn(file);
		int Mrows = 0;
		int Mcols = 0;
		fileIn >> Mrows;
		fileIn >> Mcols;
		int** Matrix;
		Matrix = new int* [Mrows];
		for (int i = 0; i < Mrows; i++)
		{
			Matrix[i] = new int[Mcols];
		}

		for (int i = 0; i < Mrows; i++)
		{
			for (int j = 0; j < Mcols; j++) {
				fileIn >> Matrix[i][j];
			}
		}
		int nonzero = 0;
		for (int i = 0; i < Mrows; i++)
		{
			for (int j = 0; j < Mcols; j++) {
				if (Matrix[i][j] != 0)
				{
					nonzero++;
				}
			}
		}
		sparseMatrix = new int* [3];
		for (int i = 0; i < 3; ++i)
		{
			sparseMatrix[i] = new int[nonzero];
		}

		int n = 0;
		for (int i = 0; i < Mrows; i++)
		{
			for (int j = 0;j < Mcols; j++)
			{
				if (Matrix[i][j] != 0)
				{
					sparseMatrix[0][n] = i;
					sparseMatrix[1][n] = j;
					sparseMatrix[2][n] = Matrix[i][j];
					n++;
				}
			}
		}
		rows = 3;
		cols = nonzero;
	}
	//copy Constructor
	SparseMatrix(const SparseMatrix& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		sparseMatrix = new int* [3];

		for (int i = 0; i < 3; ++i)
		{
			sparseMatrix[i] = new int[other.cols];
		}
		for (int i = 0; i < other.rows; i++)
		{
			for (int j = 0; j < other.cols; j++) {
				this->sparseMatrix[i][j] = other.sparseMatrix[i][j];
			}
		}
		
	}
    SparseMatrix operator=(const SparseMatrix other)

    {
            
        if (this == &other) {
            
            return *this;
        }

        
        for (int i = 0; i < rows; i++) {
            delete[] sparseMatrix[i];
        }
        delete[] sparseMatrix;

        
        rows = other.rows;
        cols = other.cols;

        
        sparseMatrix = new int*[3];
        for (int i = 0; i < 3; ++i) {
            sparseMatrix[i] = new int[cols];
        }

        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cols; j++) {
                sparseMatrix[i][j] = other.sparseMatrix[i][j];
            }
        }

        return *this;
}
    SparseMatrix operator+(const SparseMatrix other) const
    {
    int maxSize = this->cols + other.cols;
    int** resultMatrix = new int*[3];
    for (int i = 0; i < 3; ++i) {
        resultMatrix[i] = new int[maxSize];
    }

    int resultCount = 0; // Counts the number of non-zero entries in the result matrix

    int a = 0, b = 0; // Iterators for the two matrices

    
    while (a < this->cols && b < other.cols) {
        //  each matrix ka data store kiya taka aga compare karna ma istamal ho saka
        int rowA = this->sparseMatrix[0][a];
        int colA = this->sparseMatrix[1][a];
        int valA = this->sparseMatrix[2][a];

        int rowB = other.sparseMatrix[0][b];
        int colB = other.sparseMatrix[1][b];
        int valB = other.sparseMatrix[2][b];

        // is same then add both value
        if (rowA == rowB && colA == colB) {
            resultMatrix[0][resultCount] = rowA;
            resultMatrix[1][resultCount] = colA;
            resultMatrix[2][resultCount] = valA + valB;
            a++;
            b++;
            //agar rowA chotta ho OR agar same ha or colA chotta ho to A ka data copy karo
        } else if (rowA < rowB || (rowA == rowB && colA < colB)) {
            
            resultMatrix[0][resultCount] = rowA;
            resultMatrix[1][resultCount] = colA;
            resultMatrix[2][resultCount] = valA;
            a++;
        } else {
            
            resultMatrix[0][resultCount] = rowB;
            resultMatrix[1][resultCount] = colB;
            resultMatrix[2][resultCount] = valB;
            b++;
        }
        resultCount++;  // that will maintain col count
    }

    // Copy remaining elements from A oif after comparing b ends
    while (a < this->cols) {
        resultMatrix[0][resultCount] = this->sparseMatrix[0][a];
        resultMatrix[1][resultCount] = this->sparseMatrix[1][a];
        resultMatrix[2][resultCount] = this->sparseMatrix[2][a];
        a++;
        resultCount++;
    }
    // Copy remaining elements from B oif after comparing a ends
    while (b < other.cols) {
        resultMatrix[0][resultCount] = other.sparseMatrix[0][b];
        resultMatrix[1][resultCount] = other.sparseMatrix[1][b];
        resultMatrix[2][resultCount] = other.sparseMatrix[2][b];
        b++;
        resultCount++;
    }

    // Create the resulting SparseMatrix object
    SparseMatrix result;
    
    result.sparseMatrix = resultMatrix;  
    result.rows = 3;
    result.cols = resultCount;

    return result;

    }
    SparseMatrix operator-(const SparseMatrix& other) const
    {
        int maxSize = this->cols + other.cols;
    int** resultMatrix = new int*[3];
    for (int i = 0; i < 3; ++i) {
        resultMatrix[i] = new int[maxSize];
    }

    int resultCount = 0; // Counts the number of non-zero entries in the result matrix

    int a = 0, b = 0; // Iterators for the two matrices

    
    while (a < this->cols && b < other.cols) {
        //  each matrix ka data store kiya taka aga compare karna ma istamal ho saka
        int rowA = this->sparseMatrix[0][a];
        int colA = this->sparseMatrix[1][a];
        int valA = this->sparseMatrix[2][a];

        int rowB = other.sparseMatrix[0][b];
        int colB = other.sparseMatrix[1][b];
        int valB = other.sparseMatrix[2][b];

        // is same then add both value
        if (rowA == rowB && colA == colB) {
            resultMatrix[0][resultCount] = rowA;
            resultMatrix[1][resultCount] = colA;
            resultMatrix[2][resultCount] = valA - valB;
            a++;
            b++;
            //agar rowA chotta ho OR agar same ha or colA chotta ho to A ka data copy karo
        } else if (rowA < rowB || (rowA == rowB && colA < colB)) {
            
            resultMatrix[0][resultCount] = rowA;
            resultMatrix[1][resultCount] = colA;
            resultMatrix[2][resultCount] = valA;
            a++;
        } else {
            
            resultMatrix[0][resultCount] = rowB;
            resultMatrix[1][resultCount] = colB;
            resultMatrix[2][resultCount] = valB;
            b++;
        }
        resultCount++;  // that will maintain col count
    }

    // Copy remaining elements from A oif after comparing b ends
    while (a < this->cols) {
        resultMatrix[0][resultCount] = this->sparseMatrix[0][a];
        resultMatrix[1][resultCount] = this->sparseMatrix[1][a];
        resultMatrix[2][resultCount] = this->sparseMatrix[2][a];
        a++;
        resultCount++;
    }
    // Copy remaining elements from B oif after comparing a ends
    while (b < other.cols) {
        resultMatrix[0][resultCount] = other.sparseMatrix[0][b];
        resultMatrix[1][resultCount] = other.sparseMatrix[1][b];
        resultMatrix[2][resultCount] = other.sparseMatrix[2][b];
        b++;
        resultCount++;
    }

    // Create the resulting SparseMatrix object
    SparseMatrix result;
    
    result.sparseMatrix = resultMatrix;  
    result.rows = 3;
    result.cols = resultCount;

    return result;
    }
    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout<<sparseMatrix[i][j]<<" ";
            }
            cout<<endl;
            
        }
        
    }

	~SparseMatrix()
	{
		cout << "Destructer Called\n";
		for (int i = 0; i < rows; i++)
		{
			delete sparseMatrix[i];
			sparseMatrix[i] = nullptr;

		}
		sparseMatrix = nullptr;
	}
   
};
int main()
{
	const string filename = "file.txt";
    const string file2 = "file2.txt";
	SparseMatrix myMatrix(filename);
	SparseMatrix temp(myMatrix);
    SparseMatrix checkAsssignment(file2);
temp.display();
cout<<endl;
checkAsssignment.display();
    //checkAsssignment=temp;
    //checkAsssignment.display();
    SparseMatrix checkplusOP=temp+checkAsssignment;
    checkplusOP.display();
    SparseMatrix checkMinusOP=temp-checkAsssignment;
     checkMinusOP.display();
}
