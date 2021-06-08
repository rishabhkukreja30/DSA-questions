
node* evenAfterOdd(node*& head) {
	
	node* evenHead = new node(0);
	node* oddHead = new node(0);

	node* even = evenHead;
	node* odd = oddHead;

	node* temp  =head;

	while(temp != NULL) {
		if(temp->data % 2 == 0) {
			even->next = temp;
			even = even->next;
		}
		else {
			odd->next = temp;
			odd = odd->next;
		}
		temp = temp->next;
	}
	odd->next = evenHead->next;
	head = oddHead->next;
	return head;
}