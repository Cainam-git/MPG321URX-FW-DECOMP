/* leon2m FUN_a00953d4 @ 0xa00953d4  MATCH (-mcpu=v8 -O2 -g)
 * This function performs a short sequence of register writes and helper calls on the NT68500 scaler: it writes 0x0F to a status/control byte at 0xa802b08f, calls two initialisation helpers, stores the 32-bit constant 0x7B at 0xa802afec, calls a third helper with two unit arguments, copies a byte from 0xa802d434 into 0xa8025c55, and finally sets bit 1 (OR with 2) on the byte at 0xa802b08e. FUN_a00a9650 is declared with two arguments: the `mov 1,%o1` in the call's delay slot is not emitted for a single-argument call.
 */
extern unsigned char DAT_a802b08f; /* 0xa802b08f */
extern unsigned char DAT_a802b08e; /* 0xa802b08e */
extern unsigned int  DAT_a802afec; /* 0xa802afec */
extern unsigned char DAT_a802d434; /* 0xa802d434 */
extern unsigned char DAT_a8025c55; /* 0xa8025c55 */
extern void FUN_a00a8c88(void);
extern void FUN_a00a86e8(void);
extern void FUN_a00a9650(unsigned int, unsigned int);

void FUN_a00953d4(void)
{
    DAT_a802b08f = 0xf;
    FUN_a00a8c88();
    FUN_a00a86e8();
    DAT_a802afec = 0x7b;
    FUN_a00a9650(1, 1);
    DAT_a8025c55 = DAT_a802d434;
    DAT_a802b08e = DAT_a802b08e | 2;
}
