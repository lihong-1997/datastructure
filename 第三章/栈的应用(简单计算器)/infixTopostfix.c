#include "infixTopostfix.h"

int PriorLevel(char operator)
{
	switch (operator)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '^':
		return 3;
	case '(':
		return 4;
	default:
		return 0;
	}
}

void InfixToPostfix(const char *Infix, int len, char *Postfix)
{
	int outIndex = 0;
	Stack OperatorStack = CreateStack(50);
	char top;
	for (int i = 0; i < len;i++)
	{
		if (Infix[i] == '^' || Infix[i] == '*' || Infix[i] == '+' || Infix[i] == '-' || Infix[i] == '/' || Infix[i] == '(')
		{
			if (IsEmpty(OperatorStack))
				Push(Infix[i], OperatorStack);
			else
			{
				top = Top(OperatorStack);
				//��ע���������������!!!
				if ((PriorLevel(top) < PriorLevel(Infix[i])) || (top == '^' && Infix[i] == '^'))
					Push(Infix[i], OperatorStack);
				else
				{
					//���Ǵ�������ţ������Ų�����
					while(top != '(' && PriorLevel(top) >= PriorLevel(Infix[i]))
					{
						Postfix[outIndex++] = top;
						Pop(OperatorStack);
						if (IsEmpty(OperatorStack)) break;
						top = Top(OperatorStack);
					}
					Push(Infix[i], OperatorStack);
				}
			}
		}
		else if(Infix[i] == ')')
		{
			top = Top(OperatorStack);
			//printf("top:%c", top);
			//���ε���ջԪ�أ�д��Postfix��ֱ������'('
			while (top != '(')
			{
				Postfix[outIndex++] = top;
				Pop(OperatorStack);
				top = Top(OperatorStack);
			}
			Pop(OperatorStack); // �� '('����
		}
		else
			Postfix[outIndex++] = Infix[i]; //���������������
	}
	//����Ϊ�գ���ջԪ��ȫ������
	while (!IsEmpty(OperatorStack))
	{
		top = Top(OperatorStack);
		Postfix[outIndex++] = top;
		Pop(OperatorStack);
	}
	DisposeStack(OperatorStack);
}