node* reverse(node* head) {
	node* current = head;
	node* prev = NULL;
	node* n;
	while(current != NULL) {
		n = current->next;
		current->next = prev;
		prev = current;
		current = n;
	}
	return prev;
}


bool isPalindrome(node* head) {

	if(head == NULL || head->next == NULL) {
		return true;
	}

	node* slow = head;
	node* fast = head;

	//find middle of linked list
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	slow->next = reverse(slow->next);
	slow = slow->next;

	while(slow != NULL) {
		if(head->data != slow->data) {
			return false;
		}
		head = head->next;
		slow = slow->next;
	}
	return true;
}