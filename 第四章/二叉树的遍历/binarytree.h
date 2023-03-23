#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stack>
#include <queue>
#include <iostream>

template <class T>
struct TreeNode
{
	T val;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>(T x) : val(x), left(nullptr), right(nullptr) {}
};

template <class T>
TreeNode<T>* CreateNode(T val_)
{
    TreeNode<T>* treeNode = new TreeNode<T>(val_);
    if (treeNode == nullptr)
    {
        std::cout << "out of space" << std::endl;
        return nullptr;
    }
    treeNode->val = val_;

    return treeNode;
}


//��������ݹ��
template <class T>
void PreOrderTraversal_Recursion(TreeNode<T>* root)
{
    if (root)
    {
		std::cout << root->val << " ";
        PreOrderTraversal_Recursion(root->left);
        PreOrderTraversal_Recursion(root->right);
    }
}

//��������ǵݹ��
template <class T>
void PreOrderTraversal(TreeNode<T>* root)
{
    if (!root) return;

    TreeNode<T>* treeNode = root;
    std::stack<TreeNode<T>*> s;

    while (treeNode || !s.empty())
    {
	    while (treeNode)
	    {
            s.emplace(treeNode);
            std::cout << treeNode->val << " ";
            treeNode = treeNode->left;
	    }
	    if (!s.empty())
	    {
            treeNode = s.top();
            s.pop();
            treeNode = treeNode->right;
	    }
    }
    std::cout << std::endl;
}

//��������ݹ��
template <class T>
void InOrderTraversal_Recursion(TreeNode<T>* root)
{
    if (root)
    {
        InOrderTraversal_Recursion(root->left);
		std::cout << root->val << " ";
        InOrderTraversal_Recursion(root->right);
    }
}

//��������ǵݹ��
template <class T>
void InOrderTraversal(TreeNode<T>* root)
{
    if (!root) return;

    TreeNode<T>* treeNode = root;
    std::stack<TreeNode<T>*> s;

    while (treeNode || !s.empty())
    {
	    while (treeNode)
	    {
            s.emplace(treeNode);
            treeNode = treeNode->left;
	    }//��������������
	    if (!s.empty())
	    {
            //��ջ�������ڵ㣬��ӡ�ýڵ㣬Ȼ�����������
            treeNode = s.top();
            s.pop();
            std::cout << treeNode->val << " ";
            treeNode = treeNode->right;
	    }
    }
    std::cout << std::endl;
}



//��������ݹ��
template <class T>
void PostOrderTraversal_Recursion(TreeNode<T>* root)
{
	if (root)
	{
        PostOrderTraversal_Recursion(root->left);
        PostOrderTraversal_Recursion(root->right);
        std::cout << root->val << " ";
	}
}

//��������ǵݹ��
template <class T>
void PostOrderTraversal(TreeNode<T>* root) {
    if (!root) return;

    std::stack<TreeNode<T>* > s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode<T>* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        TreeNode<T>* node = s2.top();
        s2.pop();
        std::cout << node->val << " ";
    }
    std::cout << std::endl;
}

//�������
template <class T>
void LevelOrderTraversal(TreeNode<T>* root)
{
    if (!root) return;

    std::queue<TreeNode<T>* > Q;
    TreeNode<T>* tNode = root;
    Q.push(tNode);

    while (!Q.empty())
    {
        tNode = Q.front();
        std::cout << tNode->val << " ";
        Q.pop();
        if (tNode->left) Q.push(tNode->left);
        if (tNode->right) Q.push(tNode->right);
    }
}

#endif
