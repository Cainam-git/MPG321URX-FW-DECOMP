/* leon2m FUN_a002cb30 @ 0xa002cb30..0xa002cd38 (130 words)  GPIO pin mode: FUN_a002cb30(port, mask, on).
 * Used by the bit-banged I2C of the settings read at start-up step 5; the I2C code
 * calls it with 1 to hand a pin over before reading it and with 0 to take it back.
 * What it does (code facts): on == 1: register |= mask; on != 1: register &= ~mask; register by port 1..17 =
 * 0xCF03C014/18/1C/20/24, 0xCF03C044/4C, 0xCF03C454..7C (step 8), 0xCF03CC40..4C (jump tables 0xA002C794 for
 * on == 1 and 0xA002C7DC for the other case); port 0 and port > 17: nothing.
 * Can it wait or fail? No: a leaf, one read-modify-write, no loop.
 * Exact: both compiled jump tables equal the firmware tables and are referenced by the same dispatch.
 * The jump table at 0xa002c7dc lies outside the image piece that tools/exact.py links (see FUN_a002cd38.c).
 * Source form: 'if (on == 1) set-switch else clear-switch' (gcc moves the == arm out of line).
 * volatile = real hardware registers.
 */
void FUN_a002cb30(unsigned char port, unsigned char mask, unsigned char on)
{
    if (on == 1) {
        switch (port) {
        case 1:
            *(volatile unsigned int *)0xCF03C014 |= mask;
            break;
        case 2:
            *(volatile unsigned int *)0xCF03C018 |= mask;
            break;
        case 3:
            *(volatile unsigned int *)0xCF03C01C |= mask;
            break;
        case 4:
            *(volatile unsigned int *)0xCF03C020 |= mask;
            break;
        case 5:
            *(volatile unsigned int *)0xCF03C024 |= mask;
            break;
        case 6:
            *(volatile unsigned int *)0xCF03C044 |= mask;
            break;
        case 7:
            *(volatile unsigned int *)0xCF03C04C |= mask;
            break;
        case 8:
            *(volatile unsigned int *)0xCF03C454 |= mask;
            break;
        case 9:
            *(volatile unsigned int *)0xCF03C45C |= mask;
            break;
        case 10:
            *(volatile unsigned int *)0xCF03C464 |= mask;
            break;
        case 11:
            *(volatile unsigned int *)0xCF03C46C |= mask;
            break;
        case 12:
            *(volatile unsigned int *)0xCF03C474 |= mask;
            break;
        case 13:
            *(volatile unsigned int *)0xCF03C47C |= mask;
            break;
        case 14:
            *(volatile unsigned int *)0xCF03CC40 |= mask;
            break;
        case 15:
            *(volatile unsigned int *)0xCF03CC44 |= mask;
            break;
        case 16:
            *(volatile unsigned int *)0xCF03CC48 |= mask;
            break;
        case 17:
            *(volatile unsigned int *)0xCF03CC4C |= mask;
            break;
        }
    } else {
        switch (port) {
        case 1:
            *(volatile unsigned int *)0xCF03C014 &= ~mask;
            break;
        case 2:
            *(volatile unsigned int *)0xCF03C018 &= ~mask;
            break;
        case 3:
            *(volatile unsigned int *)0xCF03C01C &= ~mask;
            break;
        case 4:
            *(volatile unsigned int *)0xCF03C020 &= ~mask;
            break;
        case 5:
            *(volatile unsigned int *)0xCF03C024 &= ~mask;
            break;
        case 6:
            *(volatile unsigned int *)0xCF03C044 &= ~mask;
            break;
        case 7:
            *(volatile unsigned int *)0xCF03C04C &= ~mask;
            break;
        case 8:
            *(volatile unsigned int *)0xCF03C454 &= ~mask;
            break;
        case 9:
            *(volatile unsigned int *)0xCF03C45C &= ~mask;
            break;
        case 10:
            *(volatile unsigned int *)0xCF03C464 &= ~mask;
            break;
        case 11:
            *(volatile unsigned int *)0xCF03C46C &= ~mask;
            break;
        case 12:
            *(volatile unsigned int *)0xCF03C474 &= ~mask;
            break;
        case 13:
            *(volatile unsigned int *)0xCF03C47C &= ~mask;
            break;
        case 14:
            *(volatile unsigned int *)0xCF03CC40 &= ~mask;
            break;
        case 15:
            *(volatile unsigned int *)0xCF03CC44 &= ~mask;
            break;
        case 16:
            *(volatile unsigned int *)0xCF03CC48 &= ~mask;
            break;
        case 17:
            *(volatile unsigned int *)0xCF03CC4C &= ~mask;
            break;
        }
    }
}
