#include <stdio.h>
#include <phase1.h>
#include <phase2.h>
#include "message.h"

extern int debugflag2;
static int clockIteration = 0;

/* an error method to handle invalid syscalls */
void nullsys(sysargs *args)
{
    USLOSS_Console("nullsys(): Invalid syscall. Halting...\n");
    USLOSS_Halt(1);
} /* nullsys */


void clockHandler2(int type, void* unitPointer)
{
    int unit = *((int*) unitPointer);

    if (DEBUG2 && debugflag2)
    {
        USLOSS_Console("clockHandler2(): called\n");
    }
    if(type != USLOSS_CLOCK_DEV)
    {
        USLOSS_Console("clockHandler2(): called with wrong type %d\n", type);
    }
    if(unit != 0)
    {
        USLOSS_Console("clockHandler2(): called with invalid unit number %d\n", unit);
    }

    timeSlice();
    static int clockIteration = 0;
    clockIteration++;
    if(clockIteration == 5)
    {
        int mboxID = getDeviceMboxID(type, unit);
        MboxCondSend(mboxID, NULL, 0);
        clockIteration = 0;
    }


} /* clockHandler */


void diskHandler(int dev, int unit)
{

    if (DEBUG2 && debugflag2)
    {
        USLOSS_Console("diskHandler(): called\n");
    }

} /* diskHandler */


void termHandler(int dev, int unit)
{

    if (DEBUG2 && debugflag2)
    {
        USLOSS_Console("termHandler(): called\n");
    }


} /* termHandler */


void syscallHandler(int dev, int unit)
{

    if (DEBUG2 && debugflag2)
    {
        USLOSS_Console("syscallHandler(): called\n");
    }


} /* syscallHandler */
