#include <stdlib.h>
#include "tree.h"

#include "common.h"


PTree bst_create(int data)
{
	PTree tree = (PTree)malloc(sizeof(TreeNode));
	if(!tree)
		return NULL;

	tree->left = tree->right = NULL;	
	tree->data = data;
	return tree;
}

PTree		bst_gen_no_sorted(int node_size, int data_min, int data_max)
{
	PTree t;
	int curr_data;
	int i = 0;

	if(node_size > data_max - data_min + 1)
		curr_data = data_min;
	else
		curr_data = data_max - node_size + 1;

	t = bst_create(curr_data);
	if(!t)
		goto alloc_fail;
	++i;
	while(i < node_size) {
		// TODO: queue save the node, then insert in left or right			
		++i;
	}	

alloc_fail:
	
	return NULL;
}

PTree		bst_gen(int node_size, int data_min, int data_max)
{
	return NULL;
}

PTree		tree_create(PTree *root)
{
	PTree t;
	int data;

	scanf("%d", &data);
	if(data == -1)
		return NULL;
	t = (PTree)malloc(sizeof(TreeNode));
	if(!t)
		return NULL;
	t->data = data;
	t->left = t->right = NULL;
	
	tree_create(&(t->left));
	tree_create(&(t->right));
	*root = t;
	return t;
}

void bst_make_empty(PTree tree)
{
	if(tree == NULL)
		return;
	
	bst_make_empty(tree->left);
	bst_make_empty(tree->right);
	free(tree);
}

PTreeNode	bst_find(PTree tree, int data)
{
	if(tree == NULL)
		return NULL;
	if(tree->data == data)
		return tree;
	
	if(tree->data < data)
		return bst_find(tree->right, data);
	else
		return bst_find(tree->left, data);
}

int			bst_find_min(PTree tree)
{
	if(tree->left == NULL)
		return tree->data;
	else
		return bst_find_min(tree->left);
}

int			bst_find_max(PTree tree)
{
	if(tree->right == NULL)
		return tree->data;
	else
		return bst_find_max(tree->right);
}

int			bst_get_depth(PTree tree)
{
	if(tree == NULL)
		return 0;
	return 1 + MAX(bst_get_depth(tree->left), bst_get_depth(tree->right));
}

PTree		bst_insert(PTree tree, int data)
{
	if(tree == NULL) {
		PTree root = (PTree)malloc(sizeof(Tree));
		if(!root)
			return NULL;
		
		root->data = data;
		root->left = root->right = NULL;
		tree = root;
//		LOG_HERE;
	}
	else if(tree->data == data)
		return tree;
	else if(tree->data < data) {
		tree->right = bst_insert(tree->right, data);
	} else {
		tree->left = bst_insert(tree->left, data);
	}
	//printf("tree:%p\n", tree);
	return tree;	
}

void		bst_show(PTree tree)
{
	if(tree == NULL)
		return;
	printf("%d ", tree->data);
	bst_show(tree->left);
	bst_show(tree->right);
}

void		bst_free(PTree tree)
{
	if(tree) {
		bst_free(tree->left);
		bst_free(tree->right);
		free(tree);
	}
}
