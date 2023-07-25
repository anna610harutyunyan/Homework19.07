#include <iostream>
template <typename T>
class Matrix
{
	int m_columns;
	int m_rows;
	T** array = nullptr;
public:
	Matrix<T>()
	{
		std::cout << "Call default constructor " << std::endl;
	}

	Matrix<T>(const Matrix<T>& obj)
	{
		this->m_columns = obj.m_columns;
		this->m_rows = obj.m_rows;
		array = new T * [m_rows];
		for (int i = 0; i < m_columns; ++i)
		{
			array[i] = new T[m_columns];
			for (int j = 0; j < m_columns; ++j)
			{
				array[i][j] = obj.array[i][j];
			}
		}
		std::cout << "Call copy constructor " << std::endl;
	}
	Matrix<T>& operator =(const Matrix<T>& obj)
	{
		if (this != &obj)
		{
			for (int i = 0; i < m_rows; ++i)
			{
				delete[] array[i];
			}
			delete[] this->array;
			this->m_columns = obj.m_columns;
			this->m_rows = obj.m_rows;
			array = new T * [m_rows];
			for (int i = 0; i < m_columns; ++i)
			{
				array[i] = new T[m_columns];
				for (int j = 0; j < m_columns; ++j)
				{
					array[i][j] = obj.array[i][j];
				}
			}
			return *this;
		}

		std::cout << "Call operator assignment " << std::endl;
	}
	Matrix<T>(int columns, int rows) :m_columns(columns), m_rows(rows)
	{
		array = new T* [rows];
		for (int i = 0; i < rows; ++i)
		{
			array[i] = new T[columns];
		}
		std::cout << "Call parametrized constructor " << std::endl;
	}
	Matrix<T>(Matrix<T>&& obj)
	{
		this->m_columns = obj.m_columns;
		this->m_rows = obj.m_rows;
		this->array = obj.array;
		obj.m_columns = 0;
		obj.m_rows = 0;
		obj.array = nullptr;
		std::cout << "Call move constructor " << std::endl;

	}
	Matrix<T>& operator =(Matrix<T>&& obj)
	{
		if (this->array != obj.array)
		{
			for (int i = 0; i < m_rows; ++i)
			{
				delete[] array[i];
			}
			delete[] this->array;
			this->m_columns = obj.m_columns;
			this->m_rows = obj.m_rows;
			this->array = obj.array;
			obj.m_columns = 0;
			obj.m_rows = 0;
			obj.array = nullptr;
			std::cout << "Call move operator assignment " << std::endl;

			return *this;
		}
		std::cout << "Call move operator assignment " << std::endl;
		return *this;
	}
	~Matrix()
	{
		std::cout << "Call destructor " << std::endl;
		for (int i = 0; i < m_rows; ++i)
		{
			delete[] array[i];
		}
		delete[] array;
		array = nullptr;

	}

};

int main(int argc, char** argv)
{
	Matrix<char> obj1;
	Matrix<double> obj2;

	return 0;
}