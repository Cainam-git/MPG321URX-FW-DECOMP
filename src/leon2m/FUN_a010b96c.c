/* FUN_a010b96c (leon2m 0xa010b96c-0xa010baac, 320 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when a status bit of the selected register pair is set: for c = 0, 1, 2 bit 1, 2 or 3 of the word
 * register 0xd0030004 or 0xd0038004; for c = 3..255 (c - 3 = 1: bit 2, otherwise bit 1) of 0xd0032000 or
 * 0xd003a000; otherwise 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * It lies between FUN_a010b948 and FUN_a010baac. Source form: a flag for c > 2 (then c -= 3), a switch for the low
 * group, r != 0 as result.
 */
#define RA (*(volatile unsigned int *)0xd0030004)
#define RB (*(volatile unsigned int *)0xd0038004)
#define RC (*(volatile unsigned int *)0xd0032000)
#define RD (*(volatile unsigned int *)0xd003a000)

int FUN_a010b96c(unsigned char c)
{
    unsigned char hi = 0, r = 0;

    if (c > 2) {
        c -= 3;
        hi = 1;
    }
    if (hi) {
        if (c == 1) {
            if ((RC & 4) || (RD & 4))
                r = 1;
        } else {
            if ((RC & 2) || (RD & 2))
                r = 1;
        }
    } else {
        switch (c) {
        case 0:
            if ((RA & 2) || (RB & 2))
                r = 1;
            break;
        case 1:
            if ((RA & 4) || (RB & 4))
                r = 1;
            break;
        case 2:
            if ((RA & 8) || (RB & 8))
                r = 1;
            break;
        }
    }
    return r != 0;
}
