/**
 * Complete set of heap algorithms, including heap_sort, implemented in C as prescribed in the syllabus of the subject CS501 
 * This program has been tried and tested on standard inputs. It may contain bugs. Please report to the author in case of any bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// in-line functions
#define left(i) (2*i + 1) // get the index of the left child of a node
#define right(i) (2*i + 2) // get the index of the right child of a node
#define parent(i) ((i - 1)/2) // get the index of the parent of a node

// user-defined functions
int* create_heap(int); // create a heap of specified size
void show_heap(int); // print a heap array
void max_heapify(int,int); // max-heapify the heap using recursion
void max_heapify_alter(int,int); // max-heapify the heap using loop
void min_heapify(int,int); // min-heapify the heap using recursion
void build_max_heap(int); // build the max-heap from bottom up
void heapsort(int); // apply the heapsort process to sort the array
int extract_max(int); // take out the maximum element from the heap, and return the new heapsize
void increase_key(int,int); // update the value of the heap in the position given to a larger number
int insert_key(int,int); // insert key inside the heap, and return the new heapsize

int *h; // create a global heap variable

int main()
{
	int i, n, ch, key, pos;
	
	// create a heap array
	printf("Enter the size of the heap: ");
	scanf("%d", &n);
	h = create_heap(n);
	printf("Heap created\n");
	
	// enter elements in it
	printf("\nEnter %d elements: ", n);
	for (i = 0; i < n; i++) scanf("%d", &h[i]);
	printf("Heap updated\n");
	
	// enter the menu
	while(1)
	{
		printf("\nEnter what you want\n1. See the heap \n2. Max-Heapify it \n3. Min-Heapify it \n4. Build the entire heap \n5. Apply heapsort on the array \n6. Extract the maximum element from the heap \n7. Update a key to a higher value \n8. Insert a new value in the heap \n-1. Exit \nEnter choice: ");
		scanf("%d", &ch);
		if(ch == -1) break;
		switch(ch)
		{
			case 1: 
				printf("The heap is:\n");
				show_heap(n);
				break;
			case 2: 
				printf("Enter the position of i: "); // user assumes 1-indexed
				scanf("%d", &i);
				max_heapify(--i, n);
				printf("Heap changed\n");
				break;
			case 3:
				printf("Enter the position of i: "); // user assumes 1-indexed
				scanf("%d", &i);
				min_heapify(--i, n);
				printf("Heap changed\n");
				break;
			
			case 4:
				build_max_heap(n);
				printf("Heap built\n");
				break;
				
			case 5:
				heapsort(n);
				printf("Heap sorted\n");
				break;
			
			case 6:
				n = extract_max(n);
				printf("Maximum element extracted\n");
				break;
			
			case 7:
				printf("Enter the position and the key to be inserted there: ");
				scanf("%d %d", &pos, &key); // user assumes 1-indexed
				increase_key(--pos, key);
				printf("Key inserted\n");
				break;
			
			case 8:
				printf("Enter the value you want to insert: ");
				scanf("%d", &key);
				n = insert_key(key, n);
				printf("Key inserted\n");
				break;
				
			default:
				printf("Wrong choice. Try again\n");
				break;
		}
	}
	
	return 0;
}

int* create_heap(int n) 
{
	return (int *)malloc(n * sizeof(int));
}

void show_heap(int n)
{
	int i;
	for (i = 0; i < n; i++) printf("%d\n", h[i]);
}

void max_heapify(int i, int n)
{
	int l, r, max, temp;
	
	// compute the indices children - left and right - of the node at index i
	l = left(i);
	r = right(i);
	
	// find the largest among these, and store its index in max
	if (l < n && h[l] > h [i]) max = l;
	else max = i;
	if (r < n && h[r] > h[max]) max = r;
	
	// max-heapify away!
	if (max != i)
	{
		temp = h[i];
		h[i] = h[max];
		h[max] = temp;
		max_heapify(max, n);
	}
}

void max_heapify_alter(int i, int n)
{
	int l, r, max, temp;
	while(1)
	{
		l = left(i);
		r = right(i);
		
		// find the greatest b/w h[i] and its children h[l], h[r]
		if (l <= n && h[l] > h[i])
			max = l;
		else max = i;
		if (r <= n && h[r] > h[max])
			max = r;
		
		// if max happens to be i itself, terminate
		if (max == i) return;
		
		// otherwise, max-heapify away!
		temp = h[i];
		h[i] = h[max];
		h[max] = temp;
		
		// check the subtree now
		i = max;
	}
}

void min_heapify(int i, int n)
{
	int l, r, min, temp;
	
	// compute the indices children - left and right - of the node at index i
	l = left(i);
	r = right(i);
	
	// find the smallest among these, and store its index in min
	if (l < n && h[l] < h [i]) min = l;
	else min = i;
	if (r < n && h[r] < h[min]) min = r;
	
	// max-heapify away!
	if (min != i)
	{
		temp = h[i];
		h[i] = h[min];
		h[min] = temp;
		max_heapify(min, n);
	}
}

void build_max_heap(int n)
{
	int i;
	int non = (n-1)/2; // the index of the last non-leaf node
	// loop over from this index up till the root, and apply the max-heapify process on each node
	for(i = non; i >= 0; i--) max_heapify(i, n);
}

void heapsort(int n)
{
	int i, temp, m;
	// First, make the array a max-heap
	build_max_heap(n);
	
	m = n - 1;
	for (i = m; i > 0; i--)
	{
		// swap h[0] with h[i], thus putting the largest element at the end of the array
		temp = h[0];
		h[0] = h[i];
		h[i] = temp;
		// max-heapify the changed array uptil one before the last child
		max_heapify(0, --n);		
	}
}

int extract_max(int n)
{
	int temp;
	// first, swap the max element (h[0]) with the last leaf (h[n-1])
	temp = h[0];
	h[0] = h[n - 1];
	h[n - 1] = temp;
	
	// now decrease the heapsize by 1 and max-heapify it
	max_heapify(0, --n);
	
	// finally, return the new size to the calling function
	return n;
}

void increase_key(int pos, int key)
{
	int temp;
	// first off, put the key in the position specified
	h[pos] = key;
	
	// make sure this value does not exceed its parent's value
	while(h[pos] > h[parent(pos)])
	{
		// swap this value with its parent
		temp = h[pos];
		h[pos] = h[parent(pos)];
		h[parent(pos)] = temp;
		
		pos = parent(pos);
	}
}

int insert_key(int key, int n)
{
	// increase the heapsize by 1
	n++;
	h = (int *) realloc(h, n * sizeof(int));
	
	h[n-1] = INT_MAX; // put infinity sentinel at the end of the heap
	increase_key(n-1, key);
	
	return n; // return the new heapsize
}

