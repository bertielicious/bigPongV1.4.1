
#include "config.h"
#include "arrays.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
//void _interrupt isr(void)
__interrupt() void MY_ISR(void)
{
    uchar col;
    uchar row;
    if(INTCONbits.TMR0IF == HI)
    {
        for(col = 1; col <15; col++)
        {
        for(row = 0; row < 8; row++)
        {
            if(gameArray[row][col] == 1)
            {
                gameArray[row][col] = 0;
            }
            else
            {
                continue;
            }
                    
        }
        }
        DIAGNOSTIC_GREEN_LED = ~DIAGNOSTIC_GREEN_LED;
        INTCONbits.TMR0IF = LO;
        count++;
    }
}