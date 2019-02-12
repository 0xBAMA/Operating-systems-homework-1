#include <stdio.h>    /*printf*/
#include <stdlib.h>   /*atoi*/
#include <time.h>     /*time,nanosleep*/

/* Jon Baker 2/8/2019 */

/*
user inputs a number 1-100, we can call it 'n'
we want to use n units of time waiting busily
and 100-n units of time sleeping
*/

int main(int argc, char const *argv[]) {

  int n,count;
  clock_t t1,t2;


  struct timespec time, time2;
  time.tv_sec = 0;
  time.tv_nsec = 500000000; /*500 000 000 nanoseconds = half a second*/

  n = 0;
  count = 0;


  if(argc == 2)
    n = atoi(argv[1]);

  if(n < 1 || n > 100)
    printf("Usage: ./cpu_percentage n where n is between 1 and 100");

  while (1)
  {
    /* take the time before the loop, t1, using clock()*/
    t1 = clock();
    /* do some code*/
    while (count < 10000000)
    {
      count++;
    }
    count = 0;
    /* take the time after the loop, t2, using clock()*/
    t2 = clock();

    time.tv_nsec = (100-n)*(((((double)(t2-t1))/CLOCKS_PER_SEC)*1000000000)/n);
    /*determine the time elapsed during the loop execution, by subtracting t1 from t2

      if n units of time elapsed during the loop execution, then we will wait
      (elapsed_time/n)*(100-n) units of time before repeating the loop
    */

    nanosleep(&time,&time2);

  }
  return 0;
}
