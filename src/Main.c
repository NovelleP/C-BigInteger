/*
 * Main.c
 *
 *  Created on: 18 feb. 2020
 *      Author: alberto
 */

#include "BigInteger.h"

int main() {
	bool m1[] = {true, false, false};
	bool m2[] = {true, false};
	bool m3[] = {true, true};

	BigInteger *b1 = initBigInteger(false, m1, 3);
	BigInteger *b2 = initBigInteger(true, m2, 2);
	BigInteger *result1 = add(b1, b2);

	printNumber(b1);
	printf("\n+\n");
	printNumber(b2);
	printf("\n--------------\n");
	printNumber(result1);

	printf("\n\n**************\n\n");

	BigInteger *b3 = initBigInteger(true, m3, 2);
	BigInteger *result2 = add(b3, b3);

	printNumber(b3);
	printf("\n+\n");
	printNumber(b3);
	printf("\n--------------\n");
	printNumber(result2);

	return 0;
}
