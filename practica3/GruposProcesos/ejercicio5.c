#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
/*
[root@localhost GruposProcesos]# ./ejercicio5
PID: 16432
PPID: 14967
PGID: 2678
LIMIT: 4096
*/

int main() {

  printf("PID: %i\n", getpid());
  printf("PPID: %i\n", getppid());
  printf("PGID: %i\n", getsid(getpid()));
  struct rlimit limit;
  if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
    perror("Unable to get the resource limits");
    return -1;
  }
   printf("LIMIT: %li\n", limit.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  printf("CWD: %s\n", path);
  free (path);

  return 0;
}