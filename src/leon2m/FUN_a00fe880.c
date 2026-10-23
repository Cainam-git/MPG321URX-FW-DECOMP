/* leon2m FUN_a00fe880 @ 0xa00fe880-0xa010031c (1703 words), flags -mcpu=v8 -O3 -g. Leaf function.
 * Writes one 2-bit field of a hardware register in 0xcf0114cc-0xcf011554 or 0xcf0116ac-0xcf0116b0.
 * a (switch, jump table at 0x9d510) selects a group: 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15 and 17 have code,
 * 0, 1, 7, 16 and values above 17 do nothing. b (a single bit 0x01 ... 0x80, tested as an if/else chain) selects the
 * field: 0x01/0x10 = bits 6-7, 0x02/0x20 = bits 4-5, 0x04/0x40 = bits 2-3, 0x08/0x80 = bits 0-1, b 0x01-0x08 in one
 * register and 0x10-0x80 in the next one (groups 8-15 and 17 use two registers; group 2 maps b 0x04 to bits 6-7 and
 * 0x08 to bits 4-5 of 0xcf011540). Each group handles only some b values. c is compared with one or more
 * group-specific values (an if/else chain): a match writes 1, 2 or 3 into the field, otherwise
 * the field is cleared. Group 4 (b == 0x80) writes 1 (c == 2) or 3 (c == 3) into bits 0-1 of 0xcf0114d0 and then
 * clears bits 0-1 in every case. Called from FUN_a00fc200, FUN_a0107a20, FUN_a0111088, FUN_a011d748, FUN_a0122e80,
 * FUN_a014dc28, FUN_a014f620, FUN_a014f6f4 and FUN_a0150768.
 * Source form: case 13 is the last case of the switch (the case order decides the register names); c is an
 * unsigned int (compared without masking).
 */
#define REG_cf0114cc (*(volatile unsigned int *)0xcf0114cc)
#define REG_cf0114d0 (*(volatile unsigned int *)0xcf0114d0)
#define REG_cf0114d4 (*(volatile unsigned int *)0xcf0114d4)
#define REG_cf0114d8 (*(volatile unsigned int *)0xcf0114d8)
#define REG_cf0114dc (*(volatile unsigned int *)0xcf0114dc)
#define REG_cf0114e0 (*(volatile unsigned int *)0xcf0114e0)
#define REG_cf0114e4 (*(volatile unsigned int *)0xcf0114e4)
#define REG_cf0114e8 (*(volatile unsigned int *)0xcf0114e8)
#define REG_cf011518 (*(volatile unsigned int *)0xcf011518)
#define REG_cf01151c (*(volatile unsigned int *)0xcf01151c)
#define REG_cf011520 (*(volatile unsigned int *)0xcf011520)
#define REG_cf011524 (*(volatile unsigned int *)0xcf011524)
#define REG_cf011528 (*(volatile unsigned int *)0xcf011528)
#define REG_cf01152c (*(volatile unsigned int *)0xcf01152c)
#define REG_cf011530 (*(volatile unsigned int *)0xcf011530)
#define REG_cf011538 (*(volatile unsigned int *)0xcf011538)
#define REG_cf01153c (*(volatile unsigned int *)0xcf01153c)
#define REG_cf011540 (*(volatile unsigned int *)0xcf011540)
#define REG_cf01154c (*(volatile unsigned int *)0xcf01154c)
#define REG_cf011550 (*(volatile unsigned int *)0xcf011550)
#define REG_cf011554 (*(volatile unsigned int *)0xcf011554)
#define REG_cf0116ac (*(volatile unsigned int *)0xcf0116ac)
#define REG_cf0116b0 (*(volatile unsigned int *)0xcf0116b0)

void FUN_a00fe880(unsigned char a, unsigned char b, unsigned int c)
{
    switch (a) {
    case 2:
        if (b == 4) {
            if (c == 16)
                REG_cf011540 = (REG_cf011540 & ~0xc0) | 0x40;
            else
                REG_cf011540 &= ~0xc0;
        }
        else if (b == 8) {
            if (c == 16)
                REG_cf011540 = (REG_cf011540 & ~0x30) | 0x10;
            else
                REG_cf011540 &= ~0x30;
        }
        break;
    case 3:
        if (b == 1) {
            if (c == 1)
                REG_cf0114cc = (REG_cf0114cc & ~0xc0) | 0x40;
            else
                REG_cf0114cc &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 1)
                REG_cf0114cc = (REG_cf0114cc & ~0x30) | 0x10;
            else
                REG_cf0114cc &= ~0x30;
        }
        else if (b == 4) {
            if (c == 1)
                REG_cf0114cc = (REG_cf0114cc & ~0xc) | 4;
            else
                REG_cf0114cc &= ~0xc;
        }
        else if (b == 8) {
            if (c == 1)
                REG_cf0114cc = (REG_cf0114cc & ~3) | 1;
            else
                REG_cf0114cc &= ~3;
        }
        break;
    case 4:
        if (b == 0x80) {
            if (c == 2)
                REG_cf0114d0 = (REG_cf0114d0 & ~3) | 1;
            else if (c == 3)
                REG_cf0114d0 |= 3;
            REG_cf0114d0 &= ~3;
        }
        break;
    case 5:
        if (b == 2) {
            if (c == 4)
                REG_cf0114d4 = (REG_cf0114d4 & ~0x30) | 0x10;
            else
                REG_cf0114d4 &= ~0x30;
        }
        else if (b == 4) {
            if (c == 5)
                REG_cf0114d4 = (REG_cf0114d4 & ~0xc) | 4;
            else
                REG_cf0114d4 &= ~0xc;
        }
        else if (b == 8) {
            if (c == 5)
                REG_cf0114d4 = (REG_cf0114d4 & ~3) | 1;
            else
                REG_cf0114d4 &= ~3;
        }
        break;
    case 6:
        if (b == 1) {
            if (c == 9)
                REG_cf0114d8 = (REG_cf0114d8 & ~0xc0) | 0x40;
            else
                REG_cf0114d8 &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 9)
                REG_cf0114d8 = (REG_cf0114d8 & ~0x30) | 0x10;
            else
                REG_cf0114d8 &= ~0x30;
        }
        break;
    case 8:
        if (b == 1) {
            if (c == 6)
                REG_cf0114dc = (REG_cf0114dc & ~0xc0) | 0x40;
            else
                REG_cf0114dc &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 6)
                REG_cf0114dc = (REG_cf0114dc & ~0x30) | 0x10;
            else
                REG_cf0114dc &= ~0x30;
        }
        else if (b == 4) {
            if (c == 6)
                REG_cf0114dc = (REG_cf0114dc & ~0xc) | 4;
            else
                REG_cf0114dc &= ~0xc;
        }
        else if (b == 8) {
            if (c == 6)
                REG_cf0114dc = (REG_cf0114dc & ~3) | 1;
            else
                REG_cf0114dc &= ~3;
        }
        else if (b == 0x10) {
            if (c == 6)
                REG_cf0114e0 = (REG_cf0114e0 & ~0xc0) | 0x40;
            else
                REG_cf0114e0 &= ~0xc0;
        }
        else if (b == 0x20) {
            if (c == 6)
                REG_cf0114e0 = (REG_cf0114e0 & ~0x30) | 0x10;
            else
                REG_cf0114e0 &= ~0x30;
        }
        else if (b == 0x40) {
            if (c == 6)
                REG_cf0114e0 = (REG_cf0114e0 & ~0xc) | 4;
            else
                REG_cf0114e0 &= ~0xc;
        }
        else if (b == 0x80) {
            if (c == 6)
                REG_cf0114e0 = (REG_cf0114e0 & ~3) | 1;
            else
                REG_cf0114e0 &= ~3;
        }
        break;
    case 9:
        if (b == 1) {
            if (c == 10)
                REG_cf0114e4 = (REG_cf0114e4 & ~0xc0) | 0x40;
            else if (c == 7)
                REG_cf0114e4 = (REG_cf0114e4 & ~0xc0) | 0x80;
            else if (c == 8)
                REG_cf0114e4 |= 0xc0;
            else
                REG_cf0114e4 &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 10)
                REG_cf0114e4 = (REG_cf0114e4 & ~0x30) | 0x10;
            else if (c == 7)
                REG_cf0114e4 = (REG_cf0114e4 & ~0x30) | 0x20;
            else if (c == 8)
                REG_cf0114e4 |= 0x30;
            else
                REG_cf0114e4 &= ~0x30;
        }
        else if (b == 4) {
            if (c == 10)
                REG_cf0114e4 = (REG_cf0114e4 & ~0xc) | 4;
            else if (c == 8)
                REG_cf0114e4 |= 0xc;
            else
                REG_cf0114e4 &= ~0xc;
        }
        else if (b == 8) {
            if (c == 10)
                REG_cf0114e4 = (REG_cf0114e4 & ~3) | 1;
            else if (c == 8)
                REG_cf0114e4 |= 3;
            else
                REG_cf0114e4 &= ~3;
        }
        else if (b == 0x10) {
            if (c == 10)
                REG_cf0114e8 = (REG_cf0114e8 & ~0xc0) | 0x40;
            else if (c == 8)
                REG_cf0114e8 |= 0xc0;
            else
                REG_cf0114e8 &= ~0xc0;
        }
        else if (b == 0x20) {
            if (c == 10)
                REG_cf0114e8 = (REG_cf0114e8 & ~0x30) | 0x10;
            else if (c == 8)
                REG_cf0114e8 |= 0x30;
            else
                REG_cf0114e8 &= ~0x30;
        }
        else if (b == 0x40) {
            if (c == 10)
                REG_cf0114e8 = (REG_cf0114e8 & ~0xc) | 4;
            else if (c == 8)
                REG_cf0114e8 |= 0xc;
            else
                REG_cf0114e8 &= ~0xc;
        }
        else if (b == 0x80) {
            if (c == 10)
                REG_cf0114e8 = (REG_cf0114e8 & ~3) | 1;
            else if (c == 8)
                REG_cf0114e8 |= 3;
            else
                REG_cf0114e8 &= ~3;
        }
        break;
    case 10:
        if (b == 1) {
            if (c == 5)
                REG_cf011550 = (REG_cf011550 & ~0xc0) | 0x40;
            else if (c == 8)
                REG_cf011550 |= 0xc0;
            else
                REG_cf011550 &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 5)
                REG_cf011550 = (REG_cf011550 & ~0x30) | 0x10;
            else if (c == 8)
                REG_cf011550 |= 0x30;
            else
                REG_cf011550 &= ~0x30;
        }
        else if (b == 4) {
            if (c == 8)
                REG_cf011550 |= 0xc;
            else
                REG_cf011550 &= ~0xc;
        }
        else if (b == 8) {
            if (c == 11)
                REG_cf011550 = (REG_cf011550 & ~3) | 1;
            else if (c == 8)
                REG_cf011550 |= 3;
            else
                REG_cf011550 &= ~3;
        }
        else if (b == 0x10) {
            if (c == 11)
                REG_cf011554 = (REG_cf011554 & ~0xc0) | 0x40;
            else if (c == 8)
                REG_cf011554 |= 0xc0;
            else
                REG_cf011554 &= ~0xc0;
        }
        else if (b == 0x20) {
            if (c == 11)
                REG_cf011554 = (REG_cf011554 & ~0x30) | 0x10;
            else if (c == 8)
                REG_cf011554 |= 0x30;
            else
                REG_cf011554 &= ~0x30;
        }
        else if (b == 0x40) {
            if (c == 11)
                REG_cf011554 = (REG_cf011554 & ~0xc) | 4;
            else if (c == 8)
                REG_cf011554 |= 0xc;
            else
                REG_cf011554 &= ~0xc;
        }
        else if (b == 0x80) {
            if (c == 11)
                REG_cf011554 = (REG_cf011554 & ~3) | 1;
            else if (c == 8)
                REG_cf011554 |= 3;
            else
                REG_cf011554 &= ~3;
        }
        break;
    case 11:
        if (b == 1) {
            if (c == 10)
                REG_cf01154c = (REG_cf01154c & ~0xc0) | 0x40;
            else if (c == 5)
                REG_cf01154c = (REG_cf01154c & ~0xc0) | 0x80;
            else if (c == 6)
                REG_cf01154c |= 0xc0;
            else
                REG_cf01154c &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 10)
                REG_cf01154c = (REG_cf01154c & ~0x30) | 0x10;
            else if (c == 5)
                REG_cf01154c = (REG_cf01154c & ~0x30) | 0x20;
            else if (c == 6)
                REG_cf01154c |= 0x30;
            else
                REG_cf01154c &= ~0x30;
        }
        else if (b == 4) {
            if (c == 10)
                REG_cf01154c = (REG_cf01154c & ~0xc) | 4;
            else if (c == 5)
                REG_cf01154c = (REG_cf01154c & ~0xc) | 0x8;
            else if (c == 6)
                REG_cf01154c |= 0xc;
            else
                REG_cf01154c &= ~0xc;
        }
        else if (b == 8) {
            if (c == 10)
                REG_cf01154c = (REG_cf01154c & ~3) | 1;
            else if (c == 5)
                REG_cf01154c = (REG_cf01154c & ~3) | 2;
            else if (c == 6)
                REG_cf01154c |= 3;
            else
                REG_cf01154c &= ~3;
        }
        else if (b == 0x10) {
            if (c == 12)
                REG_cf011518 = (REG_cf011518 & ~0xc0) | 0x40;
            else if (c == 13)
                REG_cf011518 = (REG_cf011518 & ~0xc0) | 0x80;
            else if (c == 6)
                REG_cf011518 |= 0xc0;
            else
                REG_cf011518 &= ~0xc0;
        }
        else if (b == 0x20) {
            if (c == 12)
                REG_cf011518 = (REG_cf011518 & ~0x30) | 0x10;
            else if (c == 13)
                REG_cf011518 = (REG_cf011518 & ~0x30) | 0x20;
            else if (c == 6)
                REG_cf011518 |= 0x30;
            else
                REG_cf011518 &= ~0x30;
        }
        else if (b == 0x40) {
            if (c == 12)
                REG_cf011518 = (REG_cf011518 & ~0xc) | 4;
            else if (c == 6)
                REG_cf011518 |= 0xc;
            else
                REG_cf011518 &= ~0xc;
        }
        else if (b == 0x80) {
            if (c == 12)
                REG_cf011518 = (REG_cf011518 & ~3) | 1;
            else if (c == 6)
                REG_cf011518 |= 3;
            else
                REG_cf011518 &= ~3;
        }
        break;
    case 12:
        if (b == 1) {
            if (c == 11)
                REG_cf01151c = (REG_cf01151c & ~0xc0) | 0x40;
            else if (c == 6)
                REG_cf01151c |= 0xc0;
            else
                REG_cf01151c &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 11)
                REG_cf01151c = (REG_cf01151c & ~0x30) | 0x10;
            else if (c == 6)
                REG_cf01151c |= 0x30;
            else
                REG_cf01151c &= ~0x30;
        }
        else if (b == 4) {
            if (c == 11)
                REG_cf01151c = (REG_cf01151c & ~0xc) | 4;
            else if (c == 6)
                REG_cf01151c |= 0xc;
            else
                REG_cf01151c &= ~0xc;
        }
        else if (b == 8) {
            if (c == 11)
                REG_cf01151c = (REG_cf01151c & ~3) | 1;
            else if (c == 6)
                REG_cf01151c |= 3;
            else
                REG_cf01151c &= ~3;
        }
        else if (b == 0x10) {
            if (c == 6)
                REG_cf011520 |= 0xc0;
            else
                REG_cf011520 &= ~0xc0;
        }
        else if (b == 0x20) {
            if (c == 6)
                REG_cf011520 |= 0x30;
            else
                REG_cf011520 &= ~0x30;
        }
        break;
    case 14:
        if (b == 1) {
            if (c == 14)
                REG_cf011524 = (REG_cf011524 & ~0xc0) | 0x40;
            else if (c == 6)
                REG_cf011524 |= 0xc0;
            else
                REG_cf011524 &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 14)
                REG_cf011524 = (REG_cf011524 & ~0x30) | 0x10;
            else if (c == 6)
                REG_cf011524 |= 0x30;
            else
                REG_cf011524 &= ~0x30;
        }
        else if (b == 4) {
            if (c == 14)
                REG_cf011524 = (REG_cf011524 & ~0xc) | 4;
            else if (c == 6)
                REG_cf011524 |= 0xc;
            else
                REG_cf011524 &= ~0xc;
        }
        else if (b == 8) {
            if (c == 14)
                REG_cf011524 = (REG_cf011524 & ~3) | 1;
            else if (c == 6)
                REG_cf011524 |= 3;
            else
                REG_cf011524 &= ~3;
        }
        else if (b == 0x10) {
            if (c == 6)
                REG_cf011528 |= 0xc0;
            else
                REG_cf011528 &= ~0xc0;
        }
        else if (b == 0x20) {
            if (c == 6)
                REG_cf011528 |= 0x30;
            else
                REG_cf011528 &= ~0x30;
        }
        else if (b == 0x40) {
            if (c == 6)
                REG_cf011528 |= 0xc;
            else
                REG_cf011528 &= ~0xc;
        }
        else if (b == 0x80) {
            if (c == 6)
                REG_cf011528 |= 3;
            else
                REG_cf011528 &= ~3;
        }
        break;
    case 15:
        if (b == 4) {
            if (c == 5)
                REG_cf01152c = (REG_cf01152c & ~0xc) | 4;
            else if (c == 15)
                REG_cf01152c = (REG_cf01152c & ~0xc) | 0x8;
            else
                REG_cf01152c &= ~0xc;
        }
        else if (b == 8) {
            if (c == 5)
                REG_cf01152c = (REG_cf01152c & ~3) | 1;
            else if (c == 15)
                REG_cf01152c = (REG_cf01152c & ~3) | 2;
            else
                REG_cf01152c &= ~3;
        }
        else if (b == 0x10) {
            if (c == 5)
                REG_cf011530 = (REG_cf011530 & ~0xc0) | 0x40;
            else
                REG_cf011530 &= ~0xc0;
        }
        else if (b == 0x20) {
            if (c == 5)
                REG_cf011530 = (REG_cf011530 & ~0x30) | 0x10;
            else
                REG_cf011530 &= ~0x30;
        }
        else if (b == 0x40) {
            if (c == 5)
                REG_cf011530 = (REG_cf011530 & ~0xc) | 4;
            else
                REG_cf011530 &= ~0xc;
        }
        else if (b == 0x80) {
            if (c == 5)
                REG_cf011530 = (REG_cf011530 & ~3) | 1;
            else
                REG_cf011530 &= ~3;
        }
        break;
    case 17:
        if (b == 1) {
            if (c == 11)
                REG_cf011538 |= 0xc0;
            else
                REG_cf011538 &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 11)
                REG_cf011538 |= 0x30;
            else
                REG_cf011538 &= ~0x30;
        }
        else if (b == 4) {
            if (c == 11)
                REG_cf011538 |= 0xc;
            else
                REG_cf011538 &= ~0xc;
        }
        else if (b == 8) {
            if (c == 11)
                REG_cf011538 |= 3;
            else
                REG_cf011538 &= ~3;
        }
        else if (b == 0x10) {
            if (c == 11)
                REG_cf01153c |= 0xc0;
            else
                REG_cf01153c &= ~0xc0;
        }
        break;
    case 13:
        if (b == 1) {
            if (c == 18)
                REG_cf0116ac = (REG_cf0116ac & ~0xc0) | 0x40;
            else
                REG_cf0116ac &= ~0xc0;
        }
        else if (b == 2) {
            if (c == 18)
                REG_cf0116ac = (REG_cf0116ac & ~0x30) | 0x10;
            else
                REG_cf0116ac &= ~0x30;
        }
        else if (b == 4) {
            if (c == 18)
                REG_cf0116ac = (REG_cf0116ac & ~0xc) | 4;
            else
                REG_cf0116ac &= ~0xc;
        }
        else if (b == 8) {
            if (c == 18)
                REG_cf0116ac = (REG_cf0116ac & ~3) | 1;
            else
                REG_cf0116ac &= ~3;
        }
        else if (b == 0x10) {
            if (c == 18)
                REG_cf0116b0 = (REG_cf0116b0 & ~0xc0) | 0x40;
            else
                REG_cf0116b0 &= ~0xc0;
        }
        else if (b == 0x20) {
            if (c == 18)
                REG_cf0116b0 = (REG_cf0116b0 & ~0x30) | 0x10;
            else
                REG_cf0116b0 &= ~0x30;
        }
        else if (b == 0x40) {
            if (c == 5)
                REG_cf0116b0 = (REG_cf0116b0 & ~0xc) | 4;
            else if (c == 15)
                REG_cf0116b0 = (REG_cf0116b0 & ~0xc) | 0x8;
            else if (c == 6)
                REG_cf0116b0 |= 0xc;
            else
                REG_cf0116b0 &= ~0xc;
        }
        else if (b == 0x80) {
            if (c == 5)
                REG_cf0116b0 = (REG_cf0116b0 & ~3) | 1;
            else if (c == 15)
                REG_cf0116b0 = (REG_cf0116b0 & ~3) | 2;
            else if (c == 6)
                REG_cf0116b0 |= 3;
            else
                REG_cf0116b0 &= ~3;
        }
        break;
    }
}
