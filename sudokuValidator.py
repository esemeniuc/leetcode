import pprint

from typing import List


def isValidSudoku(self, a: List[List[str]]) -> bool:

    rowset = [False] * 10
    colset = [False] * 10
    boxset = [False] * 10

    for i in range(len(a)):
        for j in range(len(a[i])):
            if a[i][j] != '.':
                if rowset[int(a[i][j])]:
                    return False
                rowset[int(a[i][j])] = True
            if a[j][i] != '.':
                if colset[int(a[j][i])]:
                    return False
                colset[int(a[j][i])] = True
            ii = (i // 3) * 3 + j // 3
            jj = (i % 3) * 3 + j % 3
            if a[ii][jj] != '.':
                if boxset[int(a[ii][jj])]:
                    return False
                boxset[int(a[ii][jj])] = True

        rowset = [False] * 10
        colset = [False] * 10
        boxset = [False] * 10
    return True


assert (isValidSudoku(None,
                      [["5", "3", ".", ".", "7", ".", ".", ".", "."],
                       ["6", ".", ".", "1", "9", "5", ".", ".", "."],
                       [".", "9", "8", ".", ".", ".", ".", "6", "."],
                       ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
                       ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
                       ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                       [".", "6", ".", ".", ".", ".", "2", "8", "."],
                       [".", ".", ".", "4", "1", "9", ".", ".", "5"],
                       [".", ".", ".", ".", "8", ".", ".", "7", "9"]]))

#
# pprint.pprint(isValidSudoku())
