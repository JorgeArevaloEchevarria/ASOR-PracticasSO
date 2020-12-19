#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main(){
    //hay que añadir un 0 delnate
    int fd = open("FicheroCreado", O_CREAT,0645);
    if (fd == -1){
        perror("fallo al abrir fichero");

    }
    return 0;
}