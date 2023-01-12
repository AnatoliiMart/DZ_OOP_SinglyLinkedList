#include <iostream>
using namespace std;
// СДЕЛАЛ НАШ СПИСОК ШАБЛОННЫМ ПОТОМУ ЧТО СОБСТВЕННО ОНИ СОЗДАЮТСЯ ДЛЯ РАБОТЫ С ЛЮБЫМИ ТИПАМИ ДАННЫХ
//Односвязный список
template<typename T>
class List
{
	template<typename T>
	struct Element
	{
	public:
		//Данные
		T data;
		//Адрес следующего элемента списка
		Element* pNext;
	};
	//Адрес головного элемента списка
	Element<T>* pHead;
	//Адрес концевого элемента списка
	Element<T>* pTail;
	//Количество элементов списка
	int Count;
public:
	//Конструктор
	List();
	//Деструктор
	~List();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Add(T data);
	//Удаление элемента списка
	//(Удаляется головной элемент)
	void Del();
	//Удаление всего списка
	void DelAll();
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента) 
	void Print();
	//Получение количества элементов,
	//находящихся в списке
	int GetCount();
	void AddToBegin(T data);

};
template<typename T>
List<T>::List()
{
	//Изначально список пуст
	pHead = pTail = NULL;
	Count = 0;
}

template<typename T>
List<T>::~List()
{
	//Вызов функции удаления
	DelAll();
}

template<typename T>
int List<T>::GetCount()
{
	//Возвращаем количество элементов
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
	//создание нового элемента
	Element<T>* temp = new Element<T>;
	//заполнение данными
	temp->data = data;
	//следующий элемент отсутствует
	temp->pNext = nullptr;
	//новый элемент становится последним элементом списка
	//если он не первый добавленный
	if (pHead != nullptr) {
		pTail->pNext = temp;
		pTail = temp;
	}
	//новый элемент становится единственным
	//если он первый добавленный
	else {
		pHead = pTail = temp;
	}
}

template<typename T>
void List<T>::Del()
{
	//запоминаем адрес головного элемента
	Element<T>* temp = pHead;
	//перебрасываем голову на следующий элемент
	pHead = pHead->pNext;
	//удаляем бывший головной элемент
	delete temp;
}

template<typename T>
void List<T>::DelAll()
{
	//Пока еще есть элементы 
	while (pHead != nullptr)
		//Удаляем элементы по одному
		Del();
}

template<typename T>
void List<T>::Print()
{
	//запоминаем адрес головного элемента
	Element<T>* temp = pHead;
	//Пока еще есть элементы
	while (temp != nullptr)
	{
		//Выводим данные
		cout << temp->data << " ";
		//Переходим на следующий элемент
		temp = temp->pNext;
	}
	cout << "\n\n";
}


//Тестовый пример
int main()
{
	//Создаем объект класса List
	List<char> lst;
	//Тестовая строка
	char s[] = "Hello, World !!!";
	//Выводим строку
	cout << s << "\n\n";
	//Определяем длину строки
	int len = strlen(s);
	//Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	//Распечатываем содержимое списка
	lst.Print();
	//Удаляем три элемента списка
	lst.Del();
	lst.Del();
	lst.Del();
	lst.AddToBegin('L');
	//Распечатываем содержимое списка
	lst.Print();
}