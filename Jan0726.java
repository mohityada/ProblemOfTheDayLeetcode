class Jan0726 {
    long totalSum = 0;
    long maxProduct = 0;
    int MOD = 1_000_000_007;

    long sum(TreeNode root) {
        if (root == null) return 0;
        return sum(root.left) + sum(root.right) + root.val;
    }

    long dfs(TreeNode root) {
        if (root == null) return 0;

        long left = dfs(root.left);
        long right = dfs(root.right);

        long subTreeSum = left + right + root.val;

        long product = subTreeSum * (totalSum - subTreeSum);
        maxProduct = Math.max(maxProduct, product);

        return subTreeSum;
    }

    public int maxProduct(TreeNode root) {
        totalSum = sum(root);
        dfs(root);
        return (int)(maxProduct % MOD);
    }
}
