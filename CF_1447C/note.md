[**Problem Link**](https://codeforces.com/contest/1447/problem/C)

## **Problem Statement**
---
- There is bag with weight W 
- There is n item and ith item weight is **wi**
- total weight will be at least (W/2) and atmost (W)
- construct array of items that total weight of that array satisfy the above condition

## Input
---
- Given N, where N is number of elements
and N<=**2e5**
- Given W ,total capacity of the bag
W<=10<sup>18
- wi is weight of the item ,wi <=10<sup>9


## Observation:
- First we think of when we can't satisfy the condition
- when minimum element of that is bigger than the capacity of the bag then answer is -1
- if sum of all elements is less than (W/2) 
then also answer is -1

- for all other case answer is yes and we just have to put all items until total weights of the item don't exceed capacity

## Implementation:
- sort the array in decreasing order 
- check for satisfying condition
- put all the item until sum does not excees the capacity
- print the array
# Code
 ```c++
 