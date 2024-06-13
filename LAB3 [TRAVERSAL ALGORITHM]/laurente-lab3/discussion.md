# Tree Performance Analysis
This document explores the insertion, searching, and deletion performance of three fundamental tree algorithms: Binary Search Trees (BSTs), Red-Black Trees (RBTs), and AVL Trees. The analysis is based on the graph of randomized inputs ranging from 50,000 to 500,000.

## Insertion

- **BST**: In the worst-case scenario, BST insertion exhibits linear time complexity (O(n)) due to the possibility of tree being imbalanced. With randomized inputs, the likelihood of skewed trees leading to linear time insertion increases, especially for larger inputs that range to 500,000 inputs.
- **RBT**: RBT insertion generally performs better than BST because it enforces a weaker balancing condition. However, it still involves additional checks and rotations compared to AVL trees.
- **AVL**: AVL trees maintain a stricter balance, guaranteeing logarithmic time complexity (O(log n)) for insertion regardless of the input order. This is done by rebalancing the tree during insertion to ensure a minimal height as possible.

## Searching

- **BST, RBT, AVL**: All three trees exhibit similar average-case search time complexity, typically O(log n). This is because the basic search algorithm is comparable across these structures. Furthermore, the primary factor influencing search performance is the tree's height.
- **Advantage of AVL**: AVL trees tend to have a smaller height than RBTs on average due to its tree structure being stricter balance. This slight difference in height translates to slightly faster search times in AVL trees.

## Deletion

- **RBT**: RBT deletion is the slowest due to the need for additional operations like rotations and recoloring to maintain tree balance after removing a node.
- **BST, AVL**: BST and AVL deletion complexities are generally similar, with AVL potentially incurring a slight overhead for maintaining balance during deletion, especially with larger datasets (above 370,000 inputs, based on the graph). However, AVL's benefits in search speed can often outweigh this deletion overhead in practical scenarios.
- **BST Advantage (Limited)**: BST deletion might be marginally faster due to potentially fewer operations than AVL. However, this advantage is often negligible and comes at the cost of potentially slower search and insertion due to BST's weaker balance guarantees.

## Important Notes

- For insertion, AVL trees offer the best performance due to their strict balance.
- Search time complexity is relatively similar across all three trees, with AVL having a slight edge due to its smaller structured height.
- RBT deletion can be the slowest due to additional balancing operations. BST deletion might be marginally faster but offers less overall performance consistency.

## Additional Considerations

- The analysis is based on the graph and its average case scenarios. Worst-case deletion for AVL trees can approach O(log n) due to potential balancing rotations.
- The choice of tree depends on the application's specific priorities. If frequent insertions and deletions are common, AVL trees might be preferred for their overall efficiency. RBTs provide a good compromise between balancing and insertion/deletion complexity. BSTs could be considered if search speed is the primary concern and insertions/deletions are infrequent.
