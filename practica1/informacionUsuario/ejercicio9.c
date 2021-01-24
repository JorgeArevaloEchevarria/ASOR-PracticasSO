#include <stdio.h>
#include <stdlib.h>
//Gestión de errores:
#include <errno.h>
//Getuid/sysconf
#include <unistd.h>
//Perror
#include <string.h>
//Uname
#include <sys/utsname.h>
//id
#include <sys/types.h>
//passwd
#include <pwd.h>

/*
El setuid se utiliza para dar privilegios elevados en determinados archivos para usuarios que no lo poseen,
 como por ejemplo en el archivo /etc/bin/passwd para que todos puedan cambiar la contraseña pero que no puedan
  leer ni escribir las otras. Por lo tanto, cuando el uid es distinto del euid tiene el bit setuid activado.
*/

int main(){

    uid_t uid = getuid();

    printf("UID Real: %d\n", getuid());
    printf("UID efectivo: %d\n", geteuid());

    struct passwd *pass= getpwuid(uid);

    char *name = pass->pw_name;
    char *dir = pass->pw_dir;
    char *info = pass->pw_gecos;
     printf("Username: %s\n", name);
    printf("Home: %s\n", dir);
    printf("Info: %s\n",info);

  return 1;
}
