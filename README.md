# Sorting algorithms

Sorting algorithms are used to arrange elements (such as numbers, strings, or other data) in an array or list in ascending or descending order. There are different sorting algorithms, each with its own characteristics, advantages and disadvantages.
-------------
## Bubble Sort
![bubble_sort.gif_](./images/bubble_sort.gif "from wikipedia.org")
-**Description:** Iterates through the array, comparing each pair of adjacent elements and swapping them if they are in the wrong order. At each iteration, it "pops up" (or settles down) the largest element at the end of the array.
-**Difficulty:** O(n^2^) in average and worst cases.
-**When to use:** With a small number of elements or for training, since the algorithm is easy to understand.

## Selection Sort
![selection_sort.gif](./images/selection_sort.gif "from wikipedia.org")
-**Description:** Finds the minimum element and moves it to the beginning of the array, then repeats this for each subarray.
-**Difficulty:** O(n^2^) in average and worst cases.
-**When to use:** Suitable for small arrays, easy to implement.

## Insertion Sort
![insertion_sort_.gif](./images/insertion_sort.gif "from wikipedia.org")
-**Description:** Divides the array into sorted and unsorted parts, gradually adding elements from the unsorted part to the correct place.
-**Complexity:** O(n^2^) at worst, O(n) at best (if the array is almost sorted).
-**When to use:** Effective for small arrays or almost sorted arrays.

## Quick Sort
![quick_sort.gif](./images/quick_sort.gif "from wikipedia.org")
-**Description:** Selects a pivot, divides the array into elements smaller and larger than the pivot, and recursively sorts both parts.
-**Complexity:** O(n log n) on average, O(n^2^) at worst (if you choose an unsuccessful pivot, for example, the first element in a sorted array).
-**When to use:** One of the fastest sorting algorithms for large arrays, but may require optimization to avoid the worst case.

## Merge sort
![merge_sort.gif](./images/merge_sort.gif "from wikipedia.org")
-**Description:** Divides the array into two parts, recursively sorts them and merges them into a single sorted array.
-**Difficulty:** O(n log n) in the worst, average and best cases.
-**When to use:** Fast sorting with good performance on large datasets, especially useful when stable sorting is needed.

## Heap Sort
![merge_sort.gif](./images/heap_sort.gif "from wikipedia.org")
-**Description:** Building a binary heap (max-heap) from an array, then extracting the maximum element and restoring the heap.
-**Difficulty:** O(n log n) in the average and worst cases.
-**When to use:** Effective for arrays that need to be sorted without additional memory.

-----------------
## Comparison of algorithms
| Algorithm | Average difficulty | Worst difficulty | Memory | Stability |
|-----------|--------------------|------------------|--------|-----------|
|Bubble Sort| O(n²)| O(n²) | O(1) | + |
|Selection Sort| O(n²) | O(n²) | O(1) | - |
|Insertion Sort| O(n²) | O(n²) | O(1) | + |
|Quick Sort| O(n log n) | O(n²) | O(log n) | - |
|Merge Sort| O(n log n) | O(n log n) | O(n) | + |
|Heap Sort | O(n log n) | O(n log n) | O(1) | - |

**Conclusion:** it is better to choose the sorting depending on your tasks.

-----------
## About app
My application visually shows the sorting speeds of various sorting algorithms on different datasets, of different types and of different sizes in charts.