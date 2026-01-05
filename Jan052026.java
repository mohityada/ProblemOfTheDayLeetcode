class Jan052026 {
    public long maxMatrixSum(int[][] a) {
        int n = a.length;

        long sum = 0;
        int count_neg = 0, min_elem = 100000000;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] < 0){
                    count_neg++;
                }
                int element = Math.abs(a[i][j]);
                min_elem = Math.min(min_elem, element);
                sum += element;                
            }
        }
        if(count_neg%2 == 1) sum -= 2*min_elem;
        return sum;
    }
}
