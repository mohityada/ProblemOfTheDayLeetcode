class Solution {
public:
    bool isPossible(int startRow, int startCol, int endRow, int endCol, vector<vector<int>>& grid) {

        int rowSum = 0, colSum = 0, diagSum = 0;
        int targetSum = -1;

        // Check rows
        for (int i = startRow; i <= endRow; i++) {
            for (int j = startCol; j <= endCol; j++) {
                rowSum += grid[i][j];
            }

            if (targetSum == -1) {
                targetSum = rowSum;
            } else if (rowSum != targetSum) {
                return false;
            }
            rowSum = 0;
        }

        // Check columns
        for (int j = startCol; j <= endCol; j++) {
            for (int i = startRow; i <= endRow; i++) {
                colSum += grid[i][j];
            }
            if (colSum != targetSum) return false;
            colSum = 0;
        }

        // Main diagonal
        for (int i = startRow, j = startCol; i <= endRow; i++, j++) {
            diagSum += grid[i][j];
        }
        if (diagSum != targetSum) return false;

        // Anti-diagonal
        diagSum = 0;
        for (int i = startRow, j = endCol; i <= endRow; i++, j--) {
            diagSum += grid[i][j];
        }
        if (diagSum != targetSum) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxSize = 1;
        int limit = min(rows, cols);

        for (int size = 1; size < limit; size++) { // size = 1 -> 2x2
            bool found = false;

            for (int i = size; i < rows; i++) {
                for (int j = size; j < cols; j++) {
                    if (isPossible(i - size, j - size, i, j, grid)) {
                        maxSize = max(maxSize, size + 1);
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
