
bool floydCycleRemoval(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL && fast != slow)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL || fast->next == NULL)
    {
        //No cycle present
        return false;
    }

    if (fast->next == head)
    {
        fast->next = NULL;
        return true;
    }

    slow = head;
    fast = fast->next;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return true;
}