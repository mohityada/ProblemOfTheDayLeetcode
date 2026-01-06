class Jan062026 {
    public int maxLevelSum(TreeNode root) {
        if(root == null) return 0;

        Queue<TreeNode> queue = new LinkedList<>();
        int maxLevelSum = Integer.MIN_VALUE, maxLevel = 0, level = 0;
        queue.add(root);
        while(!queue.isEmpty()){
            level++;
            int size = queue.size();
            int sum = 0;
            while (size > 0) {
                TreeNode node = queue.poll();
                sum += node.val;
                if(node.left != null) queue.add(node.left);
                if(node.right != null) queue.add(node.right);
                size--;
            }
            if(sum > maxLevelSum){
                maxLevelSum = sum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }
}
