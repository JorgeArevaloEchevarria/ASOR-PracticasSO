#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

	struct stat sb;

	if(stat(argv[1], &sb) == -1) {
		perror("stat()");
		return -1;
	}

    switch (sb.st_mode & S_IFMT) {
           
           case S_IFREG:
             printf("regular file\n");            
             link(2);
             symlink(2);
             
             break;
               
           default:       printf("unknown?\n");                break;
    }
}