/*
 * BigInteger.c
 *
 *  Created on: 18 feb. 2020
 *      Author: alberto
 */

#include "BigInteger.h"

BigInteger *initBigInteger(bool isNegative, bool *magnitude, int mag_length) {
	BigInteger *bigInteger = malloc(sizeof(BigInteger));

	if (isNegative) {
		mag_length += 1;
		magnitude = to2Complement(magnitude, mag_length);
	}

	bigInteger->isNegative = isNegative;
	bigInteger->magnitude = magnitude;
	bigInteger->mag_length = mag_length;

	return bigInteger;
}

BigInteger *initBigIntegerFrom2Complement(bool isNegative, bool *magnitude, int mag_length) {
	BigInteger *bigInteger = malloc(sizeof(BigInteger));

	bigInteger->isNegative = isNegative;
	bigInteger->magnitude = magnitude;
	bigInteger->mag_length = mag_length;

	return bigInteger;
}

bool *to2Complement(bool *magnitude, int mag_length) {
	bool *c2 = to1Complement(magnitude, mag_length);

	bool carry = true;
	while(--mag_length >= 0) {
		c2[mag_length] ^= carry;
		carry = carry == 1 && c2[mag_length] == 0;
	}

	return c2;
}

bool *to1Complement(bool *magnitude, int mag_length) {
	bool *c1 = malloc(mag_length * sizeof(bool));
	c1[0] = true;
	while(--mag_length > 0) {
		c1[mag_length] = magnitude[mag_length-1] ^ 1;
	}

	return c1;
}

BigInteger *add(BigInteger *a, BigInteger *b) {
	int max_length = (a->mag_length > b->mag_length)? a->mag_length : b->mag_length;
	bool isNegative = false;
	bool *magnitude = calloc(max_length, sizeof(max_length));
	int idx = max_length - 1;
	int idx_a = a->mag_length - 1;
	int idx_b = b->mag_length - 1;
	bool carry = false;

	while(idx_a >= 0 && idx_b >= 0) {
		magnitude[idx] = a->magnitude[idx_a] ^ b->magnitude[idx_b] ^ carry;
		carry = (a->magnitude[idx_a] && b->magnitude[idx_b] || a->magnitude[idx_a] && carry || b->magnitude[idx_b] && carry);
		idx--;
		idx_a--;
		idx_b--;

	}

	while(idx_a >= 0) {
		magnitude[idx] = a->magnitude[idx_a] ^ b->isNegative ^ carry;
		carry = (a->magnitude[idx_a] && b->isNegative || a->magnitude[idx_a] && carry || b->isNegative && carry);
		idx--;
		idx_a--;
	}

	while(idx_b >= 0) {
		magnitude[idx] = a->isNegative ^ b->magnitude[idx_b] ^ carry;
		carry = (a->isNegative && b->magnitude[idx_b] || a->isNegative && carry || b->magnitude[idx_b] && carry);
		idx--;
		idx_b--;
	}

	isNegative = a->isNegative ^ b->isNegative ^ carry;

	return initBigIntegerFrom2Complement(isNegative, magnitude, max_length);

}

void printNumber(BigInteger* bigInteger) {
	printf("%d ", bigInteger->isNegative);
	int i;
	for(i = 0; i < bigInteger->mag_length; i++) {
		printf("%d", bigInteger->magnitude[i]);
	}
}


