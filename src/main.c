#include "../include/project_1.h"

#ifdef FRDM
#define printf(...)
#endif

/*
* The main fucntion that will call the proejct report. All Pre-processing gets
* complete before Main is called. 
*/
int main()
{
    project_1_report();
    return 0;
}
