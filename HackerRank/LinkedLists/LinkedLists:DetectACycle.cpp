bool has_cycle(Node* head) {
    Node *fast = head;
    Node *slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}

