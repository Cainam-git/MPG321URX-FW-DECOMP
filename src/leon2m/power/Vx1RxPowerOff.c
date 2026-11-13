/* Vx1RxPowerOff  (FUN_a0123384)
 *
 * Switch the V-by-One receiver off.
 * Name basis: proven - prints 'Vx1RxPowerOff' (original name); paged register writes through 0xCF03D024
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123384, flags -mcpu=v8 -O3 -g.
 * Source form: the paged write is an inlined static helper with a local base 0x7600 (the firmware builds the
 * window address at run time, as in input_unit_setup_by_mode); the delay loop body is a single __asm__("nop"), the nop the
 * firmware executes on each pass. volatile: hardware registers only.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern int dbg_printf(const char *fmt, ...);

/* Page register: selects the page of the register window at register number 0x7600 (word 0xCF000000 | n << 2). */
#define PAGE_REG 0xcf03d024

/* Write val to register 'reg' of page 'page' of the window; the previous low byte of the page register is restored. */
static void pwr(unsigned int page, unsigned int reg, unsigned int val)
{
    unsigned int saved_page = R(PAGE_REG);
    unsigned int base = 0x7600;

    R(PAGE_REG) = page;
    R(0xcf000000 | ((base + reg) << 2)) = val;
    R(PAGE_REG) = saved_page & 0xff;
}

/*
 * Set bits 2 and 3 of 0xCF03C548, clear 0xCF011814, then write through the page register: page 0xC register 0x14 =
 * 0x44, page 0xC register 0x12 = 0x11, page 0 register 0x03 = 0xFB, page 0xC register 0x11 = 1; wait 0x400 loop
 * passes; page 0xC register 0x11 = 0; print "Vx1RxPowerOff". Called by startup_init_converter_sources and by
 * sys_shut_down_blocks.
 */
void Vx1RxPowerOff(void)
{
    unsigned short i;

    R(0xcf03c548) |= 0xc;
    R(0xcf011814) = 0;
    pwr(0xc, 0x14, 0x44);
    pwr(0xc, 0x12, 0x11);
    pwr(0, 0x03, 0xfb);
    pwr(0xc, 0x11, 1);
    for (i = 0; i < 0x400; i++)
        __asm__("nop");
    pwr(0xc, 0x11, 0);
    dbg_printf("Vx1RxPowerOff\r\n");
}
