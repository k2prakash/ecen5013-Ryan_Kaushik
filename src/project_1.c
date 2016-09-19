#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include "../include/memory.h"
#include "../include/data.h"
#include "../include/project_1.h"

#ifdef FRDM
#define printf(...) (0)
#endif

void project_1_report()
{
    printf("Hello, World!\n");
    return;
}

