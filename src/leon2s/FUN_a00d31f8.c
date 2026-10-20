/* FUN_a00d31f8 (leon2s, 0xa00d31f8-0xa00d3364, 91 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void(void). Runs only if bit 3 of DAT_a8078c30. Copies 0x101 u16 into ARR_a8077a08 from ARR_a80783de (bit 2 clear) or from
 DAT_9f1b0800 (bit 2 set). FUN_a00d2378(0x100), FUN_a00d3114(0,0,0,0,0). v = func_0xa0f71528(0xd0013f6c); func_0xa0f714b8(&v,0x1f,0x1e,0)
 and (..,3), each followed by func_0xa0f71534(0xd0013f6c, v). v = 71528(0xd0013fdc); 714b8 field writes (0x19,0x18,1), (0x1f,0x1e,0),
 (0x1f,0x1e,3), each followed by 71534(0xd0013fdc, v). FUN_a00d2ca8(); clear bit 3 of DAT_a8078c30.
 Fixes vs draft: 0x9f1b0800 is a SYMBOL address (fw sethi + or %lo 0, like the other bases), declared extern DAT_9f1b0800[]; the draft
 copied with stride 2 elements (i*2 on a u16 array) and had a bogus 'uVar2 = 0xd0013fdc' value; the second v is the 71528 return. Aids: none.
 */
extern unsigned char DAT_a8078c30;
extern void FUN_a00d2378(unsigned int);
extern void FUN_a00d2ca8(void);
extern void FUN_a00d3114(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void func_0xa0f714b8(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned int func_0xa0f71528(unsigned int);
extern void func_0xa0f71534(unsigned int, unsigned int);
extern unsigned short ARR_a8077a08[];
extern unsigned short ARR_a80783de[];
extern unsigned short DAT_9f1b0800[];

void FUN_a00d31f8(void)
{
    unsigned int v;
    unsigned int i;

    if ((DAT_a8078c30 & 8) != 0) {
        if ((DAT_a8078c30 & 4) == 0) {
            for (i = 0; i <= 0x100; i++)
                ARR_a8077a08[i] = ARR_a80783de[i];
        } else {
            for (i = 0; i <= 0x100; i++)
                ARR_a8077a08[i] = DAT_9f1b0800[i];
        }
        FUN_a00d2378(0x100);
        FUN_a00d3114(0, 0, 0, 0, 0);
        v = func_0xa0f71528(0xd0013f6c);
        func_0xa0f714b8(&v, 0x1f, 0x1e, 0);
        func_0xa0f71534(0xd0013f6c, v);
        func_0xa0f714b8(&v, 0x1f, 0x1e, 3);
        func_0xa0f71534(0xd0013f6c, v);
        v = func_0xa0f71528(0xd0013fdc);
        func_0xa0f714b8(&v, 0x19, 0x18, 1);
        func_0xa0f71534(0xd0013fdc, v);
        func_0xa0f714b8(&v, 0x1f, 0x1e, 0);
        func_0xa0f71534(0xd0013fdc, v);
        func_0xa0f714b8(&v, 0x1f, 0x1e, 3);
        func_0xa0f71534(0xd0013fdc, v);
        FUN_a00d2ca8();
        DAT_a8078c30 = DAT_a8078c30 & 0xf7;
    }
}
