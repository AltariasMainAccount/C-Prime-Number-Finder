#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define clear() printf("\033[H\033[J")

int main(){
    long long int limitInput = 1000;
    long long int limit;
    unsigned long long int i,j;
    char *primeNumbers;
    int z = 1;
    clear();
    printf("How many Integers shoud be checked for primes?: ");
    scanf("%lld", &limitInput);
    limit = limitInput;
    /* What is a prime? */
    primeNumbers = malloc(sizeof(int)*limit); // Array for primes (needs the limit for the allocations)

    /* prime / nonprime filter (aka Prime sieve) [Filtering Primes from nonprimes] */
    for (i=2;i<limit;i++)
    {
        primeNumbers[i]=1;
    }
    for (i=2;i<limit;i++)
    {
        if (primeNumbers[i])
            {
                for (j=i;i*j<limit;j++)
                    {
                        primeNumbers[i*j]=0;
                    }
            }  
    }
    /* If primeNumbers = prime (prime found) | else (not a prime) */
    for (i=2;i<limit;i++)
    {
        if (primeNumbers[i]) 
        {
            printf("%d. prime found = %lld\n",z++,i);
        }
    }

    /* return 0 */
	return 0;
}