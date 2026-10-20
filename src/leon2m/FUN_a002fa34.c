/* leon2m FUN_a002fa34 @ 0xa002fa34-0xa002fae0 (43 words).
 * Reads FUN_a002c194(3), calls FUN_a002c11c(2, 0xdd), then reads FUN_a002c194(3) up to 0x7d001 times until it
 * returns 0xaa, with eight nop instructions (written as asm nops) after each read. On 0xaa: FUN_a002c11c(1, 0), (2, 0) and (3, 0). Otherwise: FUN_a002c11c(1, 0), (2, 0x88) and (3, 0).
 */
extern unsigned char FUN_a002c194(unsigned char n);
extern void FUN_a002c11c(unsigned char n, unsigned char v);

void FUN_a002fa34(void)
{
    unsigned int i = 0;

    FUN_a002c194(3);
    FUN_a002c11c(2, 0xdd);
    do {
        if (FUN_a002c194(3) == 0xaa) {
            FUN_a002c11c(1, 0);
            FUN_a002c11c(2, 0);
            FUN_a002c11c(3, 0);
            return;
        }
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
    } while (++i <= 0x7d000);
    FUN_a002c11c(1, 0);
    FUN_a002c11c(2, 0x88);
    FUN_a002c11c(3, 0);
}
