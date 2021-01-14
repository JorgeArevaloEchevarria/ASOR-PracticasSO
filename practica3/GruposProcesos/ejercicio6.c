#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

/*
[root@localhost GruposProcesos]# ./ejercicio6
[Padre] Proceso 16578 (Padre: 14967)
[Padre]PID: 16578
[Padre]PPID: 14967
[Padre]PPID: 2678
[Padre]LIMIT: 4096
[Padre]CWD: /home/cursoredes/Desktop/workspace/ASOR-PracticasSO/practica3/GruposProcesos
[root@localhost GruposProcesos]# [Hijo] Proceso 16579 (Padre: 1)
[Hijo]PID: 16579
[Hijo]PPID: 1
[Hijo]PPID: 16579
[Hijo]LIMIT: 4096
[Hijo]CWD: /tmp

¿Qué pasa si el padre termina antes que el hijo?
El hijo se queda huérfano y el ppid lo recoge la shell o init.
*/

void printAtributos(char *type){
  printf("[%s]PID: %i\n", type,getpid());
  printf("[%s]PPID: %i\n", type, getppid());
  printf("[%s]PPID: %i\n", type, getsid(getpid()));
  struct rlimit limit;
  if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
    perror("Unable to get the resource limits");
  }
  printf("[%s]LIMIT: %li\n", type, limit.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  printf("[%s]CWD: %s\n", type, path);
  free (path);
}

int main() {

  // pid_t mi_pid, pid, mi_ppid, mi_sid;
  // char *ncwd;

  pid_t pid = fork();

  switch (pid) {
    case -1:
      perror("fork");
      exit(-1);
        break;
    case 0:;
      pid_t mi_sid = setsid(); //Creamos una nueva sesión
      char *ncwd= chdir("/tmp"); //Cambiamos el directorio

      printf("[Hijo] Proceso %i (Padre: %i)\n",getpid(),getppid());
      printAtributos("Hijo");
      //sleep(100);
      break;

    default:
        printf("[Padre] Proceso %i (Padre: %i)\n",getpid(),getppid());
        printAtributos("Padre");
        break;
  }
    return 0;
}