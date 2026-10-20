/* 8051_bank2 module FUN_CODE_573b: FUN_CODE_573b @ 0x573b..0x5c20 and FUN_CODE_7a60 @ 0x7a60..0x7ddb, with the Keil
 * common-entry block FUN_CODE_7a46 @ 0x7a46..0x7a60 in front of FUN_CODE_7a60. One Keil C51 module, OPTIMIZE(8,SPEED)
 * LARGE. The block is the shared argument set-up of the seven FUN_CODE_7a60 calls in FUN_CODE_573b (len into R6:R7,
 * byte p + 3 into R5 through ?C?CLDOPTR); Keil emits it once because all seven calls pass the same arguments.
 *
 * FUN_CODE_573b (only caller: FUN_CODE_5c20 at 0x5d77): writes register [0x1C0] = 0x10, reads two 32-bit values from
 * [0x1D0] into req[2] at XDATA 0x08FC, writes [0x1C0] = 0; p is a generic pointer to req. Byte/word offsets in req
 * used below: +0 word w0, +2 byte b2, +3 byte b3, +4 word w4. Only when (b3 & 0x60) == 0, switch on b2:
 *   5: [0x104] = ([0x104] & ~0x7f) | (w0 & 0x7f);
 *   6: prints "DescType = %02BX" with type = w0 >> 8 (idx = low byte of w0); per type a CODE table and length n go
 *      to FUN_CODE_e306(table, n), then FUN_CODE_7a60(len, b3): type 1 -> 0x7F86 / 18, 2 -> 0x80E6 / 32,
 *      0x0F -> 0x7F98 / 80, 3 -> prints "DescIdx = %02BX" and idx 0 / 1 / 2 / 3 / 4 / 7 / 8 select 0x7FE8 / 4,
 *      0x7FEC / 16, 0x7FFC / 60, 0x8038 / 48, 0x8068 / 40, 0x8090 / 24, 0x80A8 / 62 (other idx as idx 8),
 *      6 -> 0x8106 / 10, 7 -> 0x8110 / 32;
 *   0: 0x8130 / 2;  9: nothing.  These four values of b2 set st = 1.
 *   len = min(w4, n) (XDATA 0x08FA) is the first argument of FUN_CODE_7a60.
 * Then st 1: [0x120] |= 1 (FUN_CODE_dfbe) and "fotg210: cx_finish!", st 2: [0x120] |= 4 and "fotg210: cx_stall!"
 * (st is never 2 here), st 0: "fotg210: cx_idle?".
 * Source forms the bytes depend on: type and idx are two char locals (0x08F8 / 0x08F9) filled from one int load of
 * w0; the type tests are int compares ('(unsigned int)type == 1' gives XRL A,#k / JNZ and reloads 0x08F8 each
 * test); the idx tests are char compares (CJNE); the case order is as written.
 *
 * FUN_CODE_7a60(size, dir): loop over pieces with the registers that the "fotg210: dma ..." strings name (register
 * numbers as passed to FUN_CODE_9b91 read / FUN_CODE_b317 write). LARGE parameters size (0x090B) and dir (0x090D);
 * locals fail (0x090E), v (0x090F), t (0x0913), rem (0x0917), off (0x0919), declared in that XDATA order.
 * rem = size, off = 0; per piece (size cut to XDATA 0x09BD, an int; rem -= size):
 *   [0x1C8] bit 0 set: prints "fotg210: dma busy\r\n" (0x7F41), then waits until it clears;
 *   [0x1CC] = XDATA 0x08C9 (unsigned long) * 0x20 + off;
 *   dir bit 7 set: waits until ([0x120] & 0x20) == 0x20, e44b(1), [0x1C0] = 0x10, v = (size << 8) | 2;
 *   dir bit 7 clear: [0x1C0] = 0x10, then up to 1000 rounds of e44b(1), v = ([0x120] & 0x7F000000) >> 24 while
 *     v < size; when v > size, size = v; v = (size << 8) & ~2;
 *   [0x1C8] = v, then [0x1C8] |= 1 (read-modify-write);
 *   fail = 0xFF; up to 1000 reads of v = [0x14C]: bit 7 -> fail = 0, [0x14C] = 0x80; bit 8 -> [0x14C] = 0x100 and
 *     "fotg210: dma error\r\n" (0x7EA9); bits 0..2 -> [0x14C] = 7 and "fotg210: dma reset by host\r\n" (0x7F55);
 *     each of the three ends the reads;
 *   fail != 0: [0x1C8] = 0x18 and "fotg210: dma fail\r\n" (0x7F72); [0x1C0] = 0; size = rem; off += XDATA 0x09BD;
 *   repeat while rem != 0.
 * Source forms the bytes depend on: 'v = x & 0x7f000000; v >>= 24;' as two statements (the firmware stores v
 * between the mask and ?C?ULSHR); 'if (v > size)' (SETB C / JC); the shared tail from the v store at 0x7C3D is
 * Keil's cross-jump of the two dir arms. The parameter is named size because the common-entry block's operand
 * 'len' belongs to FUN_CODE_573b.
 */
