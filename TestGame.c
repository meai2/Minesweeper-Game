//Note: Don't use rand() for security. If you need a cryptographically secure number, see this answer instead.

#include <time.h>
#include <stdlib.h>

srand(time(NULL));   // Initialization, should only be called once.
int r = rand()/RAND_MAX;  