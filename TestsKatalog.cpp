#include<iostream>

using namespace std;

int factorial(int number) {
	if (number < 1) {
		cout << "cant solve that\n";
		return 0;
	}
	int now = number;
	while (number > 1) {
		number--;
		now = now * number;

	}

	return now;
}

struct node {
	string data;
	node* next;

};

void create_head_linked_list(node *&head,string data) {

	if (head == nullptr) {
		node* NewNode = new node;
		NewNode->data = data;
		NewNode->next = nullptr;
		head = NewNode;
		return;
	}
	cout << "you already have head\n";
}

void add_node_linked_list( node *&head, string data) {
	if (head == nullptr) {
		cout << "you have not head" << endl;
		return;
}
	node *NewNode = new node;
	NewNode->data = data;
	NewNode->next = nullptr;
	node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = NewNode;
	return;
}

void print_linked_list(node *head) {
	if (head == NULL) {
		cout << "\tList is empty\n";
		return;

	}
	else {

		node* temp = head;
		while (temp->next != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
	return;

}

void change_head_linked_list(node *&head, string data) {
	node* NewNode = new node;
	NewNode->data = data;
	NewNode->next = head;
	head = NewNode;
	return;
}

void delete_last_linked_list(node *head) {
	node* temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	node *node_to_del = temp->next;
	temp->next = nullptr;
	delete node_to_del;
}

void get_position_linked_list(node *head,string value) {
	
	if (head == nullptr) {
		cout << "list is empty" << endl;
		return;
	}else {
		node* temp = head;
		int current_position = 1;
		while (temp->next != nullptr) {
			if (temp->data == value)
				cout << current_position << endl;
			temp = temp->next;
			current_position++;
		}
		if (temp->data == value)
			cout << current_position << endl;
	}
}

int get_lenth_linked_list(node *head) {
	node* temp = head;
	int current_position = 1;
	if (head == NULL) {
		return 0;
	}
	else {
		while (temp->next != nullptr) {
			temp = temp->next;
			current_position++;
		}
		return current_position;
	}

}

void get_node_by_position_linked_list(node *head,int position) {
	if (position > get_lenth_linked_list(head) || position < 1 || get_lenth_linked_list == 0) {
		cout << "there are not this position in this list\n";
		return;
	}
	else {
		node* temp = head;
		int current_position = 1;
	
		while (temp->next != nullptr && current_position != position) {
			temp = temp->next;
		}
		cout << temp->data;
	}

}
void test_linked_list() {
	node* head = new node;
	head = NULL;
	print_linked_list(head);
	add_node_linked_list(head, "yes");
	create_head_linked_list(head, "It is head");
	add_node_linked_list(head, "second");
	add_node_linked_list(head, "third");
	print_linked_list(head);
	cout << "-------------" << endl;
	change_head_linked_list(head, "new head");
	print_linked_list(head);
	cout << "-------------" << endl;
	delete_last_linked_list(head);
	print_linked_list(head);
	cout << "-------------" << endl;
	add_node_linked_list(head, "second");
	get_position_linked_list(head, "second");

	get_position_linked_list(head, "new head");
	get_position_linked_list(head, "It is head");

	cout << "-------------" << endl;
	print_linked_list(head);
	cout << "lenth: \t" << get_lenth_linked_list(head) << endl;
	get_node_by_position_linked_list(head, 4);
}

int main() {
setlocale(LC_ALL, "ru");

test_linked_list();


}