/* leon2s FUN_a00b34a8 @ 0xa00b34a8 (-mcpu=v8 -Os)
 */
extern unsigned char DAT_a807dec4;
extern unsigned int _DAT_a807deac;
extern unsigned char DAT_a807dea8;
extern unsigned char DAT_a807e0b0;
extern unsigned char DAT_a807deb0;
extern int FUN_a0061280(const char *, ...);

void FUN_a00b34a8(void)
{
    int i;
    int j;
    unsigned char *p;

    DAT_a807dec4 = 0;
    _DAT_a807deac = 0;
    DAT_a807dea8 = 0;
    DAT_a807e0b0 = 0;
    DAT_a807deb0 = 0;

    p = (unsigned char *)0xa807dff0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 0x20; j++) {
            p[j] = 0;
        }
        p += 0x20;
    }

    FUN_a0061280("\n---------------------------------------------");
    FUN_a0061280("\n    Welcome to User's Command Line Debug");
    FUN_a0061280("\n---------------------------------------------\n");
}
