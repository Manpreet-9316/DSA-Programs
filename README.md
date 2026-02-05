# Sorting Algorithms - DSA Programs

This repository contains implementations of various sorting algorithms in C++. Below is a detailed analysis of each sorting algorithm.

---

## 1. Bubble Sort (`Bubble_sort.c++`)

### Algorithm Overview
Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process continues until the list is sorted.

### How It Works
1. Compare adjacent elements starting from the first pair
2. If the left element is greater than the right element, swap them
3. Move to the next pair and repeat
4. After each complete pass, the largest unsorted element "bubbles up" to its correct position
5. Repeat until no more swaps are needed

### Pseudocode
```
BUBBLE_SORT(arr[], n)
    FOR i = 0 TO n-1
        FOR j = 0 TO n-i-2
            IF arr[j] > arr[j+1]
                SWAP arr[j] and arr[j+1]
            END IF
        END FOR
    END FOR
END BUBBLE_SORT
```

### Time Complexity
- **Best Case**: O(n) - when the array is already sorted
- **Average Case**: O(n²) - typical random input
- **Worst Case**: O(n²) - when the array is sorted in reverse order

### Space Complexity
- O(1) - sorts in place, no extra space needed

### Advantages
- Simple to understand and implement
- No extra space required (in-place sorting)
- Stable sort (maintains relative order of equal elements)

### Disadvantages
- Very inefficient for large datasets
- High number of comparisons and swaps

### Example
```
Original array: 64 34 25 12 22 11 90
Sorted array: 11 12 22 25 34 64 90
```

---

## 2. Selection Sort (`Selection_sort.cpp`)

### Algorithm Overview
Selection Sort is a comparison-based sorting algorithm that divides the array into two parts: sorted and unsorted. It repeatedly selects the minimum element from the unsorted part and places it in the sorted part.

### How It Works
1. Find the minimum element in the unsorted portion of the array
2. Swap it with the first element of the unsorted portion
3. Move the boundary between sorted and unsorted portions one element to the right
4. Repeat until the entire array is sorted

### Pseudocode
```
SELECTION_SORT(arr[], n)
    FOR i = 0 TO n-2
        minIndex = i
        FOR j = i+1 TO n-1
            IF arr[j] < arr[minIndex]
                minIndex = j
            END IF
        END FOR
        SWAP arr[i] and arr[minIndex]
    END FOR
END SELECTION_SORT
```

### Time Complexity
- **Best Case**: O(n²)
- **Average Case**: O(n²)
- **Worst Case**: O(n²)

### Space Complexity
- O(1) - sorts in place, no extra space needed

### Advantages
- Simple implementation
- No extra space required
- Efficient for small datasets
- Reduces the number of swaps compared to Bubble Sort

### Disadvantages
- O(n²) time complexity makes it inefficient for large datasets
- Not stable (may change the relative order of equal elements)

### Example
```
Original array: 64 25 12 22 11
Sorted array: 11 12 22 25 64
```

---

## 3. Insertion Sort (`Insertion_sort.cpp`)

### Algorithm Overview
Insertion Sort is a comparison-based sorting algorithm that builds the sorted array one item at a time. It iterates through an array, and for each element, it finds the correct position in the already-sorted portion and inserts it there.

### How It Works
1. Start with the second element
2. Compare it with elements in the sorted portion (left side)
3. Shift all larger elements one position to the right
4. Insert the current element in its correct position
5. Move to the next element and repeat until the array is sorted

### Pseudocode
```
INSERTION_SORT(arr[], n)
    FOR i = 1 TO n-1
        key = arr[i]
        j = i - 1
        WHILE j >= 0 AND arr[j] > key
            arr[j+1] = arr[j]
            j = j - 1
        END WHILE
        arr[j+1] = key
    END FOR
END INSERTION_SORT
```

### Time Complexity
- **Best Case**: O(n) - when the array is already sorted
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - when the array is sorted in reverse order

### Space Complexity
- O(1) - sorts in place, no extra space needed

