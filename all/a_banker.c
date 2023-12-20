#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finished[MAX_PROCESSES];

int num_processes, num_resources;

void input_data() {
	int i,j;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);
    
    printf("Enter the available resources: ");
    for (i = 0; i < num_resources; i++) 
	{
        scanf("%d", &available[i]);
    }
    
    printf("Enter the maximum demand of each process: \n");
    for (i = 0; i < num_processes; i++) 
	{
        printf("Process %d: ", i);
        for ( j = 0; j < num_resources; j++) 
		{
            scanf("%d", &maximum[i][j]);
        }
    }
    
    printf("Enter the current allocation of each process: \n");
    for (i = 0; i < num_processes; i++)
	 {
        printf("Process %d: ", i);
        for (j = 0; j < num_resources; j++)
		 {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool is_safe(int seq[], int len)
 {
	int i,j;
    int work[MAX_RESOURCES];
    for (i = 0; i < num_resources; i++)
	 {
        work[i] = available[i];
    }
    
    bool finished_copy[MAX_PROCESSES];
    for (i = 0; i < num_processes; i++)
	 {
        finished_copy[i] = finished[i];
    }
    
    for ( i = 0; i < len; i++)
	 {
        int process = seq[i];
        bool can_execute = true;
        for (j = 0; j < num_resources; j++)
		 {
            if (need[process][j] > work[j]) 
			{
                can_execute = false;
                break;
            }
        }
        if (can_execute) {
            for (j = 0; j < num_resources; j++)
			 {
                work[j] += allocation[process][j];
            }
            finished_copy[process] = true;
        } else
		 {
            return false;
        }
    }
    
    for ( i = 0; i < num_processes; i++)
	 {
        if (!finished_copy[i])
		 {
            return false;
        }
    }
    return true;
}

void print_seq(int seq[], int len)
 {
	int i;
    for ( i = 0; i < len; i++) 
	{
        printf("%d ", seq[i]);
    }
    printf("\n");
}

void find_safe_seq(int seq[], int len)
 {
	int i,j;
    if (len == num_processes)
	 {
        if (is_safe(seq, len)) 
		{
            print_seq(seq, len);
        }
        return;
    }
    
    for ( i = 0; i < num_processes; i++)
	 {
        if (!finished[i])
		 {
            bool can_execute = true;
            for ( j = 0; j < num_resources; j++) 
			{
                if (need[i][j] > available[j])
				 {
                    can_execute = false;
                    break;
                }
            }
            if (can_execute)
			 {
            	for (j = 0; j < num_resources; j++)
				 {
                    available[j] += allocation[i][j];
                }
                finished[i] = true;
                seq[len] = i;
                find_safe_seq(seq, len+1);
                finished[i] = false;
                seq[len] = -1;
                for (j = 0; j < num_resources; j++)
				 {
                    available[j] -= allocation[i][j];
                }
            }
        }
    }
}
int main() {
    input_data();
    int i;
    int seq[MAX_PROCESSES];
    for (i = 0; i < num_processes; i++)
	 {
        seq[i] = -1;
    }
    find_safe_seq(seq, 0);
    return 0;
}





               

