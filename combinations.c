#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
/* To compile:
gcc combinations.c -o combinations */
int factorial(int n)
{
	int i;
	int factorial = 1;
	if(n == 1 || n == 0)
		return 1;
	if(n < 0)
		return -1;
	for(i = 1;i < n+1; i++)
		factorial *= i;

	return factorial;
}

int num_of_combinations(int n, int k)
{
	if(n < k)
		return -1;
	int n_factorial = factorial(n);
	int k_factorial = factorial (k);
	int n_minus_k_factorial = factorial(n-k);

	return n_factorial/(n_minus_k_factorial*k_factorial);
}

int generate_all_combinations(int *a,int n, int m)
{
	/* Generate combinations of indexes */
	/* To generate we need to call function in while() loop */	
	int i,j;
	int k = m;
	for (i = k - 1; i >= 0; --i)
  	  if (a[i] < n - k + i + 1) 
  	  {
  	   ++a[i];
   	   for (j = i + 1; j < k; ++j)
   	     a[j] = a[j - 1] + 1;
		return 0;
 	   }
	 return -1;

}
void print_all_combinations(char *c, int n, int m)
{
	int *a=(int*)calloc(n, sizeof(int));// array of indexes
	
	int i;
	for(i=0; i < n; i++)
		a[i] = i+1;
	for(i=0; i < m; i++)
		printf("%c ", c[i]);
	printf("\n");
	while(!(generate_all_combinations(a,n,m)))
		{
			for(i=0; i < m;i++)
		      printf("%c ",*(c+*(a+i)-1));//match every index to letter in c array
			  printf("\n");
		}
	free(a);
}
int main(int argc, char** argv)
{
	int n, k, opt;
 	char *s;
	char* help="Prints all combinations by k of symbols included in string s\nUsage: %s [-n] [-k] [-s string]\n";
	if(argc < 3)
   	{
		fprintf(stderr, help, argv[0]);
        	exit(EXIT_FAILURE);
   	}
   	while((opt=getopt(argc, argv, "hs:n:k:")) != -1)
   	{
		switch (opt)
		{
               	   case 'n':
                   	n = atoi(optarg);
                   	break;
               	   case 'k':
                   	k = atoi(optarg);
                   	break;
		   case 's':
			s=optarg;
			break;
		   case ':':// getopt() returns this if missing option argument detected
			exit(EXIT_FAILURE);
               	   case '?'://if getopt() met unknown option
		   case 'h':
        	        fprintf(stderr,help,argv[0]);
                	exit(EXIT_FAILURE);
		   default:
                   	fprintf(stderr,help,argv[0]);
		   	exit(EXIT_FAILURE);
               }
   }
	if (optind != argc) 
   	{
		   fprintf(stderr, help, argv[0]);
		   exit(EXIT_FAILURE);
   	}
    	if(k > n || k == 0 || n == 0)
     	{
      		fprintf(stderr, "Error: N,K are incorrect \n");
      		exit(EXIT_FAILURE);
     	}

   	printf("String=%s\n",s); 
   	printf("num of combinations by %i of %i = %d\n",k,n, num_of_combinations(n,k));
   	print_all_combinations(s, n, k);
}