### Advantages
- Simple and intuitive to understand
- Efficient for small datasets
- Stable sort
- Adaptive - efficient for nearly sorted arrays
- In-place sorting

### Disadvantages
- O(n²) time complexity for large datasets
- Not suitable for large lists

### Example
```
Original array: 12 11 13 5 6
Sorted array: 5 6 11 12 13
```

---

## 4. Merge Sort (`Marge_sort.cpp`)

### Algorithm Overview
Merge Sort is a divide-and-conquer sorting algorithm that divides the array into halves, recursively sorts them, and then merges the sorted halves back together. It is a stable and efficient sorting algorithm.

### How It Works
1. **Divide**: Split the array into two halves
2. **Conquer**: Recursively sort each half
3. **Combine**: Merge the two sorted halves into a single sorted array
   - Compare elements from both halves
   - Place the smaller element in the temp array
   - Continue until one half is exhausted
   - Copy remaining elements from the non-empty half

### Pseudocode
```
MERGE_SORT(arr[], left, right)
    IF left < right
        mid = left + (right - left) / 2
        MERGE_SORT(arr, left, mid)
        MERGE_SORT(arr, mid+1, right)
        MERGE(arr, left, mid, right)
    END IF
END MERGE_SORT

MERGE(arr[], left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid
    
    CREATE temp arrays L[n1] and R[n2]
    
    FOR i = 0 TO n1-1
        L[i] = arr[left + i]
    END FOR
    
    FOR j = 0 TO n2-1
        R[j] = arr[mid + 1 + j]
    END FOR
    
    i = 0, j = 0, k = left
    
    WHILE i < n1 AND j < n2
        IF L[i] <= R[j]
            arr[k] = L[i]
            i = i + 1
        ELSE
            arr[k] = R[j]
            j = j + 1
        END IF
        k = k + 1
    END WHILE
    
    WHILE i < n1
        arr[k] = L[i]
        i = i + 1
        k = k + 1
    END WHILE
    
    WHILE j < n2
        arr[k] = R[j]
        j = j + 1
        k = k + 1
    END WHILE
END MERGE
```

### Time Complexity
- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n)

### Space Complexity
- O(n) - requires additional space for the temporary array during merging

### Advantages
- Guaranteed O(n log n) time complexity
- Stable sort
- Predictable performance
- Efficient for large datasets
- Works well with linked lists

### Disadvantages
- Requires O(n) extra space
- Slower than Quick Sort for in-place sorting due to space requirements
- Not adaptive (always performs the same operations)

### Example
```
Original array: 38 27 43 3 9 82 10
Sorted array: 3 9 10 27 38 43 82
```

---

## 5. Heap Sort (`Heap_sort.cpp`)

### Algorithm Overview
Heap Sort is a comparison-based sorting algorithm that uses a heap data structure. It builds a max heap and repeatedly extracts the maximum element, placing it at the end of the sorted array.

### How It Works
1. **Build Max Heap**: Rearrange the array into a max heap where parent nodes are larger than children
2. **Extract and Sort**:
   - Swap the root (maximum element) with the last element
   - Reduce the heap size by 1
   - Heapify the root to maintain the heap property
   - Repeat until the heap is empty

### Heapify Process
- Compares a node with its children
- If a child is larger than the parent, swap them
- Recursively heapify the affected subtree

### Pseudocode
```
HEAP_SORT(arr[], n)
    FOR i = n/2 - 1 DOWN TO 0
        HEAPIFY(arr, n, i)
    END FOR
    
    FOR i = n-1 DOWN TO 1
        SWAP arr[0] and arr[i]
        HEAPIFY(arr, i, 0)
    END FOR
END HEAP_SORT

HEAPIFY(arr[], n, i)
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    IF left < n AND arr[left] > arr[largest]
        largest = left
    END IF
    
    IF right < n AND arr[right] > arr[largest]
        largest = right
    END IF
    
    IF largest != i
        SWAP arr[i] and arr[largest]
        HEAPIFY(arr, n, largest)
    END IF
END HEAPIFY
```

