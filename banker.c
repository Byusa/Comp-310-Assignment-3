#include <stdio.h>
#include <stdbool.h>

// Number of processes
#define P 5
//int P;

// Number of resources
#define R 3
//int  R; 
// Function to find the system is in safe state or not
bool isSafe(int avail[], int maxm[][R])
{ 

	int processes[P];
    for(int pro =0 ; pro < P; pro++){
        processes[pro] = pro;
    }
    	// Resources allocated to processes
	int hold[][R] = {{0, 1, 0},
					{2, 0, 0},
					{3, 0, 2},
					{2, 1, 1},
					{0, 0, 2}};
	//for(int k;)
	/*int hold[][R] = {{0, 0, 0},
					{0, 0, 0},
					{0, 0, 0},
					{0, 0, 0},
					{0, 0, 0}};*/
	int need[P][R];
	// Function to calculate need matrix
	//calculateNeed(need, maxm, hold);
	////////
	// Fiding the need of each process
	// Calculating Need of each P
	for (int i = 0 ; i < P ; i++)
		for (int j = 0 ; j < R ; j++)
			// Need of instance = maxm instance -allocated instance
			need[i][j] = maxm[i][j] - hold[i][j];
	///////
	

	// Mark all processes as infinish
	bool finish[P] = {0};

	// To store safe sequence
	int safeSeq[P];

	// Make a copy of available resources
	int work[R];
	for (int i = 0; i < R ; i++)
		work[i] = avail[i];

	// While all processes are not finished
	// or system is not in safe state.
	int count = 0;
	while (count < P)
	{
		// Find a process which is not finish and
		// whose needs can be satisfied with current
		// work[] resources.
		bool found = false;
		for (int p = 0; p < P; p++)
		{
			// First check if a process is finished,
			// if no, go for next condition
			if (finish[p] == 0)
			{
				// Check if for all resources of
				// current P need is less
				// than work
				int j;
				for (j = 0; j < R; j++)
					if (need[p][j] > work[j])
						break;

				// If all needs of p were satisfied.
				if (j == R)
				{
					// Add the allocated resources of
					// current P to the available/work
					// resources i.e.free the resources
					for (int k = 0 ; k < R ; k++)
						work[k] += hold[p][k];

					// Add this process to safe sequence.
					safeSeq[count++] = p;

					// Mark this p as finished
					finish[p] = 1;

					found = true;
				}
			}
		}

		// If we could not find a next process in safe
		// sequence.
		if (found == false)
		{
			printf("System is not in safe state");
			return false;
		}
	}

    

	// If system is in safe state then
	// safe sequence will be as below
	printf("System is in safe state.\n");
	       //printf("Safe sequence is: "); 
//	for (int i = 0; i < P ; i++)
//	    printf("%d ",safeSeq[i]);
	return true;
}




int main() {	
	// Available instances of resources
	int avail[] = {3, 3, 2};

	// Maximum R that can be allocated
	// to processes
	int maxm[][R] = {{7, 5, 3},
					{3, 2, 2},
					{9, 0, 2},
					{2, 2, 2},
					{4, 3, 3}};
					
    // Check system is in safe state or not
	isSafe(avail, maxm);
    printf("\n");
	
	return 0;
}




