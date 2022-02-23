// Lab_7_2_1.cpp
// Кобетяк Андрій
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void fillMatrix (
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int Low, const int High,
  const int currentRow
);

void fillMatrixRow (
  int** matrix,
  const int columnsCount,
  const int Low, const int High,
  const int currentRow, const int currentColumn
);

void Print(
  int** matrix,
  const int rowsCount, const int columnsCount, 
  const int currentRow
);

void PrintRow(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn
);

void SearchMinOfMax (
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int currentRow,
  int& minOfMax
);

void SearchMaxInColumn (
  int** matrix,
  const int rowsCount,
  const int currentRow, const int currentColumn,
  int& maxElement
);

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

  fillMatrix(matrix, rowsCount, columnsCount, Low, High, 0);

  Print(matrix, rowsCount, columnsCount, 0);

  int minOfMax;

  SearchMinOfMax(matrix, rowsCount, columnsCount, 0, minOfMax);

  cout << "Min of Max in odd columns = " << minOfMax << endl;

  for (int i = 0; i < rowsCount; i++)
    delete[] matrix[i];

  delete[] matrix;

  return 0;
}

void fillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int Low, const int High,
  const int currentRow
) {
  fillMatrixRow(matrix, columnsCount, Low, High, currentRow, 0);
  if (currentRow < rowsCount - 1) {
    fillMatrix(matrix, rowsCount, columnsCount, Low, High, currentRow + 1);
  }
}

void fillMatrixRow(
  int** matrix,
  const int columnsCount,
  const int Low, const int High,
  const int currentRow, const int currentColumn
) {
  matrix[currentRow][currentColumn] = Low + rand() % (High - Low + 1);

  if (currentColumn < columnsCount - 1) {
    fillMatrixRow(matrix, columnsCount, Low, High, currentRow, currentColumn + 1);
  }
}

void Print(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int currentRow
) {
  PrintRow(matrix, columnsCount, currentRow, 0);

  if (currentRow < rowsCount - 1) {
    Print(matrix, rowsCount, columnsCount, currentRow + 1);
  } else {
    cout << endl;
  }
}

void PrintRow(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn
) {
  cout << setw(4) << matrix[currentRow][currentColumn];

  if (currentColumn < columnsCount - 1) {
    PrintRow(matrix, columnsCount, currentRow, currentColumn + 1);
  } else {
    cout << endl;
  }
}

void SearchMinOfMax(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int currentColumn,
  int& minOfMax
) {
  int maxElement = matrix[0][currentColumn];

  SearchMaxInColumn(matrix, rowsCount, 0, currentColumn, maxElement);

  if (currentColumn == 0) {
    minOfMax = maxElement;
  }

  if (maxElement < minOfMax) {
    minOfMax = maxElement;
  }

  if (currentColumn < columnsCount - 1) {
    SearchMinOfMax(matrix, rowsCount, columnsCount, currentColumn + 2, minOfMax);
  }
}

void SearchMaxInColumn(
  int** matrix,
  const int rowsCount,
  const int currentRow, const int currentColumn,
  int& maxElement
) {
  if (maxElement < matrix[currentRow][currentColumn])
    maxElement = matrix[currentRow][currentColumn];

  if (currentRow < rowsCount - 1) {
    SearchMaxInColumn(matrix, rowsCount, currentRow + 1, currentColumn, maxElement);
  }
}