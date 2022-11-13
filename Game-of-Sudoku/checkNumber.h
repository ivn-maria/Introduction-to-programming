#ifndef UNTITLED_CHECKNUMBER_H
#define UNTITLED_CHECKNUMBER_H

bool checkNumber (int sudoku[9][9], int row, int column, int number) {
    if (row < 0 || row > 9 || column < 0 || column > 9 || number < 0 || number > 9)
        return false;

    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == number || sudoku[row][i] == number * (-1)) {
            return false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (sudoku[i][column] == number || sudoku[i][column] == number * (-1)) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startColumn = column - column % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[i + startRow][j + startColumn] == number)
                return false;
            if (sudoku[i + startRow][j + startColumn] == number * (-1))
                return false;
        }
    }

    return true;
}


#endif //UNTITLED_CHECKNUMBER_H
