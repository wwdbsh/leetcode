## Diameter of Binary Tree

* tree, dfs
* Time complexity: O(N). This is because in our recursion function dfs, we only enter and exit from each node once. We know this because each node is entered from its parent, and in a tree, nodes only have one parent.
* Space complexity: O(N). The space complexity depends on the size of our implicit call stack during our DFS, which relates to the height of the tree. In the worst case, the tree is skewed so the height of the tree is O(N). If the tree is balanced, it'd be O(logN).