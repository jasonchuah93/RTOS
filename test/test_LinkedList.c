#include "unity.h"
#include "LinkedList.h"
#include <malloc.h>

void setUp(){}
void tearDown(){}

/**
	Initialize linkedlist
	
     HEAD   --------   TAIL
     --->  |  NULL |  <----
            --------
**/
void test_createLinkedList_should_return_initialized_object(void){
	LinkedList list;
	createLinkedList(&list);
	TEST_ASSERT_NULL(list.head);
	TEST_ASSERT_NULL(list.tail);
	TEST_ASSERT_EQUAL(0,list.length);
}

/**
	Add first element into linkedlist
	  HEAD            HEAD         
	-------         --------      ------- 
   |  NULL | ---->  | ele1 |-----| NULL |
    -------         --------      -------
**/
void test_listAddFirst_should_add_first_element_into_linkedList(){
	LinkedList list;
	createLinkedList(&list);
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	
}

/**
	Add elements into linkedlist
	  HEAD            HEAD                                       TAIL
	-------         ------     -----      -----      ------     ------     -----
   |  NULL | ---->  |ele5|-----|ele4|-----|ele3|-----|ele2|-----|ele1|-----|NULL|
    -------         ------     -----      ------     ------     ------     ------
**/
void test_listAddFirst_should_add_elements_into_linkedList(){
	LinkedList list;
	createLinkedList(&list);
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	Element ele2 = {.next = (Element *)NULL, .data = (Element *)5};
	Element ele3 = {.next = (Element *)NULL, .data = (Element *)10};
	Element ele4 = {.next = (Element *)NULL, .data = (Element *)15};
	Element ele5 = {.next = (Element *)NULL, .data = (Element *)20};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele2,list);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(5,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele3,list);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(10,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele4,list);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(15,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele5,list);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(20,list->head->data);
	TEST_ASSERT_EQUAL(15,list->head->next->data);
	TEST_ASSERT_EQUAL(10,list->head->next->next->data);
	TEST_ASSERT_EQUAL(5,list->head->next->next->next->data);
	TEST_ASSERT_EQUAL(1,list->head->next->next->next->next->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head->data,list->tail->data);
	TEST_ASSERT_EQUAL(list->head->next->next->next->next->data,list->tail->data);
	TEST_ASSERT_EQUAL(5,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
}

