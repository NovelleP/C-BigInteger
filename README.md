# C-BigInteger
## Big integer for C language
This code allows work with integers that don't fit in types defined in C. It represents numbers in binary two's complement with array of booleans.

### Example
  ```
  int lenNum1 = 3;
  int lenNum2 = 2;
  bool binaryNum1[] = {true, true, false}; // 6
  bool binaryNum2[] = {true, false}; // 2
  bool isNegative1 = false;
  bool isNegative2 = true;
  
  BigInteger *bigInteger1 = initBigInteger(isNegative1, binaryNumber1, lenNum1); // 6
  BigInteger *bigInteger2 = initBigInteger(isNegative2, binaryNumber2, lenNum2); // -2
  
  BigInteger *result = add(bigInteger1, bigInteger2); // 6 - 2 = 4 = 0 100(two's complement);
  ```
