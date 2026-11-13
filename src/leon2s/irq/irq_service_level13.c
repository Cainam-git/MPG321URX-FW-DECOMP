/* irq_service_level13  (FUN_a0061138)
 *
 * Service interrupt 13, which has no sources: mark it in service, clear it and unmask it.
 * Name basis: proven - vector table slot 12 = 0xA0061138; bit 0x2000 through 0x9F100090 / 0x9F120028 /
 *   0x9F120034 / 0x9F10009C
 *
 * Matching notes
 * --------------
 * FUN_a0061138 (leon2s 0xa0061138-0xa006119c, 100 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Its address is the word at 0xa00b6070 (a table of routine addresses).
 */
#define IRQ_MASK_REG   (*(volatile unsigned int *)0x9f100090)   /* bit n = level n */
#define IRQ_CLEAR_REG  (*(volatile unsigned int *)0x9f10009c)
#define IRQ_ACTIVE_REG (*(volatile unsigned int *)0x9f120028)
#define IRQ_REG_0034   (*(volatile unsigned int *)0x9f120034)
#define LEVEL13_BIT    0x2000                   /* bit 13: interrupt level 13 */

/*
 * Service routine of interrupt level 13 (entry 12 of the vector table at 0xA8076040).
 * It has no handler table: it takes the level out of the mask, writes the level bit to the two clear registers
 * and puts the level back into the mask.
 */
void irq_service_level13(void)
{
    IRQ_MASK_REG &= ~LEVEL13_BIT;
    IRQ_ACTIVE_REG |= LEVEL13_BIT;
    IRQ_REG_0034 = LEVEL13_BIT;
    IRQ_CLEAR_REG = LEVEL13_BIT;
    IRQ_ACTIVE_REG &= ~LEVEL13_BIT;
    IRQ_MASK_REG |= LEVEL13_BIT;
}
