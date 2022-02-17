// Lab_7_2_1.cpp
// Кобетяк Андрій
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 12
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void fillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int Low, const int High
);
void Print(int** matrix, const int rowsCount, const int columnsCount);
void SearchMinOfMax(int** matrix, const int rowsCount, const int columnsCount, int& minOfMax);

int main()
{
  srand((unsigned)time(NULL));

  const int Low = -10;
  const int High = 10;

  int rowsCount;
  int columnsCount;

  cout << "Rows = "; cin >> rowsCount;
  cout << "Columns = "; cin >> columnsCount;

  int** matrix = new int* [rowsCount];
  for (int i = 0; i < rowsCount; i++)
      matrix[i] = new int[columnsCount];

  fillMatrix(matrix, rowsCount, columnsCount, Low, High);
  Print(matrix, rowsCount, columnsCount);

  int minOfMax;

  SearchMinOfMax(matrix, rowsCount, columnsCount, minOfMax);

  cout << "Min of Max in odd columns = " << minOfMax << endl;

  for (int i = 0; i < rowsCount; i++)
    delete[] matrix[i];

  delete[] matrix;

  return 0;
}

void fillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int Low, const int High
) {
  for (int row = 0; row < rowsCount; row++)
    for (int column = 0; column < columnsCount; column++)
      matrix[row][column] = Low + rand() % (High - Low + 1);
}

void Print(int** matrix, const int rowsCount, const int columnsCount)
{
  cout << endl;
  for (int row = 0; row < rowsCount; row++)
  {
    for (int column = 0; column < columnsCount; column++)
      cout << setw(4) << matrix[row][column];
    cout << endl;
  }
  cout << endl;
}

void SearchMinOfMax(
  int** matrix, 
  const int rowsCount, const int columnsCount, 
  int& minOfMax
) {
  for (int column = 0; column < columnsCount; column += 2) {
    int maxElement = matrix[0][column];

    for (int row = 1; row < rowsCount; row++) {
      if (maxElement < matrix[row][column])
        maxElement = matrix[row][column];
    }

    if (column == 0) {
      minOfMax = maxElement;
    }

    if (maxElement < minOfMax)
      minOfMax = maxElement;
  }
}