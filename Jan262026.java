class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int n = arr.length;

        Arrays.sort(arr);

        int minDiff = Integer.MAX_VALUE;;
        for(int i = 1; i < n; i++){
            int b = arr[i];
            int a = arr[i-1];
            minDiff = Math.min(minDiff, b-a);
        }
        List<List<Integer>> finalList = new ArrayList<>();
        for(int i = 1; i < n; i++){
            int b = arr[i];
            int a = arr[i-1];
            if(minDiff == b-a){
                finalList.add(List.of(a, b));
            }
        }
        return finalList;
    }
}
