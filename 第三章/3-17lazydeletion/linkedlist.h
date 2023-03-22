#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

namespace linkedlist
{
	// ����ڵ�ģ��
	template <typename T>
	struct Node
	{
		Node<T>() : data(0), deleted(false), next(nullptr) {}
		Node<T>(const T& data_) : data(data_), deleted(false), next(nullptr) {}
		T data;
		bool deleted;  //����ɾ����־λ
		Node<T>* next;
	};
	// ����ģ��
	template <typename T>
	class List
	{
	public:
		List<T>();
		~List<T>();
	public:
		bool empty() const { return length == 0; }           //�ж������Ƿ�Ϊ��
		size_t size() const { return length; }               //����������
		Node<T>* Header() const { return header; }           //���������ͷ
		Node<T>* First() const { return header->next; }      //����ͷ�ڵ�
		bool IsLast(Node<T>* positon) const;                 //�ж��Ƿ�Ϊβ���
		void Insert(T value, Node<T>* positon);              //ָ��λ�ú����Ԫ��
		void Insert(T value);                                //����β������Ԫ��
		Node<T>* Find(T value) const;                        //��������ָ��Ԫ��
		Node<T>* Find_recursive(T value) const;              //�ݹ����ָ��Ԫ��
		Node<T>* Find_Kth(size_t K) const;                   //���ҵ�k��Ԫ��
		Node<T>* Find_pre(T value) const;                    //����Ԫ��ǰһ���ڵ�
		void Remove(T value);                                //ɾ��ָ��Ԫ��
		void LazyDelete(T value);                            //����ɾ��
		void Traverse() const;                               //�������������Ԫ��
		Node<T>* Advance(Node<T>* node) const;               //ǰ��һ�ڵ�
		void Reverse();                                      //��ת����
		T Retrieve(Node<T>* node);                           //
		void DeleteList();                                   //ɾ���б�

	private:
		Node<T>* Find_re(T value, Node<T>* pos) const; //�ݹ����ָ��Ԫ��
		Node<T>* header;
		size_t length;
		size_t delete_count;
	};

	template<typename T>
	List<T>::List()
	{
		length = 0;
		delete_count = 0;
		header = new Node<T>();
	}
	template<typename T>
	List<T>::~List()
	{
		Node<T>* node = header->next;
		Node<T>* temp;
		header->next = nullptr;
		while (node != nullptr)
		{
			temp = node->next;
			delete node;
			node = temp;
		}
		length = 0;
	}
	template<typename T>
	void List<T>::Insert(T value)
	{
		Node<T>* pnew = new Node<T>(value);
		if (length == 0) header->next = pnew;
		else
		{
			Node<T>* node = header->next; //�����һ���ڵ�
			while (node->next != nullptr)
				node = node->next;
			node->next = pnew;
		}

		++length;
	}

	template<typename T>
	Node<T>* List<T>::Find(T value) const
	{
		Node<T>* node = header->next;
		while (node != nullptr && node->data != value)
			node = node->next;

		return node;
	}

	template<typename T>
	Node<T>* List<T>::Find_recursive(T value) const
	{
		return Find_re(value, header->next);
	}

	template<typename T>
	Node<T>* List<T>::Find_re(T value, Node<T>* pos) const
	{
		if (pos == nullptr || pos->data == value)
			return pos;

		return Find_re(value, pos->next);
	}

	template<typename T>
	Node<T>* List<T>::Find_Kth(size_t K) const
	{
		if (K > length)
			return nullptr;
		size_t i = 1;
		Node<T>* node = header->next;
		while (i++ != K)
			node = node->next;
		return node;
	}

	template<typename T>
	Node<T>* List<T>::Find_pre(T value) const
	{
		Node<T>* node = header;
		while (node->next != nullptr && node->next->data != value)
			node = node->next;

		return node;
	}

	template<typename T>
	void List<T>::Remove(T value)
	{
		Node<T>* preNode = Find_pre(value);
		if (preNode == nullptr)
			return;
		Node<T>* temp = preNode->next;
		preNode->next = temp->next;
		delete temp;
		--length;
	}

	template<typename T>
	inline void List<T>::LazyDelete(T value)
	{
		Node<T>* p = Find(value);
		p->deleted = true;
		++delete_count;
		//����ɾ��Ԫ���ۼƵ���Ǳ�ɾ��Ԫ��һ����ʱ��ִ��ɾ��������ɾ�����б���ǽڵ�
		if (delete_count == length - delete_count)
		{
			Node<T>* fNode = header;
			while (fNode->next)
			{
				if (fNode->next->deleted)
				{
					Node<T>* temp = fNode->next->next;
					delete fNode->next;
					fNode->next = temp;
					--length;
				}
				else
					fNode = fNode->next;
			}
		}
	}

	template<typename T>
	bool List<T>::IsLast(Node<T>* positon) const
	{
		return positon->next == nullptr;
	}

	template<typename T>
	void List<T>::Insert(T value, Node<T>* positon)
	{
		Node<T>* pnew = new Node<T>(value);
		pnew->next = positon->next;
		positon->next = pnew;
		++length;
	}

	template <typename T>
	void List<T>::Traverse() const
	{
		Node<T>* node = header->next;
		while (node != nullptr) 
		{
			if (!node->deleted)//�������ɾ����ǵĽڵ�
				std::cout << node->data << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}

	template<typename T>
	Node<T>* List<T>::Advance(Node<T>* node) const
	{
		return node->next;
	}

	template<typename T>
	void List<T>::Reverse()
	{
		Node<T>* PreNode = header;
		//�����Ŀ飬��������־λ���
		Node<T>* BeginFlag = header->next;
		Node<T>* EndFlag = header->next;
		//�����Ľڵ�
		Node<T>* SwapNode = EndFlag->next;

		while (SwapNode)
		{
			PreNode->next = SwapNode;
			EndFlag->next = SwapNode->next;
			SwapNode->next = BeginFlag;

			BeginFlag = header->next; //����begin��־λ
			SwapNode = EndFlag->next; //������һ��Ҫ�����Ľڵ�
		}
	}

	template<typename T>
	T List<T>::Retrieve(Node<T>* node)
	{
		return node->data;
	}

	template<typename T>
	void List<T>::DeleteList()
	{
		Node<T>* node = header->next;
		Node<T>* temp;
		header->next = nullptr;
		while (node != nullptr)
		{
			temp = node->next;
			delete node;
			node = temp;
		}
		length = 0;
	}

}

#endif
