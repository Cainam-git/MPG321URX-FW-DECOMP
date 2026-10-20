/* leon2m FUN_a002cd38 @ 0xa002cd38..0xa002cea8 (92 words)  GPIO pin read: FUN_a002cd38(port, mask) -> 1 if
 * (input register of port & mask) != 0, else 0. Used by the bit-banged I2C of the settings read
 * (FUN_a002a910 / FUN_a002ab04 / FUN_a002ae4c / FUN_a002bb28) at start-up step 5.
 * Code: switch on port 1..17 (jump table 0xA002C824, 18 entries) -> one 32-bit load of
 * 0xCF03C000/04/08/0C/10, 0xCF03C040/48, 0xCF03C450..78 (step 8), 0xCF03CC00..0C; port 0 and port > 17 -> 0.
 * Leaf function: one load, no loop, no wait.
 * Exact: rawcmp 0/92 and the compiled jump table equals the firmware table (entries relative to the function). The
 * jf score reads 99.00 'jump table at 0xa002c824 is outside the image' only because tools/exact.py maps jump
 * tables with the main-body runtime shift (+0xA0060000), which does not apply to this boot piece (it runs at its
 * listing address). volatile = real hardware registers.
 */
unsigned char FUN_a002cd38(unsigned char port, unsigned char mask)
{
    unsigned char v;

    switch (port) {
    case 1:
        v = *(volatile unsigned int *)0xCF03C000 & mask;
        break;
    case 2:
        v = *(volatile unsigned int *)0xCF03C004 & mask;
        break;
    case 3:
        v = *(volatile unsigned int *)0xCF03C008 & mask;
        break;
    case 4:
        v = *(volatile unsigned int *)0xCF03C00C & mask;
        break;
    case 5:
        v = *(volatile unsigned int *)0xCF03C010 & mask;
        break;
    case 6:
        v = *(volatile unsigned int *)0xCF03C040 & mask;
        break;
    case 7:
        v = *(volatile unsigned int *)0xCF03C048 & mask;
        break;
    case 8:
        v = *(volatile unsigned int *)0xCF03C450 & mask;
        break;
    case 9:
        v = *(volatile unsigned int *)0xCF03C458 & mask;
        break;
    case 10:
        v = *(volatile unsigned int *)0xCF03C460 & mask;
        break;
    case 11:
        v = *(volatile unsigned int *)0xCF03C468 & mask;
        break;
    case 12:
        v = *(volatile unsigned int *)0xCF03C470 & mask;
        break;
    case 13:
        v = *(volatile unsigned int *)0xCF03C478 & mask;
        break;
    case 14:
        v = *(volatile unsigned int *)0xCF03CC00 & mask;
        break;
    case 15:
        v = *(volatile unsigned int *)0xCF03CC04 & mask;
        break;
    case 16:
        v = *(volatile unsigned int *)0xCF03CC08 & mask;
        break;
    case 17:
        v = *(volatile unsigned int *)0xCF03CC0C & mask;
        break;
    default:
        v = 0;
        break;
    }
    return v != 0;
}
