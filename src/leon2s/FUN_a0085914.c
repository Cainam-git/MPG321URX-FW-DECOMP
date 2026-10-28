/* FUN_a0085914 (leon2s 0xa0085914-0xa0085b14, 512 bytes), flags -mcpu=v8 -Os -g.
 * port != 0: sets bit 4 of register 0xcf010c08, then writes the low 3 bits of 0xcf010c00: 2 or 1 when byte 1 of
 * DAT_a807cd00 is 4 or 2, plus 1 or 2 when DAT_a807cd2d is 2 or 4. port 0: sets bit 4 of 0xcf010c00, then the
 * low 3 bits of 0xcf0116dc come from the low nibble of FUN_a00a78b4(0, 3): 4 selects by FUN_a00858f0(0) (0x81 /
 * 0x71: 1 unless FUN_a00adf64(0 / 1, DAT_a807a94d) is 1; 0x51 / 0x61: 1 when FUN_a00a29d8(0 / 1) is 1, else 2;
 * others 2), 2 gives 1 unless FUN_a00858f0(0) is 0x81 or 0x71; when bit 3 of FUN_a00a78b4(0, 0x6f) is set a
 * value of 2 becomes 4, others are incremented. Ends with FUN_a00a7940(port, 0, 8, 1) and (port, 0, 8, 0).
 * Source form: the new value r is an unsigned char copied from the masked register word; the port != 0 arm
 * uses its own word variable; the bit-3 step tests '(r & 7) == 2' first. DAT_a807cd00 is volatile: the
 * firmware reads byte 1 again for the second compare.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern volatile unsigned char DAT_a807cd00[];
extern unsigned char DAT_a807cd2d;
extern unsigned char DAT_a807a94d;
extern unsigned int FUN_a00a78b4(unsigned int, unsigned short);
extern unsigned char FUN_a00858f0(unsigned int);
extern unsigned int FUN_a00adf64(unsigned char, int);
extern unsigned char FUN_a00a29d8(unsigned int);
extern void FUN_a00a7940(unsigned int port, short reg, unsigned int mask, unsigned int mode);

void FUN_a0085914(unsigned int port)
{
    unsigned int v;
    unsigned char r;
    unsigned char c;

    if ((unsigned char)port) {
        unsigned int w;

        R(0xcf010c08) = (R(0xcf010c08) | 0x10) & 0xff;
        w = R(0xcf010c00) & ~7;
        r = w;
        if (DAT_a807cd00[1] == 4)
            r = w | 2;
        else if (DAT_a807cd00[1] == 2)
            r = w | 1;
        if (DAT_a807cd2d == 2)
            r++;
        else if (DAT_a807cd2d == 4)
            r += 2;
        R(0xcf010c00) = r & 0xff;
    } else {
        R(0xcf010c00) = (R(0xcf010c00) | 0x10) & 0xff;
        v = R(0xcf0116dc) & ~7;
        r = v;
        if ((FUN_a00a78b4(0, 3) & 0xf) == 4) {
            c = FUN_a00858f0(0);
            if (c == 0x81) {
                if ((unsigned char)FUN_a00adf64(0, DAT_a807a94d) != 1)
                    r = v | 1;
            } else if (c == 0x71) {
                if ((unsigned char)FUN_a00adf64(1, DAT_a807a94d) != 1)
                    r = v | 1;
            } else if (c == 0x51) {
                if (FUN_a00a29d8(0) == 1)
                    r = v | 1;
                else
                    r = v | 2;
            } else if (c == 0x61) {
                if (FUN_a00a29d8(1) == 1)
                    r = v | 1;
                else
                    r = v | 2;
            } else
                r = v | 2;
        } else if ((FUN_a00a78b4(0, 3) & 0xf) == 2) {
            c = FUN_a00858f0(0);
            if (c == 0x81)
                ;
            else if (c != 0x71)
                r = v | 1;
        }
        if (FUN_a00a78b4(0, 0x6f) & 8) {
            if ((r & 7) == 2)
                r = (r & ~7) | 4;
            else
                r++;
        }
        R(0xcf0116dc) = r & 0xff;
    }
    FUN_a00a7940((unsigned char)port, 0, 8, 1);
    FUN_a00a7940((unsigned char)port, 0, 8, 0);
}
