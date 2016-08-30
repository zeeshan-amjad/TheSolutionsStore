#include <stdio.h>

int main(void) {
	int len = 1, m = 1, a[100001], n, i = 0;
	scanf ("%d", &n);
	for (i = 0; i < n; i++) 
	    scanf ("%d", &a[i]);
	    
	for (i = 0; i < n - 1; i++) {
	    if (a[i + 1] >= a[i])
	        len++;
	    else
	        len = 1;
	    if (len > m)
	        m = len;
	}
	
	printf ("%d", m);
	return 0;
}
