void List::insert(int toadd, int pos) {
  ListNode *p = head;
  int count = 0;
  while (p != NULL) {
    if (count == pos-1) {
      break;
    }
    p = p->next;
    count++;
  }
  if (p == NULL)
    return;

  ListNode *newadd = new ListNode;
  newadd->data = toadd;
  newadd->next = p->next;
  p->next = newadd;
}