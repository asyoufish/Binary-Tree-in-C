#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

struct Node* CreateNode(int);
void InsertOnSubtree(int, struct Node*);

struct Node* root = NULL;
struct Node* tmp = NULL;

struct Node* CreateNode(int num) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->Left = NULL;
	n->Right = NULL;
	n->Num = num;
	return n;
}

void Insert(int num) {
	if (root == NULL) {
		// tree is empty, just make a new node and 
		// make it the root node
		root = CreateNode(num);
		return;
	}
	if (num < root->Num) {
		if (root->Left == NULL) {
			root->Left = CreateNode(num);
			return;
		}
		InsertOnSubtree(num, root->Left);
	}
	else
	{
		if (root->Right == NULL) {
			root->Right = CreateNode(num);
			return;
		}
		InsertOnSubtree(num, root->Right);
	}
}

void InsertOnSubtree(int num, struct Node* top) {
	if (num < top->Num) {
		if (top->Left == NULL) {
			top->Left = CreateNode(num);
			return;
		}
		InsertOnSubtree(num, top->Left);
	}
	else {
		if (top->Right == NULL) {
			top->Right = CreateNode(num);
			return;
		}
		InsertOnSubtree(num, top->Right);
	}
}


// Strategy 1: Check first before trying to print
void Print1(struct Node* top) {

	// 1. Print the left branch first
	if (top->Left != NULL)
		Print1(top->Left);

	// 2. Print the top node itself
	printf("%d ", top->Num);

	// 3. Print the right branch
	if (top->Right != NULL)
		Print1(top->Right);
}

// Strategy 2: 
void Print2(struct Node* top) {
	if (top == NULL) return;

	// 1. Print the left branch first
	Print2(top->Left);

	// 2. Print the top node itself
	printf("%d ", top->Num);

	// 3. Print the right branch
	Print2(top->Right);
}