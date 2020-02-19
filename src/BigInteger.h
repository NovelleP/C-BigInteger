/*
 * BigInteger.h
 *
 *  Created on: 18 feb. 2020
 *      Author: alberto
 */

#include <stdbool.h>

#ifndef SRC_BIGINTEGER_H_
#define SRC_BIGINTEGER_H_

typedef struct {
	bool isNegative;
	bool *magnitude;
	int mag_length;
} BigInteger;

BigInteger *initBigInteger(bool isNegative, bool *magnitude, int mag_length);

BigInteger *initBigIntegerFrom2Complement(bool isNegative, bool *magnitude, int mag_length);

BigInteger *initWithString(char *value);

bool *to2Complement(bool *magnitude, int mag_length);

bool *to1Complement(bool *magnitude, int mag_length);

BigInteger *add(BigInteger *a, BigInteger *b);

void printBits(BigInteger* bigInteger);


#endif /* SRC_BIGINTEGER_H_ */
