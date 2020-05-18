#include <iostream>
#include <ctime>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


vector<vector<float>> matrix;
class Matrix
{
public:
    virtual void show_matrix() = 0;

    ~Matrix(){}
};

class SourceMatrix : public Matrix
{
private:
    int columns, lines;
    
public:
    SourceMatrix()
	{
		columns = 2;
		lines = 2;
	}

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

        srand(time(NULL));

        for (int i = 0; i < lines; i++)
        {
            matrix.push_back(vector<float>()); 
            for (int j = 0; j < columns; j++)
            {
                matrix[i].push_back(rand() % 10); 
            }
        }
	}

    void show_matrix() override
    {
        cout << "----Source matrix----";
        for (int i = 0; i < lines; i++)
        {
            cout << endl;
            for (int j = 0; j < columns; j++)
            {
                cout << matrix[i][j] << "\t";
            }
        }
    }

    ~SourceMatrix() {}
};


class TransMatrix : public Matrix
{
private:
    int l_start, l_end, c_start, c_end;

public: 
    TransMatrix() 
    {
        l_start = 1;
        l_end = 1;
        c_start = 1;
        c_end = 1;
    }

    void line_spacing()
    {

        while (1)
        {
            cout << endl << "Enter the start of the line spacing..." << endl;
            cin >> l_start;
            if (l_start > 0)
            {
                break;
            }
            else
            {
                cout << "Error" << endl;
            }
        }

        while (1)
        {
            cout << endl << "Enter the end of the line spacing..." << endl;
            cin >> l_end;
            if (l_end > 0 && l_end >= l_start)
            {
                break;
            }
            else
            {
                cout << "Error" << endl;
            }
        }

        while (1)
        {
            cout << endl << "Enter the start of the columns spacing..." << endl;
            cin >> c_start;
            if (c_start > 0)
            {
                break;
            }
            else
            {
                cout << "Error" << endl;
            }
        }

        while (1)
        {
            cout << endl << "Enter the end of the line spacing..." << endl;
            cin >> c_end;
            if (c_end > 0 && c_end >= c_start)
            {
                break;
            }
            else
            {
                cout << "Error" << endl;
            }
        }
    }

    void show_matrix() override
    {
        cout << endl << "---Transformed matrix---";
        for (int i = l_start - 1; i < l_end; i++)
        {
            cout << endl;
            for (int j = c_start - 1; j < c_end; j++)
            {
                cout << matrix[i][j] << "\t";
            }
        }
    } 

    ~TransMatrix() {}
};

class Display
{
public:
    void show_matrix(Matrix* print)
    {
        print->show_matrix();
    }
};

int main()
{
    Display print;
    SourceMatrix source_matrix;
    source_matrix.made_matrix();
    print.show_matrix(&source_matrix);
    TransMatrix trans_matrix;
    trans_matrix.line_spacing();
    system("cls");
    print.show_matrix(&source_matrix);
    print.show_matrix(&trans_matrix);
  
	return 0;
}