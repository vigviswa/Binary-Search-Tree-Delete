# Binary-Search-Tree-Delete
Delete an Element from a binary search tree and replace it with its predecessor


The List assumes the Following values to be entered into the tree:

1, 90, 65, 9, 7, 3, 2, 21, 12, 45, 33, 31, 56, 76, 87

# Algorithm

The algorithm used for sorting is the Bubble sort algorithm. The algorithm is used for
sorting any given data structure elements in an ascending or descending order.
Suppose we have an array of length N, and the array A[N]. The algorithm works as
described below:

1) For an array of length N, we will have N-1 loops. And each Loop will have N-M-1
passes, where M = Loop Number. M = 0, 1, 2, ...
Eg: For an array of length 5, We have a total of 4 loops.
The first loop has 5-1 = 4 passes, as M = 0 for first loop.
The second loop has 5-1-1 = 3 passes, as M = 1 for second loop.
The third loop has 5-2-1 = 2 passes, as M = 2 for third loop.

And so on.

2) We will have to iterators to simulate the loop number and the pass number. If the
loop number is n and the pass number is m, for each loop, m will begin from n+1
through N.

## Contact
If you loved what you read here and feel like we can collaborate to produce some exciting stuff, or if you
just want to shoot a question, please feel free to connect with me on 
<a href="https://www.linkedin.com/in/vigviswa/" target="_blank">LinkedIn</a>


The order is checked as:
Is A[n] > A[m] : #For Ascending order
Then swap(A[n], A[m])
Else
Continue

3) After each loop, the smallest element will drop to the A[n] position, i.e., after the first
loop, A[0] will have the smallest element, after the second loop, A[1], and so on.

4) After iterating through all loops, the numbers will appear in ascending order.
