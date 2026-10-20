/* leon2s FUN_a00b1e70 @ 0xa00b1e70-0xa00b1fe0 (92 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/92 mismatches.
 * Code facts: one-time init, guarded by the byte DAT_a80793a4 (set to 1 at the end). Clears word
 * DAT_a807de98, the 1 x 2 word array at DAT_a80793a4 + 0xc (nested loops; gcc counts the inner one down:
 * addcc/bpos), picks v = 12000 / 10000 / 3000 for clock word DAT_a80787dc == 96000000 / 80000000 / other,
 * clears bytes +4, +5 and word +0x14 of 16 0x18-byte records at DAT_a80793b8 (a separate symbol: own
 * sethi), pulses bit 1 of hw word 0xc0000000 around FUN_a00b1794(1), writes v / 0x83 / 0 through
 * FUN_a0061534 to 0xc00a0010 / 14 / 18, then read-modify-writes the 0x9f12xxxx / 0x9f100090 registers
 * (|0x10, |0x10, &~0x10, &~2, =2, &~0xf, =0x10). void (the fw never sets %i0).
 * Fixes vs the autoc draft (80.85): void instead of the CONCAT44 garbage return, int loop counters
 * written as plain for loops (the draft's hand-reversed char counter gave btst 0x80 tests), struct
 * records instead of pointer walks. volatile only on the 0x9f1x / 0xc0xx hardware registers. Aids: none.
 */
#define REG_9F100090 (*(volatile unsigned int *)0x9f100090)
#define REG_9F120028 (*(volatile unsigned int *)0x9f120028)
#define REG_9F120030 (*(volatile unsigned int *)0x9f120030)
#define REG_9F120034 (*(volatile unsigned int *)0x9f120034)
#define REG_9F120038 (*(volatile unsigned int *)0x9f120038)
#define REG_9F120044 (*(volatile unsigned int *)0x9f120044)
#define REG_9F12007C (*(volatile unsigned int *)0x9f12007c)
#define REG_C0000000 (*(volatile unsigned int *)0xc0000000)

struct st_a4 {
    unsigned char init;
    unsigned char _01[0xb];
    struct { unsigned int w[2]; } a[1];
};
struct rec18 {
    unsigned char _00[4];
    unsigned char b4;
    unsigned char b5;
    unsigned char _06[0xe];
    unsigned int w14;
};
extern struct st_a4 DAT_a80793a4;
extern struct rec18 DAT_a80793b8[16];
extern unsigned int DAT_a80787dc;
extern unsigned int DAT_a807de98;
extern void FUN_a0061534(volatile unsigned int *, unsigned int);
extern void FUN_a00b1794(int);

void FUN_a00b1e70(void)
{
    int i, j;
    unsigned int v;

    if (DAT_a80793a4.init == 0) {
        DAT_a807de98 = 0;
        for (i = 0; i < 1; i++)
            for (j = 0; j < 2; j++)
                DAT_a80793a4.a[i].w[j] = 0;
        if (DAT_a80787dc == 96000000)
            v = 12000;
        else if (DAT_a80787dc == 80000000)
            v = 10000;
        else
            v = 3000;
        for (i = 0; i < 16; i++) {
            DAT_a80793b8[i].b4 = 0;
            DAT_a80793b8[i].b5 = 0;
            DAT_a80793b8[i].w14 = 0;
        }
        REG_C0000000 |= 2;
        FUN_a00b1794(1);
        REG_C0000000 &= ~2;
        FUN_a0061534((volatile unsigned int *)0xc00a0010, v);
        FUN_a0061534((volatile unsigned int *)0xc00a0014, 0x83);
        FUN_a0061534((volatile unsigned int *)0xc00a0018, 0);
        REG_9F120030 |= 0x10;
        REG_9F100090 |= 0x10;
        REG_9F120028 &= ~0x10;
        REG_9F120044 &= ~2;
        REG_9F12007C = 2;
        REG_9F120038 &= ~0xf;
        REG_9F120034 = 0x10;
        DAT_a80793a4.init = 1;
    }
}
