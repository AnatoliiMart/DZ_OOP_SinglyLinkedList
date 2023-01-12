#include <iostream>
using namespace std;
// ������ ��� ������ ��������� ������ ��� ���������� ��� ��������� ��� ������ � ������ ������ ������
//����������� ������
template<typename T>
class List
{
	template<typename T>
	struct Element
	{
	public:
		//������
		T data;
		//����� ���������� �������� ������
		Element* pNext;
	};
	//����� ��������� �������� ������
	Element<T>* pHead;
	//����� ��������� �������� ������
	Element<T>* pTail;
	//���������� ��������� ������
	int Count;
public:
	//�����������
	List();
	//����������
	~List();
	//���������� �������� � ������
	//(����� ������� ���������� ���������)
	void Add(T data);
	//�������� �������� ������
	//(��������� �������� �������)
	void Del();
	//�������� ����� ������
	void DelAll();
	//���������� ����������� ������
	//(���������� ���������� � ��������� ��������) 
	void Print();
	//��������� ���������� ���������,
	//����������� � ������
	int GetCount();
	void AddToBegin(T data);

};
template<typename T>
List<T>::List()
{
	//���������� ������ ����
	pHead = pTail = NULL;
	Count = 0;
}

template<typename T>
List<T>::~List()
{
	//����� ������� ��������
	DelAll();
}

template<typename T>
int List<T>::GetCount()
{
	//���������� ���������� ���������
	return Count;
}

template<typename T>
void List<T>::AddToBegin(T data)
{
	Element<T>* temp = new Element<T>;
	
	if (pHead == nullptr) 
	{
		temp->data = data;
		temp->pNext = nullptr;
		pHead = pTail = temp;
	}
	temp->data = data;
	temp->pNext = pHead;
	pHead = temp;
}

template<typename T>
void List<T>::Add(T data)
{
	//�������� ������ ��������
	Element<T>* temp = new Element<T>;
	//���������� �������
	temp->data = data;
	//��������� ������� �����������
	temp->pNext = nullptr;
	//����� ������� ���������� ��������� ��������� ������
	//���� �� �� ������ �����������
	if (pHead != nullptr) {
		pTail->pNext = temp;
		pTail = temp;
	}
	//����� ������� ���������� ������������
	//���� �� ������ �����������
	else {
		pHead = pTail = temp;
	}
}

template<typename T>
void List<T>::Del()
{
	//���������� ����� ��������� ��������
	Element<T>* temp = pHead;
	//������������� ������ �� ��������� �������
	pHead = pHead->pNext;
	//������� ������ �������� �������
	delete temp;
}

template<typename T>
void List<T>::DelAll()
{
	//���� ��� ���� �������� 
	while (pHead != nullptr)
		//������� �������� �� ������
		Del();
}

template<typename T>
void List<T>::Print()
{
	//���������� ����� ��������� ��������
	Element<T>* temp = pHead;
	//���� ��� ���� ��������
	while (temp != nullptr)
	{
		//������� ������
		cout << temp->data << " ";
		//��������� �� ��������� �������
		temp = temp->pNext;
	}
	cout << "\n\n";
}


//�������� ������
int main()
{
	//������� ������ ������ List
	List<char> lst;
	//�������� ������
	char s[] = "Hello, World !!!";
	//������� ������
	cout << s << "\n\n";
	//���������� ����� ������
	int len = strlen(s);
	//�������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	//������������� ���������� ������
	lst.Print();
	//������� ��� �������� ������
	lst.Del();
	lst.Del();
	lst.Del();
	lst.AddToBegin('L');
	//������������� ���������� ������
	lst.Print();
}