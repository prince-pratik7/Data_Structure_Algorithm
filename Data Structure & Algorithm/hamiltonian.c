/** Computes and prints the Hamiltonian path of a graph.
 * Input: The number of veritces (n) in the graph, followed by the nxn graph
 * Output: The Hamiltonian path of the graph
 */
#include <stdio.h>
#include <stdlib.h>

int n; // number of vertices in the graph g
int *x; // the solution array

// user-defined functions
void nextValue(int k, int g[n][n]); // assign a vertex to x[k] assuming x[0] to x[k-1] are assigned
void hamiltonian(int k, int g[n][n]); // solve the hamiltonian problem

int main()
{
	int i, j;
	printf("Enter the number of vertices in the graph: ");
	scanf("%d", &n);

	int g[n][n];
	x = (int *)malloc(n*sizeof(int));

	printf("Enter the adjacency matrix of the graph:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	}

	// set the solution array to 0, except x[0]
	for (i = 1; i < n; i++) x[i] = 0;
	x[0] = 1;

	printf("The Hamiltonian path is:\n");
	hamiltonian(1, g);

	return 0;
}

void nextValue(int k, int g[n][n])
{
	int i;
	while(1)
	{
		x[k] = (x[k]+1) % (n+1);
		if (x[k] == 0) return;

		// check for an edge between x[k] and x[k-1]
		if (g[ x[k] ][ x[k-1] ] != 0)
		{
			// check for distincness
			for (i = 0; i < k; i++)
				if (x[i] == x[k]) break;
			if (i == k) // distinct
			{
				if ((k < n-1) || (k == n-1 && g[ x[k] ][ x[0] ] != 0))
					return;
			}
		}
	}
}

void hamiltonian(int k, int g[n][n])
{
	int i, j;

	nextValue(k,g); // generate a new value for x[k]
	//if (x[k] == 0) return;
	if (k == n)
	{
		for (i = 0; i < n; i++) printf("%d ", x[i] + 1);
		printf("\n");
	}
	else hamiltonian(k+1, g);
}

