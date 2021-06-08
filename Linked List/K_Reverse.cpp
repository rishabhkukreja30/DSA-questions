
node* reverse(node* head, int k) {
       
       node* current = head; 
       node* next = NULL; 
       node* prev = NULL; 

       int count = 0; 

       /* Reverse first k nodes of linked list */
       while (count < k && current != NULL)  
       { 
           next = current->next; 
           current->next = prev; 
           prev = current; 
           current = next; 
           count++; 
       } 

       /* next is now a pointer to (k+1)th node  
          Recursively call for the list starting from current. 
          And make rest of the list as next of first node */
       if (next != NULL)  
          head->next = reverse(next, k); 

       // prev is now head of input list 
       return prev; 
}


