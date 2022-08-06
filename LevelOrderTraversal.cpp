Given a pointer to the root of a binary tree, you need to print the level order traversal of this tree. In level-order traversal, nodes are visited level by level from left to right. Complete the function levelOrder and print the values in a single line separated by a space.


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    int height(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }

        return max(height(root->left), height(root->right)) + 1;
    }

    void printDistance(Node *root, int k)
    {
        if (root == NULL)
        {
            return;
        }
        if (k == 0)
        {
            cout << root->data << " ";
        }
        else
        {
            printDistance(root->left, k - 1);
            printDistance(root->right, k - 1);
        }
    }

    void levelOrder(Node *root)
    {
        int n = height(root);

        for (int i = 0; i <= n; i++)
        {
            printDistance(root, i);
        }
    }

}; // End of Solution

//Driver Code

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.levelOrder(root);
    return 0;
}
