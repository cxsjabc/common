#ifndef NOUSE_XI_LIST
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "list.h"

LHead 	list_create(LPNode p)
{
	LHead head = (LHead)malloc(sizeof(LNode));
	LPNode node;
	if(!head)
		return NULL;

	head->next = NULL;
	if(p) {
		node = (LPNode)malloc(sizeof(LNode));
		if(!node)
			goto fail;
		head->next = node;
		node->data = p->data;
		node->next = NULL;
	}

	return head;
fail:
	if(node)
		free(node);
	if(head)
		free(head);
	return NULL;
}

LHead 	list_create_from_arr(int arr[], int size)
{
	LHead head;
	int i = 0;

	head = (LHead)malloc(sizeof(LNode));
	if(!head)
		return NULL;

	head->next = NULL;
	while(i < size) {
		if(!list_append(head, arr[i]))
			goto fail;
		++i;			
	}

	return head;
fail:
	if(head)
		list_free(head);
	return NULL;
}

int		list_is_empty(LHead list)
{
	return (list->next == NULL);
}


int		list_is_last(LHead list, LPNode node)
{
	return node->next == NULL;
}

LPNode	list_find(LHead list, int data)
{
	LPNode node = list->next;
	while(node) {
		if(node->data == data)
			return node;
		node = node->next;
	}
	return NULL;	
}

LPNode	list_insert(LHead list, LPNode node, int data)
{
	LPNode prev = list_get_prev(list, node);
	LPNode new_node = (LPNode)malloc(sizeof(LNode));
	
	if(!new_node)
		return NULL;
	if(prev == NULL)
		prev = list;

	new_node->next = list->next;	
	prev->next = new_node;
	new_node->data = data;

	return new_node;
}

void	list_delete(LHead list, int data)
{
	LPNode node = list->next;
	LPNode prev = list;

	while(node) {
		if(node->data == data) {
			LPNode next = node->next;
			prev->next = next;
			free(node);
			node = next;
		} else {
			prev = node;
			node = node->next;
		}
	}
}

LPNode	list_get_prev(LHead list, LPNode node)
{
	LPNode prev = NULL;
	while(list->next) {
		if(list->next == node) {
			prev = list;
			break;
		}
		else
			list = list->next;
	}	
	return prev;
}

int		list_get(LHead list, int index, int *data)
{
	int i = 1;
	list = list->next;

	while(i < index && list) {
		list = list->next;
		++i;
	}
	if(i == index) {
		*data = list->data;
		return 1;
	}
	else
		return 0;
}

void list_show(LHead list)
{
	LPNode node = list->next;
	while(node) {
		printf("%d ", node->data);
		node = node->next;	
	}
	printf("\n");
}

int		list_append(LHead list, int data)
{
	LPNode node = list;
	LPNode append_node;

	while(node->next != NULL) {
		node = node->next;
	}

	append_node = (LPNode)malloc(sizeof(LNode));
	if(!append_node)
		goto label_alloc_fail;
	append_node->data = data;
	append_node->next = NULL;

	node->next = append_node;
	return 1;

label_alloc_fail:
	return 0;
}

void 	list_free(LHead list) 
{
	LPNode curr = list;
	LPNode next = list->next;
	while(next) {
		LPNode temp = next;
		free(curr);
		curr = temp;
		next = temp->next;
	}
	free(curr);
}

// the list is asc
LHead		list_merge(LHead list1, LHead list2)
{
	LPNode node1, node2;
	LHead	list;	
	int append_ret;
	
	//printf("before list create\n");
	list = (LHead)list_create(NULL);
	if(!list)
		goto label_alloc_fail;

	//printf("after list create\n");
	node1 = list1->next;
	node2 = list2->next;
	
	//printf("before merge...\n");
	while(node1 != NULL && node2 != NULL) {
		//printf("node1->data:%d, node2->data:%d\n", node1->data, node2->data);
		if(node1->data <= node2->data) {
			append_ret = list_append(list, node1->data);
			if(!append_ret)
				goto label_alloc_fail;
			node1 = node1->next;
		}
		else {
			append_ret = list_append(list, node2->data);
			if(!append_ret)
				goto label_alloc_fail;
			node2 = node2->next;
		}
	}

	//printf("after merge...\n");
	if(node1 == NULL) {
		while(node2 != NULL) {
			append_ret = list_append(list, node2->data);
			if(!append_ret)
				goto label_alloc_fail;
			//printf("append data:%d\n", node2->data);
			node2 = node2->next;
		}
	}

	//printf("after merge1...\n");
	if(node2 == NULL) {
		while(node1 != NULL) {
			append_ret = list_append(list, node1->data);
			if(!append_ret)
				goto label_alloc_fail;
			//printf("append data:%d\n", node1->data);
			node1 = node1->next;
		}
	}
	
	return list;

label_alloc_fail:
	if(list)
		list_free(list);
	return NULL;	

}
#endif
