/* leon2m FUN_a002c86c @ 0xa002c86c..0xa002cb30 (177 words)  GPIO pin write: FUN_a002c86c(port, mask, level)
 * Used by the bit-banged I2C of the settings read (start-up step 5, before the hook) and as the GPIO
 * primitive of the post-hook path.
 * What it does (code facts): switch on bit 0 of level; 1: data = data | second | mask; 0: data = (data | second) &
 * ~mask; 'data' = the port register FUN_a002cd38 reads (ports 1..17: 0xCF03C000/04/08/0C/10, 0xCF03C040/48,
 * 0xCF03C450..78, 0xCF03CC00..0C), 'second' = the register FUN_a002cb30 sets/clears (0xCF03C014.., port 6 =
 * 0xCF03C044); jump tables 0xA002C74C (level 0) and 0xA002C704 (level 1); port 0 and port > 17: nothing. Every
 * write ORs in the second register.
 * Leaf function: one read-modify-write, no loop, no failure path.
 * Exact: both compiled jump tables equal the firmware tables with the same
 * dispatch. Exact form: 'switch (level & 1) { case 1: set-switch; default: clear-switch; }' (an if/else
 * keeps the wrong arm as the fall-through). volatile = real hardware registers.
 */
void FUN_a002c86c(unsigned char port, unsigned char mask, unsigned char level)
{
    switch (level & 1) {
    case 1:
        switch (port) {
        case 1:
            *(volatile unsigned int *)0xCF03C000 = *(volatile unsigned int *)0xCF03C000 | *(volatile unsigned int *)0xCF03C014 | mask;
            break;
        case 2:
            *(volatile unsigned int *)0xCF03C004 = *(volatile unsigned int *)0xCF03C004 | *(volatile unsigned int *)0xCF03C018 | mask;
            break;
        case 3:
            *(volatile unsigned int *)0xCF03C008 = *(volatile unsigned int *)0xCF03C008 | *(volatile unsigned int *)0xCF03C01C | mask;
            break;
        case 4:
            *(volatile unsigned int *)0xCF03C00C = *(volatile unsigned int *)0xCF03C00C | *(volatile unsigned int *)0xCF03C020 | mask;
            break;
        case 5:
            *(volatile unsigned int *)0xCF03C010 = *(volatile unsigned int *)0xCF03C010 | *(volatile unsigned int *)0xCF03C024 | mask;
            break;
        case 6:
            *(volatile unsigned int *)0xCF03C040 = *(volatile unsigned int *)0xCF03C040 | *(volatile unsigned int *)0xCF03C044 | mask;
            break;
        case 7:
            *(volatile unsigned int *)0xCF03C048 = *(volatile unsigned int *)0xCF03C048 | *(volatile unsigned int *)0xCF03C04C | mask;
            break;
        case 8:
            *(volatile unsigned int *)0xCF03C450 = *(volatile unsigned int *)0xCF03C450 | *(volatile unsigned int *)0xCF03C454 | mask;
            break;
        case 9:
            *(volatile unsigned int *)0xCF03C458 = *(volatile unsigned int *)0xCF03C458 | *(volatile unsigned int *)0xCF03C45C | mask;
            break;
        case 10:
            *(volatile unsigned int *)0xCF03C460 = *(volatile unsigned int *)0xCF03C460 | *(volatile unsigned int *)0xCF03C464 | mask;
            break;
        case 11:
            *(volatile unsigned int *)0xCF03C468 = *(volatile unsigned int *)0xCF03C468 | *(volatile unsigned int *)0xCF03C46C | mask;
            break;
        case 12:
            *(volatile unsigned int *)0xCF03C470 = *(volatile unsigned int *)0xCF03C470 | *(volatile unsigned int *)0xCF03C474 | mask;
            break;
        case 13:
            *(volatile unsigned int *)0xCF03C478 = *(volatile unsigned int *)0xCF03C478 | *(volatile unsigned int *)0xCF03C47C | mask;
            break;
        case 14:
            *(volatile unsigned int *)0xCF03CC00 = *(volatile unsigned int *)0xCF03CC00 | *(volatile unsigned int *)0xCF03CC40 | mask;
            break;
        case 15:
            *(volatile unsigned int *)0xCF03CC04 = *(volatile unsigned int *)0xCF03CC04 | *(volatile unsigned int *)0xCF03CC44 | mask;
            break;
        case 16:
            *(volatile unsigned int *)0xCF03CC08 = *(volatile unsigned int *)0xCF03CC08 | *(volatile unsigned int *)0xCF03CC48 | mask;
            break;
        case 17:
            *(volatile unsigned int *)0xCF03CC0C = *(volatile unsigned int *)0xCF03CC0C | *(volatile unsigned int *)0xCF03CC4C | mask;
            break;
        }
        break;
    default:
        switch (port) {
        case 1:
            *(volatile unsigned int *)0xCF03C000 = (*(volatile unsigned int *)0xCF03C000 | *(volatile unsigned int *)0xCF03C014) & ~mask;
            break;
        case 2:
            *(volatile unsigned int *)0xCF03C004 = (*(volatile unsigned int *)0xCF03C004 | *(volatile unsigned int *)0xCF03C018) & ~mask;
            break;
        case 3:
            *(volatile unsigned int *)0xCF03C008 = (*(volatile unsigned int *)0xCF03C008 | *(volatile unsigned int *)0xCF03C01C) & ~mask;
            break;
        case 4:
            *(volatile unsigned int *)0xCF03C00C = (*(volatile unsigned int *)0xCF03C00C | *(volatile unsigned int *)0xCF03C020) & ~mask;
            break;
        case 5:
            *(volatile unsigned int *)0xCF03C010 = (*(volatile unsigned int *)0xCF03C010 | *(volatile unsigned int *)0xCF03C024) & ~mask;
            break;
        case 6:
            *(volatile unsigned int *)0xCF03C040 = (*(volatile unsigned int *)0xCF03C040 | *(volatile unsigned int *)0xCF03C044) & ~mask;
            break;
        case 7:
            *(volatile unsigned int *)0xCF03C048 = (*(volatile unsigned int *)0xCF03C048 | *(volatile unsigned int *)0xCF03C04C) & ~mask;
            break;
        case 8:
            *(volatile unsigned int *)0xCF03C450 = (*(volatile unsigned int *)0xCF03C450 | *(volatile unsigned int *)0xCF03C454) & ~mask;
            break;
        case 9:
            *(volatile unsigned int *)0xCF03C458 = (*(volatile unsigned int *)0xCF03C458 | *(volatile unsigned int *)0xCF03C45C) & ~mask;
            break;
        case 10:
            *(volatile unsigned int *)0xCF03C460 = (*(volatile unsigned int *)0xCF03C460 | *(volatile unsigned int *)0xCF03C464) & ~mask;
            break;
        case 11:
            *(volatile unsigned int *)0xCF03C468 = (*(volatile unsigned int *)0xCF03C468 | *(volatile unsigned int *)0xCF03C46C) & ~mask;
            break;
        case 12:
            *(volatile unsigned int *)0xCF03C470 = (*(volatile unsigned int *)0xCF03C470 | *(volatile unsigned int *)0xCF03C474) & ~mask;
            break;
        case 13:
            *(volatile unsigned int *)0xCF03C478 = (*(volatile unsigned int *)0xCF03C478 | *(volatile unsigned int *)0xCF03C47C) & ~mask;
            break;
        case 14:
            *(volatile unsigned int *)0xCF03CC00 = (*(volatile unsigned int *)0xCF03CC00 | *(volatile unsigned int *)0xCF03CC40) & ~mask;
            break;
        case 15:
            *(volatile unsigned int *)0xCF03CC04 = (*(volatile unsigned int *)0xCF03CC04 | *(volatile unsigned int *)0xCF03CC44) & ~mask;
            break;
        case 16:
            *(volatile unsigned int *)0xCF03CC08 = (*(volatile unsigned int *)0xCF03CC08 | *(volatile unsigned int *)0xCF03CC48) & ~mask;
            break;
        case 17:
            *(volatile unsigned int *)0xCF03CC0C = (*(volatile unsigned int *)0xCF03CC0C | *(volatile unsigned int *)0xCF03CC4C) & ~mask;
            break;
        }
        break;
    }
}
