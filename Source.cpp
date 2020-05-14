#include <iostream>
#include <ctime>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Matrix
{
private:

	int columns, lines;
    vector<vector<float>> matrix;

public:

	Matrix() {}

	void made_matrix()
	{
        cout << "Enter the number of lines <16" << endl;
        while (1)
        {
            cin >> lines;
            if (lines < 16 && lines > 0)
            {
                break;
            }
            else
            {
                cout << "Error, try again" << endl;
            }
        }

        cout << "Enter the number of columns <21" << endl;
        while (1)
        {
            cin >> columns;
            if (columns < 21 && columns > 0)
            {
                break;
            }
            else
            {
                cout << "Error, try again" << endl;
            }
        }

        
        for (int i = 0; i < lines; i++)
        {
            matrix.push_back(vector<float>()); 
            for (int j = 0; j < columns; j++)
            {
                matrix[i].push_back(rand() % 10); 
            }
        }
	}

};

int main()
{
    Matrix A;
    A.made_matrix();
    system("cls");

	return 0;
}