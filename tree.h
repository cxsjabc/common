#ifndef TREE_H
#define TREE_H


typedef struct _TreeNode
{
	int data;
	struct _TreeNode * 	left;
	struct _TreeNode *	right;
}TreeNode;

typedef TreeNode * 	PTreeNode;
typedef TreeNode * 	PTree;

typedef TreeNode 		Tree;

PTree		bst_create(int data);

PTree		bst_insert(PTree tree, int data);

PTreeNode	bst_find(PTree tree, int data);
int			bst_find_min(PTree tree);
int			bst_find_max(PTree tree);

void		bst_make_empty(PTree tree);

void		bst_show(PTree tree);

void		bst_free(PTree tree);

#endif
