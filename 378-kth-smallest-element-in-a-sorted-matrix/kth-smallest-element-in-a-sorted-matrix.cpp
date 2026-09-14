class Solution {
public:

    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int count = 0;

        int row = 0;
        int col = n - 1;

        // Start from top-right
        while (row < n && col >= 0) {

            if (matrix[row][col] <= mid) {
                // Entire row from 0 to col is <= mid
                count += col + 1;
                row++;
            }
            else {
                col--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while (low < high) {

            int mid = low + (high - low) / 2;

            int count = countLessEqual(matrix, mid);

            if (count >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};