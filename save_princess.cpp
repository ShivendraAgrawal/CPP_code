#include <cstdio>
#define maxN 5010
using namespace std;
int n, V;
float f[maxN];
int a[110];
float p[110];
int i,j;
 
int main() {
	int TT;
	scanf("%d", &TT);
	while (TT--) {
		scanf("%d", &n), V = 0;
		for ( i = 1; i <= n; ++i) scanf("%d", a + i), V += a[i];
		for ( i = 1; i <= n; ++i) scanf("%f", p + i), p[i] /= 100;
		for ( i = 1; i <= (V - 1) / 2; ++i) f[i] = 0;
		f[0] = 1;
		for ( i = 1; i <= n; ++i) {
			for ( j = V / 2; j >= a[i]; --j) {
				f[j] = f[j-a[i]] * p[i] + f[j] * (1 - p[i]);
			}
			for ( j = 0; j < a[i]; ++j) f[j] *= 1 - p[i];
		}
		double ans = 0;
		for ( i = 0; i <= (V - 1) / 2; ++i) ans += f[i];
		printf("%.10f\n", 1 - ans);
	}
	return 0;
}