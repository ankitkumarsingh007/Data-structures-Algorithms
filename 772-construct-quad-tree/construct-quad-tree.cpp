/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
    Node* quadTree(vector<vector<int>>& grid, int i, int j, int n) {
        if (n == 1) {
            return new Node(grid[i][j], 1);
        }
        Node* topLeft = quadTree(grid, i, j, n / 2);
        Node* topRight = quadTree(grid, i, j + n / 2, n / 2);
        Node* bottomLeft = quadTree(grid, i + n / 2, j, n / 2);
        Node* bottomRight = quadTree(grid, i + n / 2, j + n / 2, n / 2);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf &&
            bottomRight->isLeaf && topLeft->val == topRight->val &&
            topLeft->val == bottomLeft->val &&
            topLeft->val == bottomRight->val) {
            return topLeft;
        } else {
            Node* curr = new Node(1, 0);
            curr->topLeft = topLeft;
            curr->topRight = topRight;
            curr->bottomLeft = bottomLeft;
            curr->bottomRight = bottomRight;
            return curr;
        }
        return NULL;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return quadTree(grid, 0, 0, n);
    }
};