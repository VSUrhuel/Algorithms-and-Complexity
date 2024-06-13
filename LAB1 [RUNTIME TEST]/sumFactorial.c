#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

long long unsigned fact(long long unsigned d)
{
    long long f = 1; //->1
    while(d > 0) //->d+1
    {
        f*=d;// -> 2
        d--; //-> 2
    }
    return f;//->1
    //4d + 6 is the run time of this function
}

long long unsigned sumFact(long long unsigned n)
{
    long long unsigned sum = 0; //->1
    while(n > 0) //-> log(n) + 1
    {
        sum += fact(n%10); //-> 2 + (4d+6)
        n/=10; //->2
    }
    return sum; //->1
    //4dlog(n) + 10log(n) + 10 + 4d is the runtime of this function
}

int main()
{
    srand(time(NULL));
    clock_t start, end;
    double timeTaken = 0, theorizeTime = 0;
    long long n[] = {1000, 10000, 100000, 1000000, 20000000, 30000000, 40000000, 50000000, 60000000};

    char *fileName = "test.txt";
    char *fileName2 = "theorize.txt";
    FILE *fp = fopen(fileName, "a");
    FILE *fp2 = fopen(fileName2, "a");
    if(fp == NULL || fp2 == NULL)
    {
        printf("Error opening the file.\n");
        return -1;
    }

    for(int i=0; i<10; i++)
    {
        for(int j = 0; j < n[i]; j++)
        {
            // Random number between three digits to six digits
            double num = rand() % 999999 + 999;
            //The Asymptotic Equation is:
                //4dlog(n) + 10log(n) + 10 + 4d
            //Where d is the highest maximum digit whihc is 9
            //Asymptotic Notation is O(d*log(n))
            //My computer has a median of 3 GhZ, which means this can run in 3000000000 inst/sec
            //Cacluculating the Asymptotic Runtime using the Asymptotic Equation
            theorizeTime += ((4 * 9 * (floor(log(num))) + 1) + (10 *  (floor(log(num)) + 1)) + (4 * 9) + 10)/3000000000;

            //Start Recording Time for Actual Run Time
            start = clock();
            sumFact(num);
            end = clock();
            timeTaken += ((double) (end - start)) / CLOCKS_PER_SEC;
        }
        //printf("%lf-%lf,", theorizeTime, timeTaken);
        fprintf(fp2, "%lld - %lf\n", n[i], theorizeTime);
        fprintf(fp, "%lld - %lf\n", n[i], timeTaken);
    }
    fclose(fp);
    fclose(fp2);
}