### Time Complexity
- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n)

### Space Complexity
- O(1) - sorts in place (excluding the recursive call stack)

### Advantages
- Guaranteed O(n log n) time complexity
- In-place sorting (minimal extra space)
- Not stable but efficient
- Good for memory-constrained environments

### Disadvantages
- Complex implementation
- Not stable sort
- Slower than Quick Sort in practice due to cache inefficiency
- Not adaptive

### Example
```
Original array: 12 11 13 5 6 7
Sorted array: 5 6 7 11 12 13
```

---

## 6. Quick Sort (`Quick_sort.cpp`)

### Algorithm Overview
Quick Sort is a divide-and-conquer sorting algorithm that selects a pivot element and partitions the array into two subarrays: elements less than the pivot and elements greater than the pivot. It then recursively sorts these subarrays.

### How It Works
1. **Select Pivot**: Choose an element as the pivot (typically the last element)
2. **Partition**: Rearrange the array so that:
   - All elements less than the pivot are on the left
   - All elements greater than the pivot are on the right
   - The pivot is in its final position
3. **Recursively Sort**: Apply the same process to the left and right subarrays

### Partition Process
- Use two pointers: one starting from the left and one at the pivot
- Move the left pointer to find an element greater than the pivot
- Move elements greater than the pivot to the right
- Place the pivot in its correct position

### Pseudocode
```
QUICK_SORT(arr[], low, high)
    IF low < high
        pi = PARTITION(arr, low, high)
        QUICK_SORT(arr, low, pi - 1)
        QUICK_SORT(arr, pi + 1, high)
    END IF
END QUICK_SORT

PARTITION(arr[], low, high)
    pivot = arr[high]
    i = low - 1
    
    FOR j = low TO high - 1
        IF arr[j] < pivot
            i = i + 1
            SWAP arr[i] and arr[j]
        END IF
    END FOR
    
    SWAP arr[i + 1] and arr[high]
    RETURN i + 1
END PARTITION
```

### Time Complexity
- **Best Case**: O(n log n) - when the pivot divides the array evenly
- **Average Case**: O(n log n)
- **Worst Case**: O(n²) - when the pivot is always the smallest or largest element

### Space Complexity
- O(log n) - due to recursive call stack (in-place sorting)

### Advantages
- Fast in practice with good average-case performance
- In-place sorting
- Cache-friendly due to sequential access patterns
- Works well for large datasets
- Can be optimized with various pivot selection strategies

### Disadvantages
- Unstable sort
- Worst-case O(n²) time complexity
- Performance depends on pivot selection
- Recursive implementation requires stack space

### Example
```
Original array: 10 7 8 9 1 5
Sorted array: 1 5 7 8 9 10
```

---

## Comparison Table

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | Notes |
|-----------|-----------|--------------|-----------|-------|--------|-------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Simple, slow for large data |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Consistent performance |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Good for nearly sorted data |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | Guaranteed speed, extra space |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No | Consistent, not cache-friendly |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No | Fast in practice, pivot-dependent |

---

## When to Use Each Algorithm

- **Bubble Sort**: Educational purposes only, not for production
- **Selection Sort**: When memory is extremely limited and simplicity is needed
- **Insertion Sort**: Small datasets or nearly sorted data
- **Merge Sort**: When stability and guaranteed O(n log n) performance is critical
- **Heap Sort**: When space is critical and predictable O(n log n) is needed
- **Quick Sort**: General-purpose sorting for most applications due to excellent average performance

---

## Note on Code Quality

Some files contain minor issues:
- `Selection_sort.cpp`: Contains a typo in the include directive (`#include<iosteam>` should be `#include<iostream>`)
- `Marge_sort.cpp`: File name should be `Merge_sort.cpp` and contains an unused `partition` function in `Heap_sort.cpp`

These should be corrected for proper compilation and clarity.

