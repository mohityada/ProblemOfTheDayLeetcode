class Jan122026 {
    public int minTimeToVisitAllPoints(int[][] points) {
        int n = points.length;
        int ans = 0;
        for(int i = 1; i < n; i++){
            int x = Math.abs(points[i-1][0] - points[i][0]);
            int y = Math.abs(points[i-1][1] - points[i][1]);
            ans += Math.min(x, y);
            ans += Math.abs(x-y);
        }
        return ans;
    }
}
