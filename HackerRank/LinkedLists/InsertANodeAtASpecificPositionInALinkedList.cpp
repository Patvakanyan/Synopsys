SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode *head = llist;
    
    for(size_t i = 0; i < position - 1; ++i)
        llist = llist->next;   
    SinglyLinkedListNode *next = llist->next;
    llist->next = new SinglyLinkedListNode(data);
    llist->next->next = next;
    return head;
}
