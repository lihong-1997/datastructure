#include "binarytree.h"

int main()
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

    std::cout << "�������������";
    PreOrderTraversal(root);
    std::cout << "��������ݹ飺";
    PreOrderTraversal_Recursion(root);
    std::cout << std::endl;

    std::cout << "�������������";
    InOrderTraversal(root);
    std::cout << "��������ݹ飺";
    InOrderTraversal_Recursion(root);
    std::cout << std::endl;

    std::cout << "�������������";
    PostOrderTraversal(root);
    std::cout << "��������ݹ飺";
    PostOrderTraversal_Recursion(root);

    std::cout << std::endl;
    std::cout << "�������������";
    LevelOrderTraversal(root);

    return 0;
}