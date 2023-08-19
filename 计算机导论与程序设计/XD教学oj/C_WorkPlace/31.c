#include <stdio.h>

int main(void)
{
	int a, b, gcd, i, min, max;

	scanf("%d %d", &a, &b);

	if (a >= b) {
		max = a;
		min = b;
	}
	else {
		max = b;
		min = a;
	}

	if (min == 0 ) {
		gcd = max;
	}
    else if ( max % min == 0){
        gcd = min ;
    }
	else {
		for (i = 1; i <= min; i++) {
			if (min % i == 0 && max % i == 0) { // 或辗转相除
				gcd = i;
			}
		}
	}

	printf("%d", gcd);

	return 0;
}     