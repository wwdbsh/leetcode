## Verifying an Alien Dictionary

* hash table, sort

Let N be the length of order, and M be the total number of characters in words. 

* Time complexity : O(M).

Storing the letter-order relation of each letter takes O(N) time. For the nested for-loops, we examine each pair of words in the outer-loop and for the inner loop, we check each letter in the current word. Therefore, we will iterate over all of letters in words.

Taking both into consideration, the time complexity is O(M+N). However, we know that NN is fixed as 26. Therefore, the time complexity is O(M).

* Space complexity : O(1). The only extra data structure we use is the hashmap/array that serves to store the letter-order relations for each word in order. Because the length of order is fixed as 26, this approach achieves constant space complexity.