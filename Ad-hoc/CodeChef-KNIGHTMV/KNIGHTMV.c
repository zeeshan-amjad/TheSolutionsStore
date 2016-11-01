#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int t;
	scanf ("%d", &t);
	getchar();
	while (t--) {
		char *moves;
		size_t len = 11;
		moves = malloc (len * sizeof (char));
		getline (&moves, &len, stdin);
		
		if (moves[0] < 'a' || moves[0] > 'h' || moves[3] < 'a' || moves[3] > 'h') {
			printf ("Error\n");
			continue;
		}

		if (moves[1] < '1' || moves[1] > '8' || moves[4] < '1' || moves[4] > '8' || moves[2] != '-' || strlen (moves) != 6) {
			printf ("Error\n");
			continue;
		}

		if (abs (moves[0] - moves[3]) == 1 && abs (moves[1] - moves[4]) == 2) {
			printf ("Yes\n");
			continue;
		}

		if (abs (moves[0] - moves[3]) == 2 && abs (moves[1] - moves[4]) == 1) {
			printf ("Yes\n");
			continue;
		}

		printf ("No\n");

	}
	return 0;
}
