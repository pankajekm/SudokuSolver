//Copyright (c) 2020, Pankaj Kumar G
//All rights reserved.
// SPDX-License-Identifier: BSD 3-Clause
#ifndef SUDOKUSOLVER_SUDOKUSOLVER_H
#define SUDOKUSOLVER_SUDOKUSOLVER_H

#include<iostream>
#include <fstream>
using namespace std;
class SudokuSolver {
public:
    SudokuSolver();
    int displayPuzzle();
    int displaySolutions();
    bool checkValidity(int x, int y, int value);
    bool isPuzzleSolved();
    int loadFile(string filename);
    int readPuzzle();
    bool solvePuzzle(int x);
    bool solver();
private:
     int puzzle[9][9];
     int solutions[10000][9][9];
     int num_solutions;
     int req_solutions;
    ifstream input;
    ofstream output;



};


#endif //SUDOKUSOLVER_SUDOKUSOLVER_H
