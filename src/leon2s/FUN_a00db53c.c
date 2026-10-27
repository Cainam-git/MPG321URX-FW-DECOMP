/* leon2s FUN_a00db53c @ 0xa00db53c-0xa00db784, -mcpu=v8 -Os -g.
 * void (void). Code linked 0xF10000 above its load address (func_0xa0f8.... calls, s_9f1c.... strings).
 * i = DAT_a80787fe; row = 48-byte row DAT_a807a520[i & 0xf]; v = (row[0] >> 4) - 1, n = v / 2 rounded up for
 * odd v; len = DAT_a8079c88[i]. row[n + 3] == 0x11: unless row[n + 6] and row[n + 7] are both 0, prints
 * "AllocatePLDIDTable : %d, %d" with row[n + 5] and 0, FUN_a00dae90(row[n + 5], 0, 0), FUN_a00d64ec() and
 * "Trigger %s to other REQ" with "ACT". row[n + 3] == 0x14: FUN_a00dae90(0, 1, 1); when DAT_a8078854 is 1 the
 * low bytes of the registers 0xcf013000 / 0xcf0189e0 are saved, bit 7 / bit 0 set around FUN_a00d64ec() and
 * restored, and DAT_a8078854 cleared. Then for each 16-byte block j of the len bytes of the row:
 * func_0xa0f963d4(0, 0x80, 0x1000 + 16j, count - 1 (15 for full blocks), row + 16j); a 0 result prints
 * "OtherReqBuf_Update FAIL(%d)" with DAT_a8078832. Finally DAT_a80787fe steps modulo 16.
 * Source forms: the size byte is an unsigned short local (the firmware masks it again at each use);
 * FUN_a00dae90 is declared with an int result (argument set-up order).
 */
extern unsigned char DAT_a80787fe;
extern unsigned char DAT_a8078854;
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8079c88[];
extern unsigned char DAT_a807a520[][48];
extern const char s_9f1ccae8[], s_9f1ccb08[], s_9f1ccb30[], s_9f1ccb38[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned char func_0xa0f963d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int FUN_a00dae90(unsigned char, unsigned char, unsigned char);
extern void FUN_a00d64ec(void);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00db53c(void)
{
    unsigned char *row;
    int v;
    unsigned char n, j, ok;
    unsigned char len;
    unsigned short size;
    unsigned char s1, s2;

    size = 0;
    s1 = 0;
    s2 = 0;
    row = DAT_a807a520[DAT_a80787fe & 0xf];
    v = (row[0] >> 4) - 1;
    n = v / 2;
    len = DAT_a8079c88[DAT_a80787fe];
    if (v & 1)
        n = v / 2 + 1;
    if (row[n + 3] == 0x11) {
        if (row[n + 6] == 0 && row[n + 7] == 0)
            ok = 1;
        else {
            size = row[n + 5];
            ok = 0;
        }
        if (!ok) {
            func_0xa0f83044(s_9f1ccae8, size, 0);
            FUN_a00dae90(size, 0, 0);
            FUN_a00d64ec();
            func_0xa0f83044(s_9f1ccb08, s_9f1ccb30);
        }
    } else if (row[n + 3] == 0x14) {
        FUN_a00dae90(0, 1, 1);
        if (DAT_a8078854 == 1) {
            s1 = R(0xcf013000);
            s2 = R(0xcf0189e0);
            R(0xcf013000) |= 0x80;
            R(0xcf0189e0) |= 1;
        }
        FUN_a00d64ec();
        if (DAT_a8078854 == 1) {
            R(0xcf013000) = s1;
            R(0xcf0189e0) = s2;
            DAT_a8078854 = 0;
        }
    }
    for (j = 0; (j << 4) < len; j++) {
        if ((j << 4) + 16 > len) {
            if (!func_0xa0f963d4(0, 0x80, 0x1000 + (j << 4), (signed char)(len - (j << 4) - 1), row + (j << 4)))
                func_0xa0f83044(s_9f1ccb38, DAT_a8078832);
        } else {
            if (!func_0xa0f963d4(0, 0x80, 0x1000 + (j << 4), 0xf, row + (j << 4)))
                func_0xa0f83044(s_9f1ccb38, DAT_a8078832);
        }
    }
    DAT_a80787fe = (DAT_a80787fe + 1) & 0xf;
}