struct setup { unsigned int wValue; unsigned char bRequest; unsigned char bmRequestType; unsigned int wLength; unsigned int wIndex; };
unsigned long FUN_CODE_9b91(unsigned int reg);
void FUN_CODE_b317(unsigned int reg, unsigned long v);
void FUN_CODE_dfbe(unsigned int reg, unsigned long v);
void FUN_CODE_e306(unsigned char *buf, unsigned char n);
void FUN_CODE_7a60(unsigned int size, unsigned char dir);
extern void FUN_CODE_65ab(void *fmt, ...) large;

void FUN_CODE_573b(void)
{
    unsigned char addr;
    unsigned char st;
    unsigned char type;
    unsigned char idx;
    unsigned int len;
    unsigned long req[2];
    unsigned long v;
    struct setup *p;
    p = (struct setup *)req;
    FUN_CODE_b317(0x01c0, 0x10);
    req[0] = FUN_CODE_9b91(0x01d0);
    req[1] = FUN_CODE_9b91(0x01d0);
    FUN_CODE_b317(0x01c0, 0);
    st = 0;
    if ((p->bmRequestType & 0x60) == 0) {
        switch (p->bRequest) {
        case 5:
            addr = p->wValue & 0x7f;
            v = FUN_CODE_9b91(0x0104);
            v &= ~0x7f;
            v |= addr;
            FUN_CODE_b317(0x0104, v);
            st = 1;
            break;
        case 6:
            type = p->wValue >> 8;
            idx = p->wValue;
            FUN_CODE_65ab((void code *)0x7edd, type);
            len = p->wLength;
            if ((unsigned int)type == 1) {
                if (p->wLength > 0x12) len = 0x12;
                FUN_CODE_e306((void code *)0x7f86, 0x12);
                FUN_CODE_7a60(len, p->bmRequestType);
            } else if ((unsigned int)type == 2) {
                if (p->wLength > 0x20) len = 0x20;
                FUN_CODE_e306((void code *)0x80e6, 0x20);
                FUN_CODE_7a60(len, p->bmRequestType);
            } else if ((unsigned int)type == 0x0f) {
                if (p->wLength > 0x50) len = 0x50;
                FUN_CODE_e306((void code *)0x7f98, 0x50);
                FUN_CODE_7a60(len, p->bmRequestType);
            } else if ((unsigned int)type == 3) {
                FUN_CODE_65ab((void code *)0x7ef0, idx);
                if (idx == 0) {
                    if (p->wLength > 4) len = 4;
                    FUN_CODE_e306((void code *)0x7fe8, 4);
                } else if (idx == 1) {
                    if (p->wLength > 0x10) len = 0x10;
                    FUN_CODE_e306((void code *)0x7fec, 0x10);
                } else if (idx == 2) {
                    if (p->wLength > 0x3c) len = 0x3c;
                    FUN_CODE_e306((void code *)0x7ffc, 0x3c);
                } else if (idx == 3) {
                    if (p->wLength > 0x30) len = 0x30;
                    FUN_CODE_e306((void code *)0x8038, 0x30);
                } else if (idx == 4) {
                    if (p->wLength > 0x28) len = 0x28;
                    FUN_CODE_e306((void code *)0x8068, 0x28);
                } else if (idx == 7) {
                    if (p->wLength > 0x18) len = 0x18;
                    FUN_CODE_e306((void code *)0x8090, 0x18);
                } else if (idx == 8) {
                    if (p->wLength > 0x3e) len = 0x3e;
                    FUN_CODE_e306((void code *)0x80a8, 0x3e);
                } else {
                    if (p->wLength > 0x3e) len = 0x3e;
                    FUN_CODE_e306((void code *)0x80a8, 0x3e);
                }
                FUN_CODE_7a60(len, p->bmRequestType);
            } else if ((unsigned int)type == 6) {
                if (p->wLength > 0x0a) len = 0x0a;
                FUN_CODE_e306((void code *)0x8106, 0x0a);
                FUN_CODE_7a60(len, p->bmRequestType);
            } else if ((unsigned int)type == 7) {
                if (p->wLength > 0x20) len = 0x20;
                FUN_CODE_e306((void code *)0x8110, 0x20);
                FUN_CODE_7a60(len, p->bmRequestType);
            }
            st = 1;
            break;
        case 0:
            len = p->wLength;
            if (p->wLength > 2) len = 2;
            FUN_CODE_e306((void code *)0x8130, 2);
            FUN_CODE_7a60(len, p->bmRequestType);
            st = 1;
            break;
        case 9:
            st = 1;
            break;
        }
    }
    switch (st) {
    case 1:
        v = FUN_CODE_9b91(0x0120);
        v |= 1;
        FUN_CODE_dfbe(0x0120, v);
        FUN_CODE_65ab((void code *)0x7f02);
        break;
    case 2:
        v = FUN_CODE_9b91(0x0120);
        v |= 4;
        FUN_CODE_dfbe(0x0120, v);
        FUN_CODE_65ab((void code *)0x7f18);
        break;
    case 0:
        FUN_CODE_65ab((void code *)0x7f2d);
        break;
    }
}

