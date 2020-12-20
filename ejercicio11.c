#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>


int main(int argc, char **argv) {

	struct stat sb;
    char **copia ;

	if(stat(argv[1], &sb) == -1) {
		perror("stat()");
		return -1;
	}

    switch (sb.st_mode & S_IFMT) {
           
           case S_IFREG:

                stpcpy(rigido,argv[1]);
                strcat(rigido,".hard");
                if(link(argv[1],rigido) == -1){
                    perror("Fallo al crear el enlace rigido \n");
                    return -1;
                }

                stpcpy(nombreSimbolico,argv[1]);
                strcat(nombreSimbolico,".sym");
                if(symlink(argv[1],nombreSimbolico) == -1){
                    perror("Fallo al crear el enlace simbolico \n");
                    return -1;
                }
             
             break;
               
           default:       printf("unknown?\n");                break;
    }
}