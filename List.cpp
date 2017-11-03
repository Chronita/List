#include "stdafx.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <iostream> 
#include "string.h" 
#include <ctime> 

using namespace std;
void error();

void error()
{
	cout << "no items" << endl;
	_gettch();
}

struct List {
    int size;
    List *head;
    List *tail;
	int value;
	List *next;
	List *prev;
};

List* createList() {      // создаёт экземпляр структуры List
	List *temp = new List;
	temp->size = 0;
	temp->head = NULL;
	temp->tail = NULL;

	return temp;
}


void add_to_beg(List *list,int data) //вставка в начало
{
	List *temp = new List;
	if (temp == NULL) error();
	temp->value = data;
	temp->next = list->head;
	temp->prev = NULL;
	if (list->head) {
		list->head->prev = temp;
	}
	list->head = temp;

	if (list->tail == NULL) {
		list->tail = temp;
	}
	list->size++;
}

void add_to_end(List *list, int value) //вставка в конец
{
	List *temp = new List;
	if (temp == NULL) error();
	temp->value = value;
	temp->next = NULL;
	temp->prev = list->tail;
	if (list->tail) {
		list->tail->next = temp;
	}
	list->tail = temp;

	if (list->head == NULL) {
		list->head = temp;
	}
	list->size++;
}

int delete_from_beg(List *list) //удаление с начала
{
	List *prev;
	int temp;
	if (list->head == NULL) error();
	prev = list->head;
	list->head = list->head->next;
	if (list->head) {
		list->head->prev = NULL;
	}
	if (prev == list->tail) {
		list->tail = NULL;
	}
	temp = prev->value;
	free(prev);

	list->size--;
	return temp;
}

int delete_from_end(List *list) //удаление с конца
{
	List *next;
	int temp;
	if (list->tail == NULL) error();
    next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail) {
		list->tail->next = NULL;
	}
	if (next == list->head) {
		list->head = NULL;
	}
	temp = next->value;
	free(next);

	list->size--;
	return temp;
}

List* get(List *list, int index) //получение элемента
{
	List *temp = list->head;
	int i = 0;
	while (temp && i < index) {
		temp = temp->next;
		i++;
	}
	return temp;
}

void add_element(List *list,int index, int value)//добавление элемента в список
{
	List *el = NULL;
	List *add = NULL;
	el = get(list, index);
	if (el == NULL) error();
	add = new List;
	add->value = value;
	add->prev = el;
	add->next = el->next;
	if (el->next) {
		el->next->prev = add;
	}
	el->next = add;

	if (!el->prev) {
		list->head = el;
	}
	if (!el->next) {
		list->tail = el;
	}

	list->size++;
}

void add_before_el(List *list, List* el, int value) // вставка до указанного элемента
{ 
	List *ins = NULL;
	if (el == NULL) error();

	if (!el->prev) {
		add_to_beg(list, value);
		return;
	}
	ins = new List;
	ins->value = value;
	ins->prev = el->prev;
	el->prev->next = ins;
	ins->next = el;
	el->prev = ins;

	list->size++;
}

void sort(List *list)
{   
	List *cur = list->head;
	while (cur->next)
	{
		if ((cur->value)>(cur->next->value))
		{
			//обмен
			int temp = cur->next->value;
			cur->next->value = cur->value;
			cur->value = temp;

			cur = cur->next;
			sort(list);
		}
		else { cur = cur->next; }
	}

}

void printList(List *list) 
{
	List *temp = list->head;
	while (temp) {
		cout<< temp->value; 
		temp = temp->next;
	}
	cout<<"\n";
}
 
void operations()
{
	int a, n, m, l, k, x;
	List *list = createList();

	cout << "1) add_to_beg\n"
	     << "2) add_to_end\n"
	     << "3) delete_from_beg\n"
	     << "4) delete_from_end\n"
             << "5) add_to_the_list\n"
	     << "6) sort\n";
	cout << "How many operations will it be?  ";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "Input the operation number ->  ";
		cin >> a;
		cout << endl;
		switch (a) {
		case 1:
			cout << "number of add_to_beg ->  "; cin >> n;
			for (int i = 0; i < n; i++) add_to_beg(list, rand() % 9 + 1);
			printList(list);
			cout << endl;
			break;
		case 2:
			cout << "number of add_to_end ->  "; cin >> m;
			for (int i = 0; i < m; i++) add_to_end(list, rand() % 9 + 1);
			printList(list);
			cout << endl;
			break;
		case 3:
			cout << "number of delete_from_beg ->  "; cin >> l;
			for (int i = 0; i < l; i++) delete_from_beg(list);
			printList(list);
			cout << endl;
			break;
		case 4:
			cout << "number of add_to_end ->  "; cin >> k;
			for (int i = 0; i < k; i++) delete_from_end(list);
			printList(list);
			break;
		case 5:
			add_element(list, 1, rand() % 9 + 1);
			printList(list);
			cout << endl;
			break;
		case 6:
			sort(list);
			printList(list);
			cout << endl;
			break;
		default:
			return error();
			break;
		}
	}
}

int main() 
{
	operations();
	_gettch();
	return 0;
}
