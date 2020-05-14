#include <iostream>
#include <chrono>
using namespace std::chrono;
#include "SudokuSolver.h"
int main() {
    SudokuSolver solver;
    solver.loadFile("../input.txt");
    solver.readPuzzle();
    solver.displayPuzzle();
    auto start = high_resolution_clock::now();
    solver.solvePuzzle(0);
    auto stop = high_resolution_clock::now();
    solver.displaySolutions();
    //solver.checkValidity(0,7,6);
    auto duration = duration_cast<seconds>(stop - start);

// To get the value of duration use the count()
// member function on the duration object
    cout << duration.count() << endl;

    return 0;
}
