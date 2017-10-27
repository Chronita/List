//����������� ������
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>					// ����� ����� - ������

using namespace std;

struct list
{
	int data; // ���� ������
	struct list *next; // ��������� �� ��������� �������
	struct list *prev; // ��������� �� ���������� �������
};

list initialisation(int a)  // �- �������� ������� ����
{
	list *pv = new list; // ��������� ������ ��� ������ ������
	pv->data = a;
	pv->next = NULL; // ��������� �� ��������� ����
	pv->prev = NULL; // ��������� �� ���������� ����
	return(*pv);
}

list add(list *pv, int number) //������� ���������� ����
{
	list *p;
	list *temp = new list;
	p = pv->next; // ���������� ��������� �� ��������� ����
	pv->next = temp; // ���������� ���� ��������� �� �����������
	temp->data = number; // ���������� ���� ������ ������������ ����
	temp->next = p; // ��������� ���� ��������� �� ��������� ����
	temp->prev = pv; // ��������� ���� ��������� �� ���������� ����
	if (p != NULL)
		p->prev = temp;
	return(*temp);//������������ ��������� ������� �������� ����� ������������ ����.
}

list del(list *pv)   //�������� ����
{
	struct list *prev, *next;
	prev = pv->prev; // ����, �������������� ��������� �� ������ ������ ���� pv
	next = pv->next; // ����, ��������� �� �������� �� ������ ������ ����� pv
	if (pv != NULL)
		prev->next = pv->next; // ������������ ���������
	if (next != NULL)
		next->prev = pv->prev; // ������������ ���������
	free(pv); // ����������� ������ ���������� ��������
	return(*prev);
}

list deletehead(list *pv)  //	������� �������� �����
	{
		list* temp;
		temp = pv->next;
		temp->prev = NULL;
		free(pv);   // ������������ ������ �������� �����
		return(*temp); // ����� ������ ������
	}

void print(list *pv) //	������� ������ ���������
	{
		struct list *p;
		p = pv;
		do {
			cout<<p->data; // ����� �������� �������� p
			p = p->next; // ������� � ���������� ����
		} while (p != NULL); // ������� ��������� ������
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

