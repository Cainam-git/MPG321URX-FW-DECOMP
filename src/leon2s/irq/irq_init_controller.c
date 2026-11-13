/* irq_init_controller  (FUN_a00b17e8)
 *
 * Mask and clear all interrupt levels, set up register 0x9F120038, then enable interrupt level 1.
 * Note: In 0x9F120038 bits 0, 2, 3, 4 are cleared and bits 16, 18, 19, 20 set; what these bits do is not
 *   shown.
 * Name basis: derived - 0 to the level mask 0x9F100090, 0xFFFF to 0x9F120028 and to the clear registers
 *   0x9F10009C and 0x9F120034; then bit 1 of 0x9F120028 cleared and bit 1 of 0x9F100090 set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b17e8 @ 0xa00b17e8-0xa00b18ac (49 words), flags -mcpu=v8 -Os -g.
 * Leaf routine, no calls. Every register access is a separate volatile read-modify-write, as written.
 */
typedef unsigned int uint;

#define IRQ_REG_9F100090 (*(volatile uint *)0x9f100090)
#define IRQ_REG_9F10009C (*(volatile uint *)0x9f10009c)
#define IRQ_REG_9F120028 (*(volatile uint *)0x9f120028)
#define IRQ_REG_9F120034 (*(volatile uint *)0x9f120034)
#define IRQ_REG_9F120038 (*(volatile uint *)0x9f120038)

/*
 * Set up the interrupt controller registers of the input processor.
 *
 * In order: 0x9F100090 = 0; 0xFFFF into 0x9F120028, 0x9F10009C and 0x9F120034; in 0x9F120038 each of bits 0, 2,
 * 3 and 4 is cleared and the bit 16 above it (bits 16, 18, 19 and 20) is set; then bit 1 of 0x9F120028 is
 * cleared and bit 1 of 0x9F100090 is set.
 * Called by startup_init_system.
 */
void irq_init_controller(void)
{
    IRQ_REG_9F100090 = 0;
    IRQ_REG_9F120028 = 0xffff;
    IRQ_REG_9F10009C = 0xffff;
    IRQ_REG_9F120034 = 0xffff;
    IRQ_REG_9F120038 = IRQ_REG_9F120038 & ~1;
    IRQ_REG_9F120038 = IRQ_REG_9F120038 | 0x10000;
    IRQ_REG_9F120038 = IRQ_REG_9F120038 & ~4;
    IRQ_REG_9F120038 = IRQ_REG_9F120038 | 0x40000;
    IRQ_REG_9F120038 = IRQ_REG_9F120038 & ~8;
    IRQ_REG_9F120038 = IRQ_REG_9F120038 | 0x80000;
    IRQ_REG_9F120038 = IRQ_REG_9F120038 & ~0x10;
    IRQ_REG_9F120038 = IRQ_REG_9F120038 | 0x100000;
    IRQ_REG_9F120028 = IRQ_REG_9F120028 & ~2;
    IRQ_REG_9F100090 = IRQ_REG_9F100090 | 2;
}
