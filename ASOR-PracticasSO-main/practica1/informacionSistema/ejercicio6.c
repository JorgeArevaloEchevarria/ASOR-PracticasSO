#include <unistd.h>
#include <stdio.h>

int main() {
	printf("Longitud Máxima de Argumentos: %li\n", sysconf(_SC_ARG_MAX));
	printf("Número máximo de hijos: %li\n", sysconf(_SC_CHILD_MAX));
	printf("Número máximo de ficheros: %li\n", sysconf(_SC_OPEN_MAX));
	return 0;
}
/*
[root@localhost informacionSistema]# ./ejercicio6
Longitud Máxima de Argumentos: 2097152
Número máximo de hijos: 1820
Número máximo de ficheros: 1024
*/