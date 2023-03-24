#include <stdio.h>
#include "BinaryTree.h"

int main()
{
    printf("Binary Tree\n");

    printf("Please enter a bunch of numbers. -100 to stop\n");

	int num;
	while (true)
	{
		scanf_s("%d", &num);
		if (num == -100)
			break;
		Insert(num);
	}

	// Walk the tree and show all the numbers in sorted order
	Print1(root);
	printf("\n");
	Print2(root);

}
