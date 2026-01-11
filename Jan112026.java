class Jan112026 {

    int area(int[] a) {
        int n = a.length;
        int i = 0;
        Stack<Integer> st = new Stack<>();
        int maxArea = 0;

        while (i < n) {
            while (!st.isEmpty() && a[st.peek()] > a[i]) {
                int idx = st.pop();
                int width = st.isEmpty() ? i : i - 1 - st.peek();
                maxArea = Math.max(maxArea, width * a[idx]);
            }
            st.push(i);
            i++;
        }

        while (!st.isEmpty()) {
            int idx = st.pop();
            int width = st.isEmpty() ? i : i - 1 - st.peek();
            maxArea = Math.max(maxArea, width * a[idx]);
        }

        return maxArea;
    }

    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int[] heights = new int[m];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            ans = Math.max(ans, area(heights));
        }

        return ans;
    }
}
