#ifndef LinkedList_H
#define LinkedList_H

typedef struct Element_t{
	struct Element_t *next;
	void *data;
}Element;

typedef struct{
	Element *head;
	Element *tail;
	int length;
}LinkedList;

void createLinkedList(LinkedList *list);
void listAddFirst(Element *newElement, LinkedList *list);
Element *listRemoveFirst(LinkedList *list);
Element *listAddLast(Element *newElement, LinkedList *list);
Element *listRemoveLast(LinkedList *list);
#endif // LinkedList_H
