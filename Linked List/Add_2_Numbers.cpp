
node* addTwoNumbers(node* l1, node* l2) {
	
	node* dummy = new node(0);
	node* temp = dummy;
	int carry = 0;

	while(l1 != NULL || l2 != NULL || carry) {
		int sum = 0;
		if(l1 != NULL) {
			sum += l1->data;
			l1 = l1->next;
		}

		if(l2 != NULL) {
			sum += l2->data;
			l2 = l2->next;
		}

		sum += carry;
		carry = sum/10;
		node* new_node = new node(sum % 10);
		temp->next = new_node;
		temp = temp->next;
	}
	return dummy->next;
}