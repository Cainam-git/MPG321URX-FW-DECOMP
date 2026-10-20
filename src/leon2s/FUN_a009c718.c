/* leon2s FUN_a009c718 @ 0xa009c718  MATCH (-mcpu=v8 -Os -g)
 * Fills the record at param_2 for port param_1 & 0xFF: words 0..3 from FUN_a009c3f0 (low byte), FUN_a009c4a4 (low
 * byte), FUN_a009c558 and FUN_a009c58c; byte +0x10 from FUN_a0097ed0; byte +0x11 from FUN_a009c6e4 when a second
 * FUN_a0097ed0 call returns a non-zero low byte, else 0. FUN_a0097ed0 and FUN_a009c6e4 take one argument (only %o0
 * is set before the calls).
 */
extern unsigned int FUN_a0097ed0(unsigned int);
extern unsigned int FUN_a009c3f0(unsigned int);
extern unsigned int FUN_a009c4a4(unsigned int);
extern unsigned int FUN_a009c558(unsigned int);
extern unsigned int FUN_a009c58c(unsigned int);
extern unsigned int FUN_a009c6e4(unsigned int);

void FUN_a009c718(unsigned int param_1, unsigned int *param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;

    uVar1 = param_1 & 0xff;
    *param_2 = FUN_a009c3f0(uVar1) & 0xff;
    param_2[1] = FUN_a009c4a4(uVar1) & 0xff;
    param_2[2] = FUN_a009c558(uVar1);
    param_2[3] = FUN_a009c58c(uVar1);
    *(unsigned char *)(param_2 + 4) = (unsigned char)FUN_a0097ed0(uVar1);
    uVar2 = FUN_a0097ed0(uVar1);
    if ((uVar2 & 0xff) != 0) {
        *(unsigned char *)((unsigned int)param_2 + 0x11) = 
            (unsigned char)FUN_a009c6e4(uVar1);
    } else {
        *(unsigned char *)((unsigned int)param_2 + 0x11) = 0;
    }
}
