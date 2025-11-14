# The Merge-Insertion Sort (Ford-Johnson) Algorithm

	example L = [5, 1, 4, 2, 3]

## Step 1: Pairing and initial Comparisions

	1.) Pairing the elements, if odd number of elements, the last one is a "stray"
		L = [5, 1, 4, 2, 3]
		Pairs: (5, 1), (4, 2)
		Stray: 3
	2.) Compare each pair:
		(5, 1) -> Larger: 5, Smaller: 1
		(4, 2) -> Larger: 4, Smaller: 2
	3.) Create two Lists: a list of the "larger", and a list of "smaller" (aka "pendants")
		Larger: [5, 4]
		Pendants: [1, 2]
		We "remember" which pendant belongs to which larger element (5, 1) and (4, 2)

## Step 2: Recursive Sort (Building the Main Chain)

	1.) Sort the "Larger" list recursively with our algorithm
		[5, 4] -> [4, 5]
	2.) Main Chain a = [a1, a2] = [4, 5]
	3.) Re-order Pendants: We reorder the pendants to match the new Main Chain
		b = [b1, b2] = [2, 1]

## Step 3: "Smart" Insertion Phase
	1.) Insert the first Pendant.
		we know b1 < a1 => we perform a binary search the part of Main Chain before a1
		- Main Chain: [4, 5]
		- Pendant to insert: b1 = 2
		- Search space: [4] (the part of the chain before and including a1 = 4)
		- Sorted List: S = [2, 4, 5]
	2.) Insert remaining pendants.
		- Naive approach continue with b2, b3, ...
		- Ford-Johnson Magic: insert pendants in Jacobsthal order (see explanation below)
			to keep binary search spaces as efficient as possible
		- Sorted List: S = [1, 2, 4, 5]
	3.) Insert the Stray: using a standard binary search
		- Sorted List: S = [1, 2, 3, 4, 5]


### Elaborating the Step 3.2 "Smart" Insertion:
---------------------------------

```
The key to minimizing comparisons comes from Step 3.2.
	Why not just insert b2, then b3, then b4?

If we had a main chain [a1, a2, a3, a4, a5]
		  and pendants [b1, b2, b3, b4, b5].

After inserting b1, our list is [...b1..., a1, a2, a3, a4, a5].

If we insert b2 next: We binary search the elements before a2.
This search space has 3 elements (...b1..., a1, a2). Max 2 comparisons.
Then we insert b3: We search elements before a3.
This space now includes b2, so it has 5 elements (...b1..., a1, ...b2..., a2, a3). Max 3 comparisons.

If we use the Ford-Johnson order (b3, then b2):
Insert b3 first: We search elements before a3.
This space has 4 elements (...b1..., a1, a2, a3). Max 2 comparisons.
Then we insert b2: We search elements before a2.
This space has 3 elements (...b1..., a1, a2). Max 2 comparisons.

In the worst case, the Ford-Johnson order (b3, b2) costs 2 + 2 = 4 comparisons,
while the naive order (b2, b3) costs 2 + 3 = 5 comparisons.
The algorithm saves a comparison by inserting b3 before b2 to optimize the binary search space.

The algorithm generalizes this by grouping pendants ( b3, b2 ), then ( b5, b4 ),
then ( b11, b10, ... b6 ), etc., following a pattern related to Jacobsthal numbers,
to always ensure the binary search is as efficient as possible.
```

Jacobsthal numbers: similar to the Fibonacci numbers.
$$J_0 = 0$$
$$J_1 = 1$$
$...$ 
$$J_n = J_{n-1} + 2 * J_{n-2}$$

The sequence starts: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...

A "closed-form" formula to find the $n$-th term directly:
$$J_n = \frac{2^n - (-1)^n}{3}$$

---

<BR>

---

# `std::vector` vs `std::deque` vs `std::list`

- **std::vector**:
  - stores its elements in a single contiguous block of memory.
  - **pros**:
	- Excellent Cache Performance: Due to contiguous memory allocation, CPU can pre-fetch the next elements into its cache, avoiding slow reads from main memory.
	- Fast Random Access: Accessing any element by its index in O(1) time complexity.
	- Memory Efficiency: Lower overhead compared to linked structures since it doesn't require extra memory for pointers.
  - **cons**:
  	- Slow Insertions/Deletions (at the beginning or middle): Requires shifting elements, leading to O(n) time complexity.
  	- Potential Reallocation: When the vector grows beyond its current capacity, it may need to allocate a new larger block of memory and copy existing elements, which can be costly.
- **std::deque**:
  - stores its elements in multiple non-contiguous memory blocks.
  - it uses a separate array of pointers to these blocks.
  - **pros**:
	- Fast Insertions/Deletions at Both Ends: O(1) time complexity for adding/removing elements at the front or back.
  - **cons**:
  	- Slower Random Access: Accessing elements is slightly slower than vectors because it requires a double-lookup (first to find the block, then to find the element within the block).
  	- Cache Performance: Less cache-friendly than vectors due to non-contiguous storage.
- **std::list**:
  - implements a doubly linked list.
  - each element (node) contains pointers to both the previous and next nodes.
  - **pros**:
	- Fast Insertions/Deletions Anywhere: O(1) time complexity for adding/removing elements at any position, given an iterator to that position.
  - **cons**:
  	- Poor Cache Performance: Nodes are scattered in memory, leading to frequent cache misses.
  	- No Random Access: Accessing elements requires traversal from the beginning or end, leading to O(n) time complexity.
  	- Higher Memory Overhead: Each node requires extra memory for storing pointers to the next and previous nodes.
