#include <iostream>
#include <ctime>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<vector<float>> matrix;
// Абстрактный класс
class Matrix
{
public:
    // чисто виртуальная функиция
    virtual void show_matrix() = 0;
    // Деструктор
    ~Matrix(){}
};
// Класс "исходная матрица"
class SourceMatrix : public Matrix
{
private:
    int columc_end, lines;
    
public:
    // Конструктор по умолчанию
    SourceMatrix()
	{
		columc_end = 2;
		lines = 2;
	}
    // Метод
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

        cout << "Enter the number of columc_end <21" << endl;
        while (1)
        {
            cin >> columc_end;
            if (columc_end < 21 && columc_end > 0)
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
            for (int j = 0; j < columc_end; ++j)
            {
                matrix[i].push_back(rand() % 10); 
            }
        }
	}
    // Метод (оверрайд для виртуальной функции) 
    void show_matrix() override
    {
        cout << "----Source matrix----";
        for (int i = 0; i < lines; ++i)
        {
            cout << endl;
            for (int j = 0; j < columc_end; ++j)
            {
                cout << matrix[i][j] << "  ";
            }
        }
    }
    // Деструктор
    ~SourceMatrix() {}
};

// Класс изм. матрицы
class TransMatrix : public SourceMatrix
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
            cout << endl << "Enter the start of the columc_end spacing..." << endl;
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
    // Метод (оверрайд для вирутальной фукнции)
    void show_matrix() override
    {
        cout << endl << "---Transformed matrix---";
        for (int i = l_start - 1; i < l_end; ++i)
        {
            cout << endl;
            for (int j = c_start - 1; j < c_end; ++j)
            {
                cout << matrix[i][j] << "  ";
            }
        }
    } 
    
    void mathexp()
    {
        int average, sh = 0, sum = 0;
        for (int i = l_start - 1; i < l_end; ++i)
        {
            for (int j = c_start - 1; j < c_end; ++j)
            {
                sh++;
                sum += matrix[i][j];
            }
        }
        average = sum / sh;
        cout << endl << endl << "Mathexp: " << average;
    }
    
    void finding_mode() 
    {
        vector<float> vec;
        int k = -1;
        float maxValue = 0, maxCount = -1;
        for (int j = l_start - 1; j <= l_end - 1; ++j)
        {
            for (int i = c_start - 1; i <= c_end - 1; ++i)
            {
                k++;
                vec.push_back(matrix[i][j]);
            }
        }

        for (int i = 0; i < k; ++i)
        {
            int count = 0;
            for (int j = 0; j < k; ++j)
            {
                if (vec[j] == vec[i])
                    ++count;
            }
            if (count > maxCount)
            {
                maxCount = count;
                maxValue = vec[i];
            }
        }
        cout <<  endl <<  "Mode: " << maxValue;
    }
    // Деструктор
    ~TransMatrix() {}
};
// класс для вывода матриц (полиморфизм)
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
    TransMatrix trabs_matrix;
    trabs_matrix.line_spacing();
    system("cls");
    print.show_matrix(&source_matrix);
    print.show_matrix(&trabs_matrix);
    trabs_matrix.mathexp();
    trabs_matrix.finding_mode();

    return 0;
}