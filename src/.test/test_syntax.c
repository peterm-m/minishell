#include <time.h>
#include <stdlib.h>
#include "common.h"
//void syntax(t_dlst *lex)

/*
Casos de prueba:

Pipe:
echo "hola" | cat
cmd suffix | cmd suffix suffix | cmd 

puerta OR:
cmd || cmd || cmd 
(cmd || cmd) || cmd 
cmd || (cmd || cmd) 

puerta AND:
cmd && cmd && cmd
(cmd && cmd) && cmd 
cmd && (cmd && cmd)

Redirección:
cmd suffix > file
cmd suffix >> file

Io number:
cmd 2>

*/