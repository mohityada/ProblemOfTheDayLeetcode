class Solution {
public:
    bool isPossible(int startRow, int startCol,int endRow, int endCol, vector<vector<int>>& grid) {

        int rowSum = 0, colSum = 0;
        int mainDiagSum = 0, antiDiagSum = 0;
        int targetSum = -1;

        // Check rows and columns
        for (int i = startRow; i <= endRow; i++) {
            for (int j = startCol; j <= endCol; j++) {
                rowSum += grid[i][j];
                colSum += grid[j - startCol + startRow]
                                 [i - startRow + startCol];
            }

            if (targetSum == -1) {
                targetSum = rowSum;
            } else if (rowSum != targetSum || colSum != targetSum) {
                return false;
            }

            rowSum = 0;
            colSum = 0;
        }

        // Check diagonals
        for (int i = startRow, j = startCol; i <= endRow; i++, j++) {
            mainDiagSum += grid[i][j];
            antiDiagSum += grid[i][endCol - j + startCol];
        }

        return mainDiagSum == targetSum &&
               antiDiagSum == targetSum;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();

        int maxSize = 1;
        int maxPossibleSize = min(totalRows, totalCols);

        for (int sizeOffset = 1; sizeOffset < maxPossibleSize; sizeOffset++) {
            bool found = false;

            for (int i = sizeOffset; i < totalRows; i++) {
                for (int j = sizeOffset; j < totalCols; j++) {
                    if (isPossible(i - sizeOffset, j - sizeOffset,
                                   i, j, grid)) {
                        maxSize = max(maxSize, sizeOffset + 1);
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        return maxSize;
    }
};
