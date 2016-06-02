#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "bstree.h"

int getrand(int min, int max) {
	return (double)rand()/(RAND_MAX+1.0)*(max-min)+min;
}

double wtime() {
	struct timespec t;
	clock_gettime(CLOCK_REALTIME, &t);
	return (double)t.tv_sec + (double)t.tv_nsec * 1E-9;
}

struct bstree *bstree_create (char *key, int value) {
	struct bstree *node;
	node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

void bstree_add (struct bstree *tree, char *key, int value) {
	struct bstree *parent, *node;
	if (tree == NULL)
		return;
	for (parent = tree; tree != NULL; ) {
		parent = tree;
		if (strcmp(key, tree -> key) < 0)
			tree = tree->left;
		else
			if (strcmp(key, tree -> key) > 0)
				tree = tree->right;
			else
				return;
	}
	node = bstree_create(key, value);
	if (key < parent->key)
		parent->left = node;
	else
		parent ->right = node;
}

struct bstree *bstree_lookup(struct bstree *tree, char *key) {
	while (tree != NULL) {
		if (strcmp(key, tree -> key) == 0) {
			return tree;
		}
		else
			if (strcmp(key, tree -> key) < 0) {
				tree = tree -> left;
			}
			else {
				tree = tree -> right;
			}
	}
	return tree;
}

struct bstree *bstree_min(struct bstree *tree) {
	if (tree == NULL)
		return NULL;
	while (tree -> left != NULL)
		tree = tree -> left;
	return tree;
}

struct bstree *bstree_max(struct bstree *tree) {
	if (tree == NULL)
		return NULL;
	while (tree -> right != NULL)
		tree = tree -> right;
	return tree;
}