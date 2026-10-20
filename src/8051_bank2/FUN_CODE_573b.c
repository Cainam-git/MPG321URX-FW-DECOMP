/* 8051_bank2 MODULE FUN_CODE_573b: FUN_CODE_573b @ 0x573b..0x5c20 (1253 B) and FUN_CODE_7a60 @ 0x7a60..0x7ddb with
 * its Keil common-entry block 0x7a46..0x7a5f (917 B together). One Keil C51 module, OPTIMIZE(8,SPEED) LARGE.
 * Both BYTE-EXACT (diff8051.judge, exact None): 573b 1253/1253; 7a60 917/917 judged over block + function.
 * functions.json has FUN_CODE_7a46 = 0x7a46..0x7ddb; the C function starts at 0x7a60 and the block in front of it
 * is the argument set-up of 573b's calls. The two functions are one module because Keil builds the block from
 * 573b's call sites.
 * FUN_CODE_573b: BYTE-EXACT under OPTIMIZE(8,SPEED) LARGE (first C,
 * MATCH exact None 1253/1253).
 * NOT IN symbols/8051_bank2.functions.json: 0x573b..0x5c20 is a gap between FUN_CODE_520d (merged to end 0x573b)
 * and FUN_CODE_5c20; Ghidra only has SUB_CODE_573b. The entry {FUN_CODE_573b, 0x573b, 0x5c20} must be
 * added before diff8051 / accept8051 can see it. Judged with plain diff8051.judge with ROOT pointed
 * at a scratch root (symlinks to the real parts / decomp / symbols, functions.json = a copy plus this one
 * entry). ?FUN_CODE_573b?XD = 0x08F6 (recorded in that root's libs.json copy only).
 * Only caller: FUN_CODE_5c20 at 0x5d77 (FOTG210 device group 0 / sub bit 0 = control-endpoint SETUP).
 * FOTG210 control (EP0) SETUP handler: write [0x1C0] = 0x10, read the 8-byte SETUP packet as two 32-bit reads of
 * [0x1D0] into req[2] (XDATA 0x08FC), write [0x1C0] = 0; p = generic pointer to req. Field offsets inside req as
 * the 32-bit reads leave them (code facts): +0 wValue (uint), +2 bRequest, +3 bmRequestType, +4 wLength (uint).
 * Only standard requests ((bmRequestType & 0x60) == 0):
 *   5 SET_ADDRESS: [0x104] = ([0x104] & ~0x7f) | (wValue & 0x7f);
 *   6 GET_DESCRIPTOR: printf "DescType = %02BX" (type = wValue >> 8), idx = low byte; per type a reply from a CODE
 *     table with FUN_CODE_e306(table, n) then FUN_CODE_7a60(len, p->bmRequestType): 1 -> 0x7F86 / 18,
 *     2 -> 0x80E6 / 32, 0x0F -> 0x7F98 / 80,
 *     3 -> printf "DescIdx = %02BX", idx 0 / 1 / 2 / 3 / 4 / 7 / 8 -> 0x7FE8 / 4, 0x7FEC / 16, 0x7FFC / 60,
 *     0x8038 / 48, 0x8068 / 40, 0x8090 / 24, 0x80A8 / 62, other idx = idx 8; 6 -> 0x8106 / 10; 7 -> 0x8110 / 32;
 *   0 GET_STATUS: 0x8130 / 2;   9 SET_CONFIGURATION: nothing.  These four set st = 1.
 *   len = min(wLength, n) (local 0x08FA) is the first argument of FUN_CODE_7a60; e306 gets the constant n.
 *   All seven 7a60 calls have the same arguments (len, p->bmRequestType): Keil emits that set-up once, as the
 *   common-entry block 0x7a46..0x7a5f in front of 7a60 (len into R6:R7, ?C?CLDOPTR of p + 3 into R5), and every
 *   call site is a plain LCALL of the block.
 * Then st 1: [0x120] |= 1 (FUN_CODE_dfbe write) + "fotg210: cx_finish!", st 2: [0x120] |= 4 + "fotg210: cx_stall!"
 * (st is never 2 here), st 0: "fotg210: cx_idle?".
 * Shapes found by the bytes: type / idx are two char locals (0x08F8 / 0x08F9) from one int load of wValue (an
 * 'unsigned int desc' local: 38.7 %, other length); the type tests are int compares
 * ('(unsigned int)type == 1' -> XRL A,#k / JNZ, reloading 0x08F8 each test; plain 'type == 1' and 'type == 1U' give
 * CJNE, 43 %; '(type ^ k) == 0' also matches); the idx tests are plain char compares (CJNE). Switch case order as
 * written (dispatch 0, 6, 9, 5 and 0, 2, 1 comes from Keil). Tail 'LCALL 65ab; RET' = the three st arms'
 * cross-jumped printf, default jumps to the RET: no aid needed.
 *
 * FUN_CODE_7a60(size, dir): piecewise DMA loop on the FOTG210 registers (its strings: "fotg210: dma ..."; register
 * numbers as passed to FUN_CODE_9b91 read / FUN_CODE_b317 write). LARGE parameters size (0x090B) and dir (0x090D); locals fail (0x090E),
 * v (0x090F), t (0x0913), rem (0x0917), off (0x0919), declared in that XDATA order. rem = size, off = 0; per piece
 * (size cut to XDATA 0x09BD, an int; rem -= size):
 *   [0x1C8] bit 0 set: printf "fotg210: dma busy\r\n" (0x7F41), then wait until it clears;
 *   [0x1CC] = XDATA 0x08C9 (unsigned long) * 0x20 + off;
 *   dir bit 7 set: wait until ([0x120] & 0x20) == 0x20, e44b(1), [0x1C0] = 0x10, v = (size << 8) | 2;
 *   dir bit 7 clear: [0x1C0] = 0x10, then up to 1000 rounds of e44b(1), v = ([0x120] & 0x7F000000) >> 24 while
 *     v < size; when v > size, size = v; v = (size << 8) & ~2;
 *   [0x1C8] = v, then [0x1C8] |= 1 (read-modify-write);
 *   fail = 0xFF; up to 1000 reads of v = [0x14C]: bit 7 -> fail = 0, [0x14C] = 0x80; bit 8 -> [0x14C] = 0x100, printf
 *     "fotg210: dma error\r\n" (0x7EA9); bits 0..2 -> [0x14C] = 7, printf "fotg210: dma reset by host\r\n" (0x7F55);
 *     each of the three ends the reads;
 *   fail != 0: [0x1C8] = 0x18, printf "fotg210: dma fail\r\n" (0x7F72); [0x1C0] = 0; size = rem; off += XDATA 0x09BD;
 *   repeat while rem != 0.
 * Source forms the bytes depend on: 'v = x & 0x7f000000; v >>= 24;' as two statements (the firmware stores v between
 * the mask and the ?C?ULSHR); 'if (v > size)' (SETB C / JC; 'v < size' gives CLR C / JNC); the shared tail from the
 * v store at 0x7C3D is Keil's cross-jump of the two dir arms. The parameter is named size, not len: the judge
 * resolves the block's 'len' (a 573b local) by name. No aids.
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
