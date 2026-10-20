/* leon2s FUN_a008f270 @ 0xa008f270  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical Ghidra C, finished by hand: switch cases in natural order 0, 1, 2; Ghidra type names kept.
 */
extern unsigned int DAT_a0068de8; /* 0xa0068de8 */
extern unsigned int DAT_a0068e08; /* 0xa0068e08 */
extern unsigned int DAT_a0068e38; /* 0xa0068e38 */
extern unsigned int DAT_a0068e60; /* 0xa0068e60 */

extern void FUN_a0073044(unsigned int *, int); /* 0xa0073044 */
extern void FUN_a00734c4(unsigned int *);      /* 0xa00734c4 */
extern void FUN_a00a80cc(int, int, int, int, int); /* 0xa00a80cc */
extern void FUN_a008e098(int, int);            /* 0xa008e098 */
extern void FUN_a008e0f0(int, int, int);       /* 0xa008e0f0 */
extern void FUN_a008e200(int, int);            /* 0xa008e200 */
extern void FUN_a00a8184(int, int, int, int, int); /* 0xa00a8184 */
extern void FUN_a008e2c0(int, int, int);       /* 0xa008e2c0 */
extern void FUN_a008e3c0(int, int);            /* 0xa008e3c0 */
extern void FUN_a0091cf4(int, int, int);       /* 0xa0091cf4 */
extern void FUN_a00a8054(int, int, int, int);  /* 0xa00a8054 */
extern void FUN_a008e484(int, int, int, int, int, int); /* 0xa008e484 */

void FUN_a008f270(int param_1, int param_2, int param_3, int param_4,
                  int param_5, int param_6) /* 0xa008f270 */
{
    unsigned char uVar1;
    unsigned char uVar3;
    unsigned char iVar2;
    unsigned char uVar4;
    unsigned char iVar5;
    unsigned char uVar6;

    FUN_a0073044(&DAT_a0068de8, param_2);

    uVar3 = 0;
    iVar2 = 0;
    uVar4 = 0;
    iVar5 = 0;
    uVar6 = 0;
    uVar1 = 0;

    if (param_2 > 0x94) {
        if ((unsigned int)(param_2 - 149) <= 0xbf)
            uVar1 = 1;
        else
            uVar1 = 2;
    }

    switch (uVar1) {
    case 0:
        FUN_a00734c4(&DAT_a0068e38);
        uVar3 = 0;
        iVar2 = 0;
        uVar4 = 0;
        iVar5 = 0;
        uVar6 = 0;
        break;
    case 1:
        FUN_a00734c4(&DAT_a0068e08);
        uVar3 = 6;
        iVar2 = 1;
        uVar4 = 0x11;
        iVar5 = 0;
        uVar6 = 0;
        break;
    case 2:
        FUN_a00734c4(&DAT_a0068e60);
        uVar3 = 0x1b;
        iVar2 = 2;
        uVar4 = 0x22;
        iVar5 = 3;
        uVar6 = 1;
        break;
    default:
        break;
    }

    param_1 &= 0xff;

    FUN_a00a80cc(param_1, 1, 0x7d, 0x80, 0);
    FUN_a008e098(param_1, uVar3 & 0x1f);
    FUN_a008e0f0(param_1, iVar2, 0);
    FUN_a008e200(param_1, uVar4 & 0x33);

    if (iVar2 == 2) {
        FUN_a00a8184(param_1, 1, 0x9b, 0x70, 0x10);
    }

    FUN_a008e2c0(param_1, iVar2, 0);
    FUN_a008e3c0(param_1, 0);
    FUN_a0091cf4(param_1, 0x20, iVar5);

    if (iVar5 == 3) {
        FUN_a00a8054(param_1, 1, 0x31, 0);
        FUN_a00a8054(param_1, 1, 0x32, 0);
        FUN_a00a8054(param_1, 1, 0x33, 0x32);
        FUN_a00a8054(param_1, 1, 0x34, 0);
    }

    FUN_a008e484(param_1, uVar6 & 1, param_3, param_4, param_5, param_6);
}
