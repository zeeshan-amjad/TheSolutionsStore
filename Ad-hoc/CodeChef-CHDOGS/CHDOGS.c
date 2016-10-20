#include <stdio.h>
 
int main () {
	int t;
	scanf ("%d", &t);
	while (t--) {
		long double s, v, ans;
		scanf ("%Lf %Lf", &s, &v);
		ans = (2 * s) / (3 * v);
		printf ("%0.9Lf\n", ans);
	}
	return 0;
}
