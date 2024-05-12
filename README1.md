# pw6 answering questions.
Questions
The destroy operation will be used when the programmer knows that he will no longer have to use a polynomial.
3.1 Explain why it is necessary to define (and think about using!) This operation.
3.2 Can we use the initialization operation to zero a polynomial? Justify the answer.
3.3 Is it necessary to use destroy on a local variable of a subroutine? Justify the answer.
3.4 Write the “destroy” subroutine.
-------------------------------------------------------------------------------------------------------------
                                            3.1 
The "destroy" operation is important because it helps free up the memory that a polynomial was using. When you're done using a polynomial and you don't need it anymore, it's essential to release the memory it was using. If you don't do this, it can cause memory leaks, which means the memory is used up but not available for other tasks.

                                            3.2 
Sure, the initialization operation can help set a polynomial to zero. In the code you have, the function createPolynomial() makes a new polynomial with a NULL. This basically means it starts with an empty polynomil. So, when you use createPolynomial() and put the result into a polynomial variable you already have, it's like resetting it to zero. That's because all the old monomials get removed.

                                            3.3
I don't think we need to use the "destroy" operation on a local variable in a subroutine. When the subroutine finishes, the computer automatically clears any memory used by the local variables, including the polynomial.