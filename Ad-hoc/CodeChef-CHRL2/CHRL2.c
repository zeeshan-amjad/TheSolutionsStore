#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int getpos (int p[4][100005], int i, int l, int val, int k) {
    if (k == l)
        return -1;
    while (p[i][k] < val) {
        k++;
        if (k == l)
            return -1;
    }
    return k + 1;
}

int main (void) {
	char a[100005];
	scanf ("%s", a);
	int i, c = 0, h = 0, e = 0, f = 0, s = strlen (a), position[4][100005];
	for (i = 0; i < s; ++i) 
	    switch (a[i]) {
	        case 'C': position[0][c++] = i;
	                  break;
	        case 'H': position[1][h++] = i;
	                  break;
	        case 'E': position[2][e++] = i;
	                  break;
	        case 'F': position[3][f++] = i;
	                  break;
	    }
	    
	if (!c || !h || !e || !f) {
	    printf ("0");
	    return 0;
	}
	int j = 0, k = 0, l = 0, ans = 0;    
	for (i = 0; i < c; ++i) {
	    j = getpos (position, 1, h, position[0][i], j);
	    if (j == -1)
	        break;
	    k = getpos (position, 2, e, position[1][j], k);
	    if (k == -1)
	        break;
	    l = getpos (position, 3, f, position[2][k], l);
	    if (l == -1)
	        break;
	    ans++;
	}    
	    
	printf ("%d", ans);
	return 0;
}
