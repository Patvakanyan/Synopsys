DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode *head = llist;
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    if (!llist || data < llist->data) {
        newNode->next = llist;
        if (llist)
            llist->prev = newNode;
        return newNode;
    }
    while(llist->next && llist->next->data < data)
        llist = llist->next;
    DoublyLinkedListNode *next = llist->next;
    llist->next = newNode;
    newNode->prev = llist;
    newNode->next = next;
    return head; 
}
