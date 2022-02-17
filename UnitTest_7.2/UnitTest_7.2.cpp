#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.2/lab_7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
  TEST_CLASS(UnitTest72)
  {
  public:
    
    TEST_METHOD(test_search)
    {
      const int rowsCount = 5;
      const int columnsCount = 5;

      int matrix[rowsCount][columnsCount] = {
        {-7,  7, -10,   5,   0},
        {-1,  5,  -5,  -4,  -5},
        { 5,  6,  -2, -10,   7},
        { 3, 10,   2,  -1,  -4},
        {-5,  4,   4,   8, -10},
      };

      int* matrixPointers[rowsCount] = {
        matrix[0],
        matrix[1],
        matrix[2],
        matrix[3],
        matrix[4],
      };

      int minOfMaxExpexcted = 4;
      int minOfMax;

      SearchMinOfMax(matrixPointers, rowsCount, columnsCount, minOfMax);

      Assert::AreEqual(minOfMaxExpexcted, minOfMax);
    }
  };
}