extern unsigned int xdata DAT_EXTMEM_09bd;
extern unsigned long xdata DAT_EXTMEM_08c9;
void FUN_CODE_e44b(unsigned char n);

void FUN_CODE_7a60(unsigned int size, unsigned char dir)
{
    unsigned char fail;
    unsigned long v;
    unsigned long t;
    unsigned int rem;
    unsigned int off;
    rem = size;
    off = 0;
    do {
        if (size > DAT_EXTMEM_09bd) size = DAT_EXTMEM_09bd;
        rem -= size;
        if (FUN_CODE_9b91(0x01c8) & 1) {
            FUN_CODE_65ab((void code *)0x7f41);
            while (FUN_CODE_9b91(0x01c8) & 1) ;
        }
        FUN_CODE_b317(0x01cc, DAT_EXTMEM_08c9 * 0x20 + off);
        if (dir & 0x80) {
            while ((FUN_CODE_9b91(0x0120) & 0x20) != 0x20) ;
            FUN_CODE_e44b(1);
            FUN_CODE_b317(0x01c0, 0x10);
            v = size << 8;
            v |= 2;
        } else {
            FUN_CODE_b317(0x01c0, 0x10);
            t = 1000;
            do {
                FUN_CODE_e44b(1);
                v = FUN_CODE_9b91(0x0120) & 0x7f000000;
                v >>= 24;
            } while (--t != 0 && v < size);
            if (v > size) size = v;
            v = size << 8;
            v &= ~2;
        }
        FUN_CODE_b317(0x01c8, v);
        v = FUN_CODE_9b91(0x01c8);
        v |= 1;
        FUN_CODE_b317(0x01c8, v);
        fail = 0xff;
        for (t = 0; t < 1000; t++) {
            v = FUN_CODE_9b91(0x014c);
            if (v & 0x80) {
                fail = 0;
                FUN_CODE_b317(0x014c, 0x80);
                break;
            }
            if (v & 0x100) {
                FUN_CODE_b317(0x014c, 0x100);
                FUN_CODE_65ab((void code *)0x7ea9);
                break;
            }
            if (v & 7) {
                FUN_CODE_b317(0x014c, 7);
                FUN_CODE_65ab((void code *)0x7f55);
                break;
            }
        }
        if (fail) {
            FUN_CODE_b317(0x01c8, 0x18);
            FUN_CODE_65ab((void code *)0x7f72);
        }
        FUN_CODE_b317(0x01c0, 0);
        size = rem;
        off += DAT_EXTMEM_09bd;
    } while (rem);
}
