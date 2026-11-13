/* irq_service_level14  (FUN_a006119c)
 *
 * Service interrupt 14, which has no sources: mark it in service, clear it and unmask it.
 * Name basis: proven - vector table slot 13 = 0xA006119C; bit 0x4000 through 0x9F100090 / 0x9F120028 /
 *   0x9F120034 / 0x9F10009C
 *
 * Matching notes
 * --------------
 * FUN_a006119c (leon2s 0xa006119c-0xa0061200, 100 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Same sequence as irq_service_level13. Its address is the word at 0xa00b6074.
 */
#define IRQ_MASK_REG   (*(volatile unsigned int *)0x9f100090)   /* bit n = level n */
#define IRQ_CLEAR_REG  (*(volatile unsigned int *)0x9f10009c)
#define IRQ_ACTIVE_REG (*(volatile unsigned int *)0x9f120028)
#define IRQ_REG_0034   (*(volatile unsigned int *)0x9f120034)
#define LEVEL14_BIT    0x4000                   /* bit 14: interrupt level 14 */

/*
 * Service routine of interrupt level 14 (entry 13 of the vector table at 0xA8076040).
 * Same sequence as irq_service_level13: no handler table, only the mask and clear registers.
 */
void irq_service_level14(void)
{
    IRQ_MASK_REG &= ~LEVEL14_BIT;
    IRQ_ACTIVE_REG |= LEVEL14_BIT;
    IRQ_REG_0034 = LEVEL14_BIT;
    IRQ_CLEAR_REG = LEVEL14_BIT;
    IRQ_ACTIVE_REG &= ~LEVEL14_BIT;
    IRQ_MASK_REG |= LEVEL14_BIT;
}
