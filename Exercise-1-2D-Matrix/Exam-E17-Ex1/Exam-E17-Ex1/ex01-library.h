#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_


#include <vector>
#include <string>


// To abbreviate declarations
typedef unsigned int UINT;


int ** createMatrix(UINT n, UINT m);
int ** duplicateMatrix(int** A, UINT n, UINT m);
int ** makeBitonal(int** A, UINT n, UINT m, int threshold);
void initMatrix(int** A, UINT n, UINT m);
void deallocateMatrix(int** A, unsigned int n);
void printMatrix(int** A, UINT n, UINT m, std::string description);


#endif