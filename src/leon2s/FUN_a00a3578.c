/* FUN_a00a3578 (leon2s, 0xa00a3578-0xa00a3788, 132 words). Flags -mcpu=v8 -Os -g.
 Code facts: TxFFE mode set-up for port (u8 p1), mode = (u8)p2. mode 2: print 'TxFFE De-Emphasis', a80cc(port,1,0x7d,0x10,1),
 e0f0(port,3,T[idx].a), e200(port,T[idx].b) with T = 2-byte records at 0xa807872a, idx = DAT_a80791f0[port], tail e3c0(port,0,p3..p6).
 mode 1: 'TxFFE_Preshoot', e0f0(port,3,0xe), e200(port,0), tail e3c0(port,3,p3..p6). mode 3: 'TxFFE_NO', read-modify-writes of regs
 1/8 (|0xf0), 1/0xe (&0xf8 then &0x8f), 1/0x7c (&0xcf). Else: print 'TxFFE_Normal(Exit Mode)[%d]' WITH mode (fw keeps mode in %o1),
 a80cc(...,0), regs 4/0xe2 and 4/0xe3 = low/high byte of u16 ARR_a8078732[idx].
 Fixes vs draft: the exit-mode print takes the mode argument (this was the whole %o1 vs %i1 difference), the 0x72a/0x72b tables
 are one array of {u8 a, b} records (fw base+1 load). Aids: none.
 */
extern unsigned int DAT_a006ba08;
extern unsigned int DAT_a006ba28;
extern unsigned int DAT_a006ba48;
extern unsigned int DAT_a006ba60;
extern int FUN_a0073044();
extern unsigned int FUN_a00734c4();
extern void FUN_a008e0f0();
extern void FUN_a008e200();
extern void FUN_a008e3c0();
extern int FUN_a00a7fd8();
extern void FUN_a00a8054();
extern void FUN_a00a80cc();
struct pair { unsigned char a; unsigned char b; };
extern struct pair ARR_a807872a[];
extern unsigned short ARR_a8078732[];
extern unsigned char DAT_a80791f0[];

void FUN_a00a3578(unsigned char param_1, int param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5, unsigned int param_6)
{
    unsigned int uVar1;
    unsigned int uVar4;
    unsigned char mode = param_2;

    if (mode == 2) {
        FUN_a00734c4(&DAT_a006ba08);
        uVar1 = param_1;
        FUN_a00a80cc(uVar1, 1, 0x7d, 0x10, 1);
        FUN_a008e0f0(uVar1, 3, ARR_a807872a[DAT_a80791f0[uVar1]].a);
        FUN_a008e200(uVar1, ARR_a807872a[DAT_a80791f0[uVar1]].b);
        FUN_a008e3c0(uVar1, 0, param_3, param_4, param_5, param_6);
        return;
    }
    if (mode == 1) {
        FUN_a00734c4(&DAT_a006ba28);
        uVar1 = param_1;
        FUN_a00a80cc(uVar1, 1, 0x7d, 0x10, 1);
        FUN_a008e0f0(uVar1, 3, 0xe);
        FUN_a008e200(uVar1, 0);
        FUN_a008e3c0(uVar1, 3, param_3, param_4, param_5, param_6);
        return;
    }
    if (mode == 3) {
        FUN_a00734c4(&DAT_a006ba48);
        uVar1 = param_1;
        FUN_a00a80cc(uVar1, 1, 0x7d, 0x10, 1);
        uVar4 = FUN_a00a7fd8(uVar1, 1, 8);
        FUN_a00a8054(uVar1, 1, 8, (uVar4 | 0xfffffff0) & 0xff);
        uVar4 = FUN_a00a7fd8(uVar1, 1, 0xe);
        FUN_a00a8054(uVar1, 1, 0xe, uVar4 & 0xf8);
        uVar4 = FUN_a00a7fd8(uVar1, 1, 0xe);
        FUN_a00a8054(uVar1, 1, 0xe, uVar4 & 0x8f);
        uVar4 = FUN_a00a7fd8(uVar1, 1, 0x7c) & 0xcf;
        FUN_a00a8054(uVar1, 1, 0x7c, uVar4);
        return;
    }
    FUN_a0073044(&DAT_a006ba60, mode);
    uVar1 = param_1;
    FUN_a00a80cc(uVar1, 1, 0x7d, 0x10, 0);
    FUN_a00a8054(uVar1, 4, 0xe2, ARR_a8078732[DAT_a80791f0[uVar1]] & 0xff);
    uVar4 = ARR_a8078732[DAT_a80791f0[uVar1]] >> 8;
    FUN_a00a8054(uVar1, 4, 0xe3, uVar4);
    return;
}
