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

void		bst_make_empty(PTree tree);

PTreeNode	bst_find(PTree tree, int data);
int			bst_find_min(PTree tree);
int			bst_find_max(PTree tree);

PTree		bst_insert(PTree tree, int data);

void		bst_show(PTree tree);

void		bst_free(PTree tree);

#endif
