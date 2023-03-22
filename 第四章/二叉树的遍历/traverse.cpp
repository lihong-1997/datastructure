#include "binarytree.h"

int main2()
{
    TreeNode<char>* root = new TreeNode<char>('A');
    root->left = new TreeNode<char>('B');
    root->left->left = new TreeNode<char>('D');
    root->left->right = new TreeNode<char>('F');
    root->left->right->left = new TreeNode<char>('E');

    root->right = new TreeNode<char>('C');
    root->right->left = new TreeNode<char>('G');
    root->right->right = new TreeNode<char>('I');
    root->right->left->right = new TreeNode<char>('H');

    std::cout << "先序遍历迭代：";
    PreOrderTraversal(root);
    std::cout << "先序遍历递归：";
    PreOrderTraversal_Recursion(root);
    std::cout << std::endl;

    std::cout << "中序遍历迭代：";
    InOrderTraversal(root);
    std::cout << "中序遍历递归：";
    InOrderTraversal_Recursion(root);
    std::cout << std::endl;

    std::cout << "后序遍历迭代：";
    PostOrderTraversal(root);
    std::cout << "后序遍历递归：";
    PostOrderTraversal_Recursion(root);

    return 0;
}