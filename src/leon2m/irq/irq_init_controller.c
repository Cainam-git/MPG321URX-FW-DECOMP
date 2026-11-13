/* irq_init_controller  (FUN_a0029858)
 *
 * Reset both interrupt controllers, enable levels 1..14, unmask level-1 and level-4 sources.
 * Note: 0x9F000090 is the LEON2 interrupt mask register and 0x9F00009C its clear register.
 * Name basis: derived - LEON2 interrupt controller layout (mask 0x90, clear 0x9C); caller startup_init_core at
 *   start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0029858 @ 0xa0029858-0xa002992c (53 words), flags -mcpu=v8 -O3 -g.
 * Source form: irq_unmask_sources is a static copy of the function just before this one and is inlined; the firmware keeps the two block bases 0x9f020034 / 0x9f02006c in registers and adds 4 * level.
 */
extern void reg_write32(unsigned int addr, unsigned int value);
extern void reg_write32_masked(volatile unsigned int *p, unsigned int v, unsigned int mask);

/* Unmask the given sources of interrupt level level and clear their pending bits. */
static void irq_unmask_sources(int level, unsigned short mask)
{
    reg_write32_masked((volatile unsigned int *)(0x9f020034 + level * 4), 0, mask);
    reg_write32(0x9f02006c + level * 4, mask);
}

#define IRQ_LEVEL_1 1          /* interrupt level 1 */
#define IRQ_LEVEL_4 4          /* interrupt level 4 */
#define IRQ_LEVELS_1_TO_14_MASK 0x7ffe /* bits 1..14: interrupt levels 1..14 */

/*
 * Reset both interrupt controllers, enable interrupt levels 1..14, and unmask
 * level-1 and level-4 sources.
 *
 * In order: the LEON2 mask register 0x9F000090 is cleared; 0x9F020028, the LEON2 clear register 0x9F00009C and
 * 0x9F020034 get 0xFFFF; bits 1..14 are set in 0x9F020030 and 0x9F000090 and cleared in 0x9F020028; 0x9F020034
 * gets 0x7FFE; bit 20 is set in 0x9F020038 (the mask register of level 1); then irq_unmask_sources unmasks
 * sources 0x10 of level 1 and 0x25 (bits 0, 2, 5) of level 4 and clears their pending bits.
 *
 * Caller: startup_init_core.
 */
void irq_init_controller(void)
{
    reg_write32(0x9f000090, 0);
    reg_write32(0x9f020028, 0xffff);
    reg_write32(0x9f00009c, 0xffff);
    reg_write32(0x9f020034, 0xffff);
    reg_write32_masked((volatile unsigned int *)0x9f020030, IRQ_LEVELS_1_TO_14_MASK, IRQ_LEVELS_1_TO_14_MASK);
    reg_write32_masked((volatile unsigned int *)0x9f000090, IRQ_LEVELS_1_TO_14_MASK, IRQ_LEVELS_1_TO_14_MASK);
    reg_write32_masked((volatile unsigned int *)0x9f020028, 0, IRQ_LEVELS_1_TO_14_MASK);
    reg_write32(0x9f020034, IRQ_LEVELS_1_TO_14_MASK);
    reg_write32_masked((volatile unsigned int *)0x9f020038, 0x100000, 0x100000);
    irq_unmask_sources(IRQ_LEVEL_1, 0x10);
    irq_unmask_sources(IRQ_LEVEL_4, 0x25);
}
