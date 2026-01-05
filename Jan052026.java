class Jan052026 {
    public long maxMatrixSum(int[][] a) {
        int n = a.length;

        int sum = 0;
        int count_neg = 0, max_neg = -1000000;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] < 0){
                    count_neg++;
                    max_neg = Math.max(max_neg, a[i][j]);
                }
                sum += Math.abs(a[i][j]);
                if(a[i][j] == 0) max_neg = 0;
            }
        }

        if(count_neg%2 == 1) sum += 2*max_neg;

        return sum;
    }
}
