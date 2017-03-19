#include <stdlib.h>
#include "tree.h"

#include "common.h"


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
