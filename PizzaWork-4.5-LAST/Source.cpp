#include <iostream>
#include <string>

using namespace std;

//������� ������� ArrayToMatrCol(A, K, M, N, B), ����������� ��
//������������� ������� A ������� K ������� B ������� M x N(�������
//����������� ���������� ������� A �� ��������).������� �������� �������
//������������; ���� ��������� ������� ������������, �� ���������� ��������
//������� ���������� ������� 0. ��������� ������ B �������� ��������
//����������.� ������� ���� ������� �� ������ ������� ������� A ������� K �
//����� ����� M � N ������������ ������� B ������� M x N

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
	string msg = "�������: \n";
	cout << "������� ������ ������� X - Y: ";
	cin >> matSizeX >> matSizeY; 

	int** matrix = new int* [matSizeY];
	for (int i = 0; i < matSizeY; i++) {
		matrix[i] = new int[matSizeX];
	}

	cout << "������� ������ ������� ��� ���������� �������: ";
	cin >> sizeVector ;

	int* vector = new int[sizeVector];

	cout << "������� �������� �������: ";
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