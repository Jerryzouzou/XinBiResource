#ifndef __ZIGZAGPRINTMATRIX_H__
#define __ZIGZAGPRINTMATRIX_H__

using namespace std;
void printMatrixZigZag(vector<vector<int> > matrix);
void printLevel(vector<vector<int> > matrix, int tR, int tC, int dR, int dC, bool fromUp);
void printMatrixZigZag_main();

#endif
