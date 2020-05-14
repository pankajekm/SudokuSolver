//Copyright (c) 2020, Pankaj Kumar G
//All rights reserved.
// SPDX-License-Identifier: BSD 3-Clause

#include "SudokuSolver.h"
SudokuSolver::SudokuSolver()
{


}
bool  SudokuSolver::checkValidity(int x, int y, int value) {
    int i,j;
    for(i=0;i<9;i++) {
        if (puzzle[i][y] == value) return false;
        if (puzzle[x][i] == value) return false;
    }
    for(i=(x/3)*3;i<(x/3)*3+3;i++) {


        for(j=(y/3)*3;j<(y/3)*3+3;j++) {
            //cout<<i<<" "<<j<<" "<<puzzle[i][j]<<endl;
            if (puzzle[i][j] == value) return false;

        }
    }
    return true;
}

int SudokuSolver::displaySolutions() {
    int i,j,k;
    cout<<endl;
    for(k=0;k<num_solutions;k++)
    {
        cout<<"Solution No: "<<k+1<<endl;

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
            cout<<solutions[k][i][j]<<" ";
        cout<<endl;

    }

    cout<<endl;
    }
    return  0;
}
int SudokuSolver::displayPuzzle() {
    int i,j;
    cout<<endl;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
            cout<<puzzle[i][j]<<" ";
        cout<<endl;

    }
    cout<<endl;
return  0;
}
bool  SudokuSolver::isPuzzleSolved() {

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if (puzzle[i][j]==0)
                return false;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            solutions[num_solutions][i][j]=puzzle[i][j];
    if (req_solutions==0)
    {

            num_solutions++;
            return false;

    }
    return true;
}
int SudokuSolver::loadFile(string filename="input.txt")
{
 input.open(filename);
return 0;
}
int SudokuSolver::readPuzzle()
{
    string line;
    if (input.is_open())
    {
       if ( getline (input,line) )
        {
            for(int i=0;i<line.size();i++)
                puzzle[i/9][i%9]=line[i]-'0';
        }
       else
        input.close();
    }
    else cout << "Unable to open file";
    return 0;
}
bool SudokuSolver::solver()
{
    int i,j,value;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if (puzzle[i][j]!=0) continue;
            for(value=1;value<10;value++)
            {
                if(checkValidity(i, j, value)) {
                    puzzle[i][j]=value;
                    if(isPuzzleSolved())
                        return true;
                    else
                    {
                        if(solver())
                            return true;


                    }

                    puzzle[i][j]=0;

                }
            }
            return false;

        }

    }

    return false;

}
bool SudokuSolver::solvePuzzle(int x) {
    num_solutions=0;
    req_solutions=x;
    return solver();

}