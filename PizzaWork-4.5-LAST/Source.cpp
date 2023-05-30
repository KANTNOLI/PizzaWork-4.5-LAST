#include <iostream>
#include <string>

using namespace std;

//Создать функцию ArrayToMatrCol(A, K, M, N, B), формирующую по
//вещественному массиву A размера K матрицу B размера M x N(матрица
//заполняется элементами массива A по столбцам).«Лишние» элементы массива
//игнорируются; если элементов массива недостаточно, то оставшиеся элементы
//матрицы полагаются равными 0. Двумерный массив B является выходным
//параметром.С помощью этой функции на основе данного массива A размера K и
//целых чисел M и N сформировать матрицу B размера M x N

void ArrayToMatrCol(int* vector, int sizeVector, int** matrix, int matSizeX, int matSizeY) {
	int count = 0;
	for (int i = 0; i < matSizeY; i++)
	{
		for (int j = 0; j < matSizeX; j++) {
			if (count < sizeVector) {
				matrix[i][j] = vector[count]; 
				count++;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}

}

int main() {
	setlocale(LC_ALL, "RUS");
	int sizeVector;
	int matSizeX, matSizeY;
	int input;
	string msg = "Матрица: \n";
	cout << "Введите размер матрицы X - Y: ";
	cin >> matSizeX >> matSizeY; 

	int** matrix = new int* [matSizeY];
	for (int i = 0; i < matSizeY; i++) {
		matrix[i] = new int[matSizeX];
	}

	cout << "Введите размер массива для заполнения матрицы: ";
	cin >> sizeVector ;

	int* vector = new int[sizeVector];

	cout << "Введите элементы массива: ";
	for (int i = 0; i < sizeVector; i++) {
		cin >> vector[i];
	}

	ArrayToMatrCol(vector, sizeVector, matrix, matSizeX, matSizeY); 
	 
	for (int i = 0; i < matSizeY; i++) 
	{  
		for (int j = 0; j < matSizeX; j++) {  
			msg += to_string(matrix[i][j]) + "  ";  
		}
		msg += "\n"; 
	}

	cout << msg << endl; 

	return 0;
}