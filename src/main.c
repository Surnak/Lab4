#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "bstree.h"

int main()
{
	srand(time(0));
	struct bstree *tree;
	char word[100], *w;
	char **words = malloc(200000 * sizeof(char *));
	int i;
	double t;

	FILE *iwords = fopen("dictionary3.txt", "r");
	
		for (i = 0; i < 200000; i++) {
			fscanf(iwords, "%s", word);
			words[i] = malloc(sizeof(word));
			words[i] = strdup(word);
		}
	fclose(iwords);

	tree = bstree_create(words[0], 0);
	for (i = 2; i <= 200000; i++) {
		bstree_add(tree, words[i - 1], i - 1);
		if (i % 10000 == 0) {
			w = words[getrand(0, i - 1)];
			t = wtime();
			bstree_lookup(tree, w);
			t = wtime() - t;
			FILE *x = fopen("bstree.dat", "a+");
			fprintf(x, "%d\t%.9f\n", i, t);
			fclose(x);
		}
	}

	for (i = 0; i < 200000; i++)
		free(words[i]);
	free(words);

	return EXIT_SUCCESS;
}