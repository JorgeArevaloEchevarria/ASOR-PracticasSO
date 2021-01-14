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

    printf("I-node number:            %ld\n", (long) sb.st_ino);
    printf("ID of containing device:  [%lx,%lx]\n",(long) major(sb.st_dev), (long) minor(sb.st_dev));

    printf("File type:                ");

           switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }


    printf("Ownership:                UID=%ld   GID=%ld\n",(long) sb.st_uid, (long) sb.st_gid)
    printf("Last status change:       %i", ctime(&sb.st_ctime));//
    printf("Last file modification:   %i", ctime(&sb.st_mtime));//ultima modificacion
}