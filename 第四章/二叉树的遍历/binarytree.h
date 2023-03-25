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

//�����������Ҷ�ӽڵ�
template <class T>
void PreOrderPrintLeaves(TreeNode<T>* root)
{
    if (root)
    {
        if (!root->left && !root->right)
			std::cout << root->val << " ";
        PreOrderPrintLeaves(root->left);
        PreOrderPrintLeaves(root->right);
    }
}

//����������߶�
template <class T>
int Height(TreeNode<T>* root)
{
    int HL, HR, MaxH;
    if (root)
    {
        HL = Height(root->left);
        HR = Height(root->right);
        MaxH = (HL > HR) ? HL : HR;
        return 1 + MaxH;
    }
    else
        return 0;
}

//����������������ȷ��������
template <class T>
TreeNode<T>* BuildTree(std::vector<T>& pre, std::vector<T>& in)
{
    //ȷ���������зǿգ�����Ϊ�ݹ��׼����
    if (pre.empty() || in.empty()) return nullptr;

    //�������е�һ��ֵΪ���ڵ�ֵ���������ڵ�
    T rootVal = pre[0];
    TreeNode<T>* root = new TreeNode<T>(rootVal);

    //�ɸ��ڵ�ֵ�������������л���������������ڵ����
	int index = 0; 
    for (;index < in.size();index++)
        if (in[index] == rootVal) break;
    //����ǰ�������е���������
    std::vector<T> leftChildTree_pre(pre.begin() + 1, pre.begin() + 1 + index);
    std::vector<T> rightChildTree_pre(pre.begin() + 1 + index, pre.end());
    //�������������е���������
    std::vector<T> leftChildTree_in(in.begin(), in.begin() + index);
    std::vector<T> rightChildTree_in(in.begin() + index + 1, in.end());

	//ǰ������������������������������
    root->left = BuildTree(leftChildTree_pre, leftChildTree_in);
    //ǰ������������������������������
    root->right = BuildTree(rightChildTree_pre, rightChildTree_in);

    return root;
}

//��������ݹ����ڵ����Ҷ���
template <class T>
void PreOrderGetChild(TreeNode<T>* root)
{
    if (root)
    {
        T lChild = (root->left) ? (root->left->val) : '-';
        T rChild = (root->right) ? (root->right->val) : '-';
        std::cout << root->val << ":" << lChild << rChild << '\n';

        PreOrderGetChild(root->left);
        PreOrderGetChild(root->right);
    }
}

//�ж��������Ƿ�ͬ��
template <class T>
bool isIsomorphic(TreeNode<T>* root1, TreeNode<T>* root2) {
    if (!root1 && !root2) return true; //���ڵ㶼û����
    if (!root1 || !root2) return false; //���ڵ�����һ��û����
    if (root1->val != root2->val) return false; //���ڵ㶼���������ж��������ڵ�ֵ
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
        (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}

#endif
