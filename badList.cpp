#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>			

using namespace std;

struct list
{
	int data; // поле данных
	struct list *next; // указатель на следующий элемент
	struct list *prev; // указатель на предыдущий элемент
};

list initialisation(int a)  // а- значение первого узла
{
	list *pv = new list; // выделение памяти под корень списка
	pv->data = a;
	pv->next = NULL; // указатель на следующий узел
	pv->prev = NULL; // указатель на предыдущий узел
	return(*pv);
}

list add(list *pv, int number) //функция добавления узла
{
	list *p;
	list *temp = new list;
	p = pv->next; // сохранение указателя на следующий узел
	pv->next = temp; // предыдущий узел указывает на создаваемый
	temp->data = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = pv; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(*temp);//Возвращаемым значением функции является адрес добавленного узла.
}

list del(list *pv)   //Удаление узла
{
	struct list *prev, *next;
	prev = pv->prev; // узел, предшествующий текущему узлу pv
	next = pv->next; // узел, следующий за текущим узлом pv
	if (pv != NULL)
		prev->next = pv->next; // переставляем указатель
	if (next != NULL)
		next->prev = pv->prev; // переставляем указатель
	free(pv); // освобождаем память удаляемого элемента
	return(*prev);
}

list deletehead(list *pv)  //	Функция удаления корня
	{
		list* temp;
		temp = pv->next;
		temp->prev = NULL;
		free(pv);   // освобождение памяти текущего корня
		return(*temp); // новый корень списка
	}

void print(list *pv) //	Функция вывода элементов
	{
		struct list *p;
		p = pv;
		do {
			cout<<p->data; // вывод значения элемента p
			p = p->next; // переход к следующему узлу
		} while (p != NULL); // условие окончания обхода
	}


	int main(list *pv)
	{
		struct list; int a, number;
		cout << "Creationing the list:" << endl;
		cout << "Input the item of the 1st node" << endl;
		cin >> a;
		initialisation(a);
		cout << "How many items will it be in the list?" << endl;
		cin >> number;
		for (int i = 1; i < number; i++) add(pv,number);
		print(pv);
		//cout << "How many options would you like to do?"
		//cout << "Choose the option"

	}
