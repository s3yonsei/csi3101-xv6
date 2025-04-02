#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int bench_start = uptime();

  int pid1 = fork();
  if (pid1 == 0) {
    // sched_setattr(5, 1);  //"If you have implemented it, remove the comments."
    int start = uptime();
    for (volatile int i = 0; i < 50000000; i++) {} // low weight
    int end = uptime();
    printf(1, "2 Time: %d\n", end - start);
    exit();
  }
  int pid2 = fork();
  if (pid2 == 0) {
    // sched_setattr(5, 5);  //"If you have implemented it, remove the comments."
    int start = uptime();
    for (volatile int i = 0; i < 50000000; i++) {} // high weight
    int end = uptime();
    printf(1, "1 Time: %d\n", end - start);
    exit();
  }

  wait(); 
  wait();
  int bench_end = uptime();
  printf(1, "[FINISH] Time: %d\n", bench_end - bench_start);
  exit();
}
