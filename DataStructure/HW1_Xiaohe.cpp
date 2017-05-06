#include <iostream>

using namespace std;

class MatrixDeterminant
{
	public:
	MatrixDeterminant();
	MatrixDeterminant(int*, int);
	void printMatrxi();
	int getDeterminant();
	private:
	int count;
	int* matrix;
	int calculateDeterminant(int* , int);
};

MatrixDeterminant::MatrixDeterminant(int* matrix_arg, int count_arg) {
	count = count_arg;
	matrix = matrix_arg;
}

void MatrixDeterminant::printMatrxi() {
	cout << endl;
	cout << "The input matrix is: " << endl;
	for (int height = 0; height < count; height++) {
		cout << "| ";
		for (int width = 0; width < count; width++) {
			cout << *(matrix + height * count + width) << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}
int MatrixDeterminant::getDeterminant() {
	return calculateDeterminant(matrix, count);
}
int MatrixDeterminant::calculateDeterminant(int *matrix, int count) {
	int result = 0;
	// If there is only one number in matrix that number is determinant
	if (count == 1) {
		result = *matrix;
		return result;
	}
	// If the size of matrix is 2 then do the calculation
	if (count == 2) {
		result = *(matrix) * *(matrix + 2 + 1) - *(matrix + 1) * *(matrix + 2);
		return result;
	}
	else {
		// If the size of matrix is greater than 2 then do the recursion
		// Get the first row of matrix
		int firstRow[count];
		int nextLevel = count - 1;
		int nextMatrix[nextLevel][nextLevel];
		for (int i = 0; i < count; i++) {
			firstRow[i] = *(matrix + i);
		}
		// Create the next level matrix and use it to calculate the determinant
		for (int i = 0; i < count; i++) {
			int prefix = 0;
			if (i % 2 == 0) {
				prefix = 1;
			}
			else {
				prefix = -1;
			}
			
			for (int height = 0; height < nextLevel; height++) {
				for (int width = 0; width < nextLevel; width++) {
					if (width < i) {
						nextMatrix[height][width] = *(matrix + (height + 1) * count + width);
					}
					else {
						nextMatrix[height][width] = *(matrix + (height + 1) * count + width + 1);
					}
				}
			}
		
			result = result + prefix * firstRow[i] * calculateDeterminant(nextMatrix[0], count - 1);
		}
		return result;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int level;
	cout << "Please in put number of elements on a side:" << endl;
	cin >> level;
	if (!cin.eof() && cin.good()) {
		// Create the 2 dimentional array
		int matrix[level][level];
		int input;
		
		for (int height = 0; height < level; height++) {
			
			for (int width = 0; width < level; width++) {
				cout << "Please input No." << height + 1 << " row's No." << width + 1 << " element:" << endl;
				cin >> input;
				if (!cin.eof() && cin.good()) {
					matrix[height][width] = input;
				}
				else {
					cout << "Get a wrong type value! Program is terminated.";
					return 0;
				}
			}
		}
	
	MatrixDeterminant *determinant = new MatrixDeterminant(matrix[0], level);
	determinant->printMatrxi();
	int ans = determinant->getDeterminant();
	cout << ans << endl;
	}
	else {
		return 0;
	}
}