#include <stdio.h>
#include "system.h"
#include <sys/alt_irq.h>
#include <io.h>
#include <alt_types.h>
#include "sys/alt_sys_init.h"
#include "altera_avalon_pio_regs.h"

static void irqhandler(void* context, alt_u32 id)
{
    // Réinitialiser le registre de capture de bord pour effacer l'interruption
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0xF0);

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

int main()
{
    alt_printf("main() started\n");

    // Configurer le bouton pour générer des interruptions
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE, 0xF1);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0xF1);

    // Enregistrer l'interruption
    alt_irq_register(PIO_1_IRQ, NULL, irqhandler);

    // Boucle principale
    while(1) {
        // Logique principale ici (si nécessaire)
        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0x0);
    }

    return 0;
}