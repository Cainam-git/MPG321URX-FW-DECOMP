/* FUN_CODE_d938, 8051_bank2 (helper chip updater), range 0xD938..0xD99E (102 B).
 * Options: OPTIMIZE(8,SPEED) LARGE. Judge: tools/diff8051.judge (scratch copy) MATCH, exact None, 102/102.
 * Code facts: LARGE parameters addr (ulong, home 0x08F3..0x08F6, stored by ?C?LSTXDATA at entry) and n (0x08F7),
 * local i at 0x08F8. It reads n / 8 words (at least one) from addr into the DATA buffer 0x22 through FUN_CODE_e373,
 * then prints the first n longs of that buffer with printf (FUN_CODE_65ab) and the CODE string 0xC9CB "%08lX\n".
 * KEY FACT: FUN_CODE_e373's real prototype is e373(unsigned long addr, unsigned char n). n is a memory parameter
 * (a char after a long does not get a register) at ?_FUN_CODE_e373?BYTE+4 = 0x098A, so ?_FUN_CODE_e373?BYTE = 0x0986.
 * The accepted src/8051_bank2/FUN_CODE_e373.c reads 0x098A as DAT_EXTMEM_098a; the two-parameter form of e373 gives
 * the same 17 bytes (judged MATCH). Keil loads argument 1 (addr, R4..R7) before it
 * stores the memory argument, which is the firmware's order here.
 * Shape lever: two calls, 'if (n < 8) e373(addr, 1); else e373(addr, n >> 3);'. Keil hoists the shared addr load in
 * front of the JNC and cross-jumps the shared MOVX / LCALL tail (one-call forms with a 0x098A global give
 * 69.6 %, the one-call ?: form 22.6 %).
 * Judge keys this records in symbols/8051_bank2.libs.json: ?_FUN_CODE_e373?BYTE 2438 (0x0986), ?FUN_CODE_d938?XD 2291
 * (0x08F3), ?C?LLDIDATA 13444 (0x3484). Caller: FUN_CODE_d2fb (0xD352). No aids.
 */
extern unsigned char data DAT_0022[];
extern void FUN_CODE_65ab(void *fmt, ...) large;
void FUN_CODE_e373(unsigned long addr, unsigned char n);
void FUN_CODE_d938(unsigned long addr, unsigned char n)
{
    unsigned char i;
    if (n < 8) FUN_CODE_e373(addr, 1);
    else FUN_CODE_e373(addr, n >> 3);
    for (i = 0; i < n; i++)
        FUN_CODE_65ab((void code *)0xc9cb, ((unsigned long data *)DAT_0022)[i]);
}
