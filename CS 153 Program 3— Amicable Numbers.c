//9/27/18
// The program finds all pairs of amicable numbers where the first number of the pair is less than the limit.

#include <stdio.h>

int sumDivisors(int n)
{
    int a;
    int total = 1;
    for(a = 2 ; a*a < n ; a++)
    {
        if(n % a == 0)
            total = total + a + n/a;
    }
    if(a*a == n)
        total = total + a;
    return total;
}

int main()
{
    int N, a, b, lowerlimit, upperlimit;

    printf("Enter lower limit: ");
    scanf("%d",&lowerlimit);

    printf("Enter upper limit: ");
    scanf("%d",&upperlimit);

    N = upperlimit - lowerlimit;

    int array[N];

    for (a = 0; a < N; ++a)
        array[a] = lowerlimit + a;

    for (a = 0; a < N; ++a)
    {
        for (b = 0; b < N; ++b)
        {
            if((array[a] == sumDivisors(array[b])) && (array[b] == sumDivisors(array[a])))
                if (array[a] == array[b])
                  printf("Perfect number: %d\n", array[a]);
                else
                  printf("Amicable pair: (%d %d)\n", array[a], array[b]);
        }
    }

    return 0;
}