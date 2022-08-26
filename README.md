
A calculator that takes the numbers and operators to perform from lines of a text file "sums.txt" and performs those operations in the form of a stack

The program finally prints the element at the top of the stack



sample text file:

6
5
add
3
subtract


operations:

add	Take the top (x) and second top (y) numbers in the stack and add them together as x+y
subtract	Take the top (x) and second top (y) numbers in the stack and subtract them as x-y
multiply	Take the top (x) and second top (y) numbers in the stack and multiply them as x*y
divide	Take the top (x) and second top (y) numbers in the stack and divide them as x/y. Attempting to divide by zero should cause the program to print "ERROR: DIVIDE BY ZERO" and exit with no further action.
negate	Take the top (x) in the stack and negate it (change it's sign from positive to negative or vice versa)
square	Take the top (x) in the stack and square it as x2
