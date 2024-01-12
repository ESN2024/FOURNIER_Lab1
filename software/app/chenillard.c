#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "unistd.h"



int main (){
        int LED = 0X01;
        
        while (1){ 
                IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,LED);
                usleep(100000);
                LED=LED<<1;
                if (LED==0X80){
                        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,LED);
                        usleep(100000);
                        LED=0X01;
                }
        }
}