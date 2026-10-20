/* FUN_a014e1d0: calls FUN_a010afc8(), FUN_a010b198() and the delay func_0x4008d1a0(10), then for sel 0..4 calls a
 * pair of routines with the argument 0: 0 -> FUN_a010b030, FUN_a010b200; 1 -> FUN_a010b07c, FUN_a010b24c;
 * 2 -> FUN_a010afe4, FUN_a010b1b4; 3 -> FUN_a010b0c8, FUN_a010b298; 4 -> FUN_a010b114, FUN_a010b2e4 (the second
 * one as a tail call); other sel values do nothing. No direct callers were found.
 */
extern void FUN_a010afc8(void);
extern void FUN_a010b198(void);
extern int func_0x4008d1a0(int);
extern void FUN_a010b030(void *p);
extern void FUN_a010b200(void *p);
extern void FUN_a010b07c(void *p);
extern void FUN_a010b24c(void *p);
extern void FUN_a010afe4(void *p);
extern void FUN_a010b1b4(void *p);
extern void FUN_a010b0c8(void *p);
extern void FUN_a010b298(void *p);
extern void FUN_a010b114(void *p);
extern void FUN_a010b2e4(void *p);

void FUN_a014e1d0(unsigned char sel)
{
    FUN_a010afc8();
    FUN_a010b198();
    func_0x4008d1a0(10);
    switch (sel) {
    case 0:
        FUN_a010b030(0);
        FUN_a010b200(0);
        break;
    case 1:
        FUN_a010b07c(0);
        FUN_a010b24c(0);
        break;
    case 2:
        FUN_a010afe4(0);
        FUN_a010b1b4(0);
        break;
    case 3:
        FUN_a010b0c8(0);
        FUN_a010b298(0);
        break;
    case 4:
        FUN_a010b114(0);
        FUN_a010b2e4(0);
        break;
    }
}
