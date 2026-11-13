/* irq_service_level15  (FUN_a0061200)
 *
 * Clear interrupt 15 (non-maskable level) at both interrupt controllers.
 * Name basis: proven - vector table slot 14 = 0xA0061200; writes 0x8000 to 0x9F120034 and 0x9F10009C
 *
 * Matching notes
 * --------------
 * FUN_a0061200 (leon2s 0xa0061200-0xa0061224, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Its address is the word at 0xa00b6078; the table at 0xa00b6070 holds irq_service_level13, irq_service_level14
 * and this routine in consecutive words. Hardware registers are volatile; each store keeps its own address
 * constant.
 */
#define IRQ_CLEAR_REG (*(volatile unsigned int *)0x9f10009c)
#define IRQ_REG_0034  (*(volatile unsigned int *)0x9f120034)
#define LEVEL15_BIT   0x8000                    /* bit 15: interrupt level 15 */

/*
 * Service routine of interrupt level 15 (entry 14 of the vector table at 0xA8076040).
 * Only writes the level bit to the two clear registers; it does not touch the mask.
 */
void irq_service_level15(void)
{
    IRQ_REG_0034 = LEVEL15_BIT;
    IRQ_CLEAR_REG = LEVEL15_BIT;
}
