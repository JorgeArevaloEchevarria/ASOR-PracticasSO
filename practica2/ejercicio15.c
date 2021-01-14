#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
int fd;

	if((fd = open(argv[1], O_CREAT| O_RDONLY, 0777)) == -1) {
		perror("open()");
		exit -1;

	}else{
        int cerrojo = lockf(fd, F_TEST ,)


    }