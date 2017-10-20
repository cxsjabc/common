#ifdef NOUSE_XI_LIST
// not use xi's list
// It's a pity that mysql's c interface header file defines list_free... functions,
// So I must define a macro for disable my list if you must to use mysql.
// You can set it on compile arguments: -DNOUSE_XI_LIST
#else
#ifndef LIST_H
#define LIST_H


struct list_node;
typedef struct list_node *LPNode;
typedef struct list_node *LHead;
typedef struct list_node  LNode;

struct list_node
{
	int 	data;
	LPNode  next;
};

LHead 	list_create(LPNode p);
LHead 	list_create_from_arr(int arr[], int size);

int		list_is_empty(LHead list);
int		list_is_last(LHead list, LPNode node);

LPNode	list_find(LHead list, int data);

// insert a node before the node
LPNode	list_insert(LHead list, LPNode node, int data);

void	list_delete(LHead list, int data);
LPNode	list_get_prev(LHead list, LPNode node);

int		list_append(LHead list, int data);

int		list_get(LHead list, int index, int *data);

void 	list_show(LHead list);
void 	list_free(LHead list);

LHead	list_merge(LHead list1, LHead list2);

#endif

#endif