/**
	Remove elements into linkedlist
    Add ele1     
      HEAD           HEAD
	-------         ------    -----
   |  NULL | ---->  |ele1|----|NULL|
    -------         ------    ------
	Remove ele1
	 HEAD                                  
	------     
    |NULL|
    ------     
**/
void test_listRemoveFirst_should_remove_first_element_from_linkedList(){
	LinkedList list;
	createLinkedList(&list);
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listRemoveFirst(list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(NULL,list->head);
	TEST_ASSERT_EQUAL(NULL,list->tail);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
}

/**
	Add elements into linkedlist
	  HEAD            HEAD                                       TAIL
	-------         ------     -----      -----      ------     ------     -----
   |  NULL | ---->  |ele5|-----|ele4|-----|ele3|-----|ele2|-----|ele1|-----|NULL|
    -------         ------     -----      ------     ------     ------     ------
	
	Remove element 5 from head
	HEAD                             TAIL
   ------     -----      -----      ------     -----
   |ele4|-----|ele3|-----|ele2|-----|ele1|-----|NULL|
   ------     -----      ------     ------     ------    
	
	Remove element 4 from head
	HEAD                  TAIL
   ------     -----      -----      -----     
   |ele3|-----|ele2|-----|ele1|-----|NULL|
   ------     -----      ------     ------       
	
	Remove element 3 from head
	HEAD      TAIL
   ------     -----      ----- 
   |ele2|-----|ele1|-----|NULL|
   ------     -----      ------
   
   Remove element 2 from head
	HEAD      
   ------     ----- 
   |ele1|-----|NULL|
   ------     ------ 
   
   Remove element 1 from head
	HEAD      
   ------     
   |NULL|
   ------     
**/

void test_listRemoveFirst_should_remove_elements_from_linkedList(){
	LinkedList list;
	createLinkedList(&list);
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	Element ele2 = {.next = (Element *)NULL, .data = (Element *)5};
	Element ele3 = {.next = (Element *)NULL, .data = (Element *)10};
	Element ele4 = {.next = (Element *)NULL, .data = (Element *)15};
	Element ele5 = {.next = (Element *)NULL, .data = (Element *)20};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele2,list);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(5,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele3,list);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(10,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele4,list);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(15,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele5,list);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(20,list->head->data);
	TEST_ASSERT_EQUAL(15,list->head->next->data);
	TEST_ASSERT_EQUAL(10,list->head->next->next->data);
	TEST_ASSERT_EQUAL(5,list->head->next->next->next->data);
	TEST_ASSERT_EQUAL(1,list->head->next->next->next->next->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head->data,list->tail->data);
	TEST_ASSERT_EQUAL(list->head->next->next->next->next->data,list->tail->data);
	TEST_ASSERT_EQUAL(5,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listRemoveFirst(list); //Removed 20 from the head
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(15,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveFirst(list); //Removed 15 from the head
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(10,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveFirst(list); //Removed 10 from the head
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(5,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveFirst(list); //Removed 5 from the head
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveFirst(list); //Removed 1 from the head
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(NULL,list->head);
	TEST_ASSERT_EQUAL(NULL,list->tail);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
}

/**
	Add first element into linkedlist
	  HEAD            HEAD         
	-------         --------      ------- 
   |  NULL | ---->  | ele1 |-----| NULL |
    -------         --------      -------
**/
void test_listAddLast_should_add_first_element_into_linkedList(){
	LinkedList list;
	createLinkedList(&list);
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	
	listAddLast(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
}

/**
	Add elements into linkedlist
	  HEAD            HEAD                                       TAIL
	-------         ------     -----      -----      ------     ------     -----
   |  NULL | ---->  |ele1|-----|ele2|-----|ele3|-----|ele4|-----|ele5|-----|NULL|
    -------         ------     -----      ------     ------     ------     ------
**/
void test_listAddLast_should_add_elements_into_linkedList(){
	LinkedList list;
	createLinkedList(&list);
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	Element ele2 = {.next = (Element *)NULL, .data = (Element *)5};
	Element ele3 = {.next = (Element *)NULL, .data = (Element *)10};
	Element ele4 = {.next = (Element *)NULL, .data = (Element *)15};
	Element ele5 = {.next = (Element *)NULL, .data = (Element *)20};
	
	listAddLast(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddLast(&ele2,list);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(5,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NOT_NULL(list->tail->next);
	
	listAddLast(&ele3,list);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(10,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NOT_NULL(list->tail->next);
	
	listAddLast(&ele4,list);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(15,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NOT_NULL(list->tail->next);
	
	listAddLast(&ele5,list);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(20,list->tail->data);
	TEST_ASSERT_EQUAL(15,list->tail->next->data);
	TEST_ASSERT_EQUAL(10,list->tail->next->next->data);
	TEST_ASSERT_EQUAL(5,list->tail->next->next->next->data);
	TEST_ASSERT_EQUAL(1,list->tail->next->next->next->next->data);
	TEST_ASSERT_NOT_EQUAL(list->head->data,list->tail->data);
	TEST_ASSERT_EQUAL(list->head->data,list->tail->next->next->next->next->data);
	TEST_ASSERT_EQUAL(5,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NOT_NULL(list->tail->next);
}

void test_listRemoveLast_should_remove_first_element_from_linkedList(){
	LinkedList list;
	createLinkedList(&list);
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	
	listAddLast(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listRemoveLast(list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(NULL,list->head);
	TEST_ASSERT_EQUAL(NULL,list->tail);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
}

/**
	Add elements into linkedlist
	  HEAD            HEAD                                       TAIL
	-------         ------     -----      -----      ------     ------     -----
   |  NULL | ---->  |ele1|-----|ele2|-----|ele3|-----|ele4|-----|ele5|-----|NULL|
    -------         ------     -----      ------     ------     ------     ------
	
	Remove element 5 from tail
	HEAD                             TAIL
   ------     -----      -----      ------     -----
   |ele1|-----|ele2|-----|ele3|-----|ele4|-----|NULL|
   ------     -----      ------     ------     ------    
	
	Remove element 4 from tail
	HEAD                  TAIL
   ------     -----      -----      -----     
   |ele1|-----|ele2|-----|ele3|-----|NULL|
   ------     -----      ------     ------       
	
	Remove element 3 from tail
	HEAD      TAIL
   ------     -----      ----- 
   |ele1|-----|ele2|-----|NULL|
   ------     -----      ------
   
   Remove element 2 from tail
	HEAD      
   ------     ----- 
   |ele1|-----|NULL|
   ------     ------ 
   
   Remove element 1 from tail
	HEAD      
   ------     
   |NULL|
   ------     
**/
void test_listRemoveLast_should_remove_elements_from_linkedList(){
	LinkedList list;
	createLinkedList(&list);
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	Element ele2 = {.next = (Element *)NULL, .data = (Element *)5};
	Element ele3 = {.next = (Element *)NULL, .data = (Element *)10};
	Element ele4 = {.next = (Element *)NULL, .data = (Element *)15};
	Element ele5 = {.next = (Element *)NULL, .data = (Element *)20};
	
	listAddLast(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddLast(&ele2,list);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(5,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NOT_NULL(list->tail->next);
	
	listAddLast(&ele3,list);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(10,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NOT_NULL(list->tail->next);
	
	listAddLast(&ele4,list);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(15,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NOT_NULL(list->tail->next);
	
	listAddLast(&ele5,list);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(20,list->tail->data);
	TEST_ASSERT_EQUAL(15,list->tail->next->data);
	TEST_ASSERT_EQUAL(10,list->tail->next->next->data);
	TEST_ASSERT_EQUAL(5,list->tail->next->next->next->data);
	TEST_ASSERT_EQUAL(1,list->tail->next->next->next->next->data);
	TEST_ASSERT_NOT_EQUAL(list->head->data,list->tail->data);
	TEST_ASSERT_EQUAL(list->head->data,list->tail->next->next->next->next->data);
	TEST_ASSERT_EQUAL(5,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NOT_NULL(list->tail->next);
	
	listRemoveLast(list); //Removed 20 from the tail 
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(15,list->tail->data);
	TEST_ASSERT_EQUAL(10,list->tail->next->data);
	TEST_ASSERT_EQUAL(5,list->tail->next->next->data);
	TEST_ASSERT_EQUAL(1,list->tail->next->next->next->data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(list->head->data,list->tail->next->next->next->data);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveLast(list); //Removed 15 from the tail 
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(10,list->tail->data);
	TEST_ASSERT_EQUAL(5,list->tail->next->data);
	TEST_ASSERT_EQUAL(1,list->tail->next->next->data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(list->head->data,list->tail->next->next->data);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveLast(list); //Removed 10 from the tail 
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(5,list->tail->data);
	TEST_ASSERT_EQUAL(1,list->tail->next->data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(list->head->data,list->tail->next->data);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveLast(list); //Removed 5 from the tail 
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(list->head->data,list->tail->data);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveLast(list); //Removed 1 from the tail 
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(NULL,list->tail);
	TEST_ASSERT_EQUAL(NULL,list->head);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
}



