#include "polynomialList.h"

#include <algorithm>

std::istream& operator>>(std::istream &is, Polynomial &poly)
{
	int coe, exp;
	Node* p = poly.header;
	while (is >> coe >> exp && coe) //��������exp
	{
		p->Next = new Node(coe, exp);
		p = p->Next;
	}

	return is;
}

std::ostream& operator<<(std::ostream &os, const Polynomial &poly)
{
	Node* TmpNode = poly.header->Next; //��һ��NODE
	while (TmpNode)
	{
		if (TmpNode->exp == 0)
			os << TmpNode->coe;
		else
			os << TmpNode->coe << "x^" << TmpNode->exp;

		if (TmpNode->Next && TmpNode->Next->coe > 0)
			os << "+";

		TmpNode = TmpNode->Next;
	}

	return os;
}
/*
 * �㷨ʱ�临�Ӷ�O(M+N),������������󲢼���˼·
 */
Polynomial operator+(const Polynomial &poly1, const Polynomial &poly2)
{
	Polynomial resultPoly;
	Node* p = resultPoly.header;
	Node* poly1FirstNode = poly1.header->Next;
	Node* poly2FirstNode = poly2.header->Next;

	while (poly1FirstNode && poly2FirstNode)
	{
		if (poly1FirstNode->exp > poly2FirstNode->exp)
		{
			p->Next = new Node(poly1FirstNode->coe, poly1FirstNode->exp);
			poly1FirstNode = poly1FirstNode->Next; //����1ǰ��һ�ڵ�
			p = p->Next;
		}
		else if (poly1FirstNode->exp < poly2FirstNode->exp)
		{
			p->Next = new Node(poly2FirstNode->coe, poly2FirstNode->exp);
			poly2FirstNode = poly2FirstNode->Next; //����2ǰ��һ�ڵ�
			p = p->Next;
		}
		else
		{
			int coeSum = poly1FirstNode->coe + poly2FirstNode->coe;
			//���ϵ���Ͳ�Ϊ 0���������ڵ�
			if (coeSum)
			{
				p->Next = new Node(coeSum, poly2FirstNode->exp);
				p = p->Next;
			}
			poly1FirstNode = poly1FirstNode->Next;
			poly2FirstNode = poly2FirstNode->Next;
		}
	}
	Node* tmpNode = poly1FirstNode ? poly1FirstNode : poly2FirstNode;
	while (tmpNode)
	{
		p->Next = new Node(tmpNode->coe, tmpNode->exp);
		p = p->Next;
		tmpNode = tmpNode->Next;
	}
	return resultPoly;
}

/*
 * ����poly1 M �poly2 N �M<N
 * �㷨���Ӷ�:O(M^2*N^2)
 * ˼·��
 * (1)����Ԫ��������˲��г�,����MN������ʽ;
 * (2)�ӵ�һ�ʼ�����������Ƚϣ�ָ�������ϲ�(O(M^2*N^2));
 * (3)���ݴβ�������
 *
 *
 * �㷨���Ӷ�:O(M^2*N)
 * ˼·��
 * (1)ÿ�ν�����ΪM�������һ��,����һ��������������,ÿ�����һ����N���ڵ�������Ķ���ʽ����,O(MN);
 * (2)�������������󲢵Ĳ������������������:
 * (3)O(N+N + 2N+N +...+ (M-1)N+N)=O(M^2*N)
 *
 *
 * �㷨���Ӷ�:O(MN*log(MN))
 * ˼·��
 * (1)����Ԫ��������˲��г�,����MN������ʽ;
 * (2)��MN���ʽ��ָ������O(MN*logMN)������:
 * (3)�ϲ�ͬ�ݴ�����ȫ����������
 */
Polynomial operator*(const Polynomial &poly1, const Polynomial &poly2)
{
	Polynomial resultPoly;
	Node* poly1Node = poly1.header->Next, *poly2Node;
	
	while (poly1Node)
	{
		//ÿ��ѭ����������һ���м����ʽ
		Polynomial tmpPoly;
		Node* tmp = tmpPoly.header;
		//���¶�λ��poly2��һ��
		poly2Node = poly2.header->Next; 
		while (poly2Node)
		{
			tmp->Next = new Node(poly1Node->coe * poly2Node->coe,
				               poly1Node->exp + poly2Node->exp);
			tmp = tmp->Next;
			poly2Node = poly2Node->Next;
		}
		resultPoly += tmpPoly;
		poly1Node = poly1Node->Next;
	}

	return resultPoly;
}

Polynomial polypower(const Polynomial &poly, unsigned times)
{
	Polynomial result;
	Node* tmp = result.header;
	if (times == 0)
	{
		tmp->Next = new Node(1, 0);
		return result;
	}
	else if(times == 1)
	{
		return poly;
	}
	
	
	else if(times % 2 == 0)
	{
		return polypower(poly, times / 2) * polypower(poly, times / 2);
	}
	else if (times % 2 != 0)
	{
		return polypower(poly, times / 2) * polypower(poly, times / 2) * poly;
	}

}

Polynomial polypower2(const Polynomial& poly, unsigned times)
{
	Polynomial result;
	Node* tmp = result.header;
	if (times == 0)
	{
		tmp->Next = new Node(1, 0);
		return result;
	}

	if (times % 2 == 0)
	{
		return polypower(poly * poly, times / 2);
	}
	else if (times % 2 != 0)
	{
		return polypower(poly * poly, times / 2) * poly;
	}
}

Polynomial::Polynomial(const Polynomial &poly)
{
	Node* Src = poly.header->Next;
	Node* Dst = header;
	while (Src)
	{
		Dst->Next = new Node(Src->coe, Src->exp);
		Dst = Dst->Next;
		Src = Src->Next;
	}
}

Polynomial::~Polynomial()
{
	Node* p = header->Next;
	header->Next = nullptr;
	delete header;
	while(p)
	{
		Node* tmp = p->Next;
		delete p;
		p = tmp;
	}
}

Polynomial& Polynomial::operator=(Polynomial poly)
{
	std::swap(header, poly.header);
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial &poly)
{
	*this = *this + poly;
	return *this;
}
