#include <stdio.h>
typedef struct _dnode{ int key; struct _dnode *prev; struct _dnode *next;} dnode;
extern dnode *head;extern dnode *tail;extern void dlist_init(void);extern void dlist_print(dnode *p);extern dnode *dnode_find(int k);extern dnode *dnode_insert(int k, int t);extern int dnode_delete(int k);extern dnode *dnode_ptr_insert(int k, dnode *t);extern int dnode_ptr_delete(dnode *p);extern dnode *ordered_insert(int k);extern void all_dnodes_delete();
void main(){ dlist_init();  ordered_insert(10); ordered_insert(5); ordered_insert(8); ordered_insert(3); ordered_insert(1);
 printf("Initial Doubly Linked List is \n"); dlist_print(head->next);  printf("Find 4 is %ssuccessful\n", dnode_find(4) == tail ? "un" : "");
 dnode *t; t = dnode_find(5); printf("Find 5 is %ssuccessful\n", t == tail ? "un" : "");
 printf("Inserting 7 before 5\n"); dnode_ptr_insert(7, t); dlist_print(head->next);
 t = dnode_find(3); printf("Deleting 3\n"); dnode_ptr_delete(t); dlist_print(head->next);
 printf("Inserting node 2 before 10\n"); dnode_insert(2, 10); dlist_print(head->next);
 printf("Deleting 2\n"); if (!dnode_delete(2))  printf(" deleting 2 is unsuccessful\n"); dlist_print(head->next);
 printf("Deleting 1\n"); dnode_delete(1); dlist_print(head->next);
 printf("Inserting 15 at first\n"); dnode_ptr_insert(15, head->next); dlist_print(head->next);
 printf("Deleting all nodes\n"); all_dnodes_delete(); dlist_print(head->next);}
