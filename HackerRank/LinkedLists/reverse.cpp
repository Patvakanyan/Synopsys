DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode *next = nullptr;
    DoublyLinkedListNode *prev = next;
    DoublyLinkedListNode *current = llist;
    if(llist)
    {
        next = llist->next;
        prev = llist;
        llist->next = llist->prev;
        llist->prev = next;
        llist = next;
    }
    while(llist)
    {
        next = llist->next;
        llist->next = prev;
        llist->prev = next;
        prev = llist;
        llist = next;
        current = prev;
    }
    return current;
}
