#include <stdio.h>

/*
n is number of elements in array
connect it to the times of iteration done in the function

O(1)
O(log2n)
O(n)
O(nlog2n)
O(n2)

rules of big O
linear search: 10 elements 10 iterations: O(n)
binary : 10 elements 4 iterations: 
    n/ 2^I = 1
    n = 2^I
    log2n = I 
    O(log2 n)

nested statments multiply

ignore constants O( c* f(n))
ignore small powers O(n^a + n^(a+1)) = O(n^a)
logs O (max (n, log n)) = O(n)
     O (max (nlog2n, n)) = O(nlog2n)
     O (max (nlog2n, n^2)) = O(n^2)


log2n > sqrt n > n > nlog2 n > n^2 > 2^n > n!

*/