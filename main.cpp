// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node {
	int val;
	node* next;
};

class list {
private:
	node * head;
public:
	list() {
		head = 0;
	}
	void push_front(int v);
	int count();
	void print();
	int findkth(int v);
};
void list::push_front(int v) {
	node* cur = new node;
	cur->val = v;
	cur->next = 0;
	if (head == NULL) {
		head = cur;
	}
	else {
		cur->next = head;
		head = cur;
	}
}
void list::print() {
	node* cur = head;
	while (cur != NULL) {
		cout << cur->val << ' ';
		cur = cur->next;
	}
	cout << endl << "Size: " << count() << endl;
}
int list::count() {
	int c = 0;
	node* cur = head;
	while (cur != NULL) {
		c++;
		cur = cur->next;
	}
	return c;
}
int list::findkth(int k) {
	int kth = count() - k;
	node* cur = head;
	for (int i = 0; i < kth; i++) {
		cur = cur->next;
	}
	return cur->val;
}

int main(){
	list * p = new list;
	for (int i = 0; i < 6; i++) {
		p->push_front(i * 2);
	}
	p->print();
	cout << 3 << " from last: " <<  p->findkth(3) << endl;

	system("pause");
    return 0;
}

