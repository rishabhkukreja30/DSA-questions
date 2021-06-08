#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;

	//constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};


//passing a pointer variable by reference
void insertAtHead(node *&head, int data) {

	node* n = new node(data);
	n->next = head;
	head = n;
}

int length(node *head) {
	int len = 0;
	while(head != NULL) {
		head = head->next;
		len += 1;
	}
	return len;
}

void insertAtTail(node*& head, int data) {
	if(head == NULL) {
		head = new node(data);
		return;
	}
	node *tail = head;
	while(tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = new node(data);
	return;
}

void insertInMiddle(node*&head, int data, int position) {
	if(head == NULL || position ==0 ) {
		insertAtHead(head, data);
	}
	else if(position>length(head)){
		insertAtTail(head,data);
	}
	else {
		//insert in the middle
		//take p-1 jumps
		int jump =1;
		node* temp = head;
		while(jump<=position-1) {
			temp = temp->next;
			jump += 1;
		}
		node* n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}

bool searchRecursive(node*&head, int key) {
	if(head == NULL) {
		return false;
	}
	//rec case
	if(head->data == key){
		return true;
	}
	else {
		return searchRecursive(head->next , key);
	}
}

bool searchIterative(node*&head, int key) {
	while(head != NULL) {
		if(head->data == key) {
			return true;
		}
		head = head->next;
	}
	return false;
}

void print(node *head) {
	while(head != NULL) {
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void deleteAtHead(node*&head) {
	if(head == NULL) {
		return;
	}
	node* temp = head;
	head = head->next;
	delete temp;
	return;
}

void deleteAtTail(node*& head) {
	node* prev =NULL;
	node* temp = head;
	while(temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	delete temp;
	prev->next = NULL;
	return;
}

void buildList(node*&head) {
	int data;
	cin>>data;
	while(data != -1) {
		insertAtTail(head, data);
		cin>>data;
	}
}

istream& operator>>(istream &is, node*&head) {
	buildList(head);
	return is;
}


ostream& operator<<(ostream &os, node*head) {
	print(head);
	return os;
}

node* midPoint(node* head) {
	if(head == NULL || head->next ==NULL) {
		return head;
	}
	node* slow = head;
	node* fast = head->next;
	while(fast != NULL && fast->next !=NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* kthNodeFromLast(node*head, int k) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	node* slow = head;
	node* fast = head;
	int count = 0;
	while(count < k) {
		fast = fast->next;
		count++;
	}
	while(fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

void reverse(node*& head) {
	node *current = head;
	node *prev = NULL;
	node *n;
	while(current != NULL) {
		//save the next node
		n = current->next;
		//make the current node point to previous
		current->next = prev;
		//just update previous and current
		prev = current;
		current = n;
	}
	head = prev;

}

node * reverseRec(node*head) {
	//base case
	if(head->next == NULL || head == NULL) {
		return head;
	}
	//rec case
	node* smallHead = reverseRec(head->next);
	node* current = head;
	current->next->next = current;
	current->next = NULL;
	return smallHead;
}

//merge two sorted linked lists
node* merge(node* a, node* b) {
	if(a==NULL) {
		return b;
	}
	else if(b == NULL) {
		return a;
	}
	node* c;

	//compare a and b for smaller element
	if(a->data < b->data) {
		c = a;
		c->next = merge(a->next ,b);
	}
	else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

node* mergeSort(node* head) {
	//base case
	if(head == NULL || head->next == NULL) {
		return head;
	}
	//rec case
	//1. mid point
	node* mid = midPoint(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	//2. recursively sort
	a = mergeSort(a);
	b = mergeSort(b);

	//3. merge a and b
	node* c = merge(a, b);
	return c;
}

bool detectCycle(node* head) {
	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow) {
			return true;
		}
	}
	return false;
}

int main() {

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	node *head = NULL;

	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtTail(head, 6);

	insertInMiddle(head, 2, 3);

	print(head);
	cout<<endl;

	reverse(head);
	print(head);
	cout<<endl;

	head = reverseRec(head);
	print(head);

	node* m = midPoint(head) ;
	cout<<endl<<m->data<<endl;

	node* kn = kthNodeFromLast(head, 2);
	cout<<endl<<kn->data<<endl;

	node* d = mergeSort(head);
	print(d);
	cout<<endl;

	deleteAtHead(head);
	deleteAtTail(head);
	cout<<endl;
	print(head);
	cout<<endl;
	if(searchRecursive(head, 4)) {
		cout<<"Element is present"<<endl;
	}
	else {
		cout<<"Element is not present"<<endl;
	}
	cout<<endl;

	if(searchIterative(head , 14)) {
		cout<<"Present"<<endl;
	}
	else{
		cout<<"Not present"<<endl;
	}

	// buildList(head);
	// print(head);


	//for merging 
	node *head1 = NULL;
	node *head2 = NULL;

	insertAtTail(head1, 1);
	insertAtTail(head1, 2);
	insertAtTail(head1, 4);
	insertAtTail(head1, 5);
	insertAtTail(head1, 6);
	insertAtTail(head1, 8);

	print(head1);
	cout<<endl;

	insertAtTail(head2, 5);
	insertAtTail(head2, 6);
	insertAtTail(head2, 7);
	insertAtTail(head2, 8);
	insertAtTail(head2, 18);
	insertAtTail(head2, 20);

	print(head2);
	cout<<endl;

	node* c = merge(head1, head2);
	print(c);
	cout<<endl;


	return 0;

}
