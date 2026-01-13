class Solution {
    public double separateSquares(int[][] squares) {

        int n = squares.length;

        double start = Double.MAX_VALUE;
        double end = Double.MIN_VALUE;

        double totalArea = 0.0;

        for (int[] sq : squares) {
            double y = sq[1];
            double l = sq[2];
            start = Math.min(start, y);
            end = Math.max(end, y + l);
            totalArea += l * l;
        }

        double halfArea = totalArea/2.0;
        for (int i = 0; i < 80; i++) { 
            double mid = (start + end) / 2.0;

            double area = 0.0;
            for (int[] sq : squares) {
                double yi = sq[1];
                double li = sq[2];
                double h = Math.max(0, Math.min(mid - yi, li));
                area += h * li;
            }

            if (area < halfArea) {
                start = mid;
            } else {
                end = mid;
            }
        }

        return start; 
    }
}
