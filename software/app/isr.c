#include <stdio.h>
#include "system.h"
#include <sys/alt_irq.h>
#include <io.h>
#include <alt_types.h>
#include "sys/alt_sys_init.h"
#include "altera_avalon_pio_regs.h"

volatile __uint8_t sleep = 1;
int LED = 0X01;

static void irqhandler_bp(void* context, alt_u32 id)
{
    IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,LED);
    usleep(100000/sleep);
    LED=LED<<1;
    if (LED==0X80){
        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,LED);
        usleep(100000/sleep);
        LED=0X01;
    }
}


static void irqhandler_sw(void* context, alt_u32 id)
{
    // Réinitialiser le registre de capture de bord pour effacer l'interruption
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_2_BASE, 0x0F);
    alt_printf("%x \n",IORD_ALTERA_AVALON_PIO_DATA(PIO_2_BASE));
    
    sleep=IORD_ALTERA_AVALON_PIO_DATA(PIO_2_BASE)+1;  
}


int main()
{
    alt_printf("main() started\n");
    alt_printf("hello");

    // Configurer le bouton pour générer des interruptions
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE, 0x1);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x1);

    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_2_BASE, 0x0F);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_2_BASE, 0x0F);

    // Enregistrer l'interruption
    alt_irq_register(PIO_1_IRQ, NULL, irqhandler_bp);
    alt_irq_register(PIO_2_IRQ, NULL, irqhandler_sw);

    // Boucle principale
    while(1) {
        // Logique principale ici (si nécessaire)
        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0x0);
    }

    return 0;
}