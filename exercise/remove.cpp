void List::remove(int pos) {
  ListNode *p = head;
  ListNode *parent;
  int count = 0;

  while (p != NULL) {
    if (count == pos) {
      break;
    }
    parent = p;
    p = p->next;
    count++;
  }

  if (p == NULL)
    return;

  parent->next = p->next;
  p->next = NULL;
  delete p;
}