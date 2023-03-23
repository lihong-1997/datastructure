#include "binarytree.h"
#include <iostream>

/*
 * ��׺ת���ʽ����
 * ��ͨ��ջ�����׺���ʽ���ơ�
 * �������Ҷ���׺���ʽ
 * �ǲ��������������ڵ�������Ҷ���ͣ�����ָ������ָ��ѹ��ջ
 * �ǲ��������������ڵ�����rightΪջpop�ĵ�һ��Ԫ�أ�leftΪpop�ĵڶ���Ԫ��
 * ѭ����������ջ��Ψһָ�룬��Ϊrootָ��
 */
TreeNode<char>* expressionTree(const char* A, int N)
{
	std::stack<TreeNode<char>* > s;

	for (int i = 0; i < N; ++i)
	{
		if (A[i] != '+' && A[i] != '*')
		{
			TreeNode<char>* numNode = CreateNode(A[i]);
			s.emplace(numNode);
		}
		else
		{
			TreeNode<char>* rightNode = s.top();
			s.pop();
			TreeNode<char>* leftNode = s.top();
			s.pop();

			TreeNode<char>* opNode = CreateNode(A[i]);
			opNode->left = leftNode;
			opNode->right = rightNode;
			s.emplace(opNode);
		}
	}

	TreeNode<char>* root = s.top();
	s.pop();

	return root;
}

/*
 * ͨ���������������������ţ�ʹ�ú�׺���ʽת��׺���ʽ
 */
void TreeToInfix(TreeNode<char>* root, std::string& res )
{
	if (root)
	{
		if (root->left) res.push_back('(');
		TreeToInfix(root->left, res);
		res.push_back(root->val);
		TreeToInfix(root->right, res);
		if (root->right) res.push_back(')');
	}

}


//����׺���ʽתΪ���ʽ�����������ʽ����������������ɵõ���׺���ʽ
std::string PostToInfix(TreeNode<char>* root, const std::string& post)
{
	std::string res;

	TreeToInfix(root, res);

	return res;
}


//�ݹ������ʽ����ֵ
int calculate_expressionTree(const TreeNode<char>* root)
{
	//��Ϊ��Ҷ������ת��Ϊ�������ͣ�������
	if (root->left == nullptr && root->right == nullptr) {
		return (int)(root->val) - 48;
	}

	int leftValue = calculate_expressionTree(root->left);
	int rightValue = calculate_expressionTree(root->right);

	switch (root->val) {
	case '+':
		return leftValue + rightValue;
	case '-':
		return leftValue - rightValue;
	case '*':
		return leftValue * rightValue;
	//case '/':
		//return leftValue / rightValue;
	default:
		return 0;
	}
}

int main2()
{
	std::string postEx("123*+45*3+2*+"); //53
	TreeNode<char>* root = expressionTree(postEx.data(), (int)postEx.size());

	std::string infixEx = PostToInfix(root, postEx);
	std::cout << "infix expression:";
	for (const char i : infixEx)
		std::cout << i;

	int value = calculate_expressionTree(root);
	std::cout << "\n" << "expression value:" << value;

	return 0;
}