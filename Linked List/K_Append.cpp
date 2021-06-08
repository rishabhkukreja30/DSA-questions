
node* appendK(node *head,int k){
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for(long i=0;i < k && fast->next!=NULL ;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL && fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}


// or
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k ==0) {
            return head;
        }
        int len = 1;
        ListNode* curr = head;
        while(curr->next != NULL) {
            len++;
            curr = curr->next;
        }
        curr->next = head;
        
        k = (k%len);
        curr  =head;
        int cnt = 1;
        while(cnt < len - k) {
            cnt++;
            curr = curr->next;
        }
        ListNode* newhead = curr->next;
        curr->next = NULL;
        return newhead;

    }



    