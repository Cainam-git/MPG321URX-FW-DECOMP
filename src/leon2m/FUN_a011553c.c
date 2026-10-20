/* leon2m FUN_a011553c @ 0xa011553c-0xa0115584 (18 words), flags -mcpu=v8 -O3 -g.
 * Code facts: hw reg 0xcf022bf8 = 0; log FUN_a00df170(string 0x1a2f20, hw reg 0xcf022800 & 0xff); 0xcf022bf8 = 0
 * again; 0xcf022800 = 0xaa; 0xcf022bf8 = 0; log FUN_a00df170(the SAME string 0x1a2f20, 0xcf022800 & 0xff) as a tail
 * call ('restore %i0, 0x320, %o0' completes the shared %hi). void. volatile only on the 0xcf... hw registers (each
 * access is real).
 * The second log uses the same string (not base + 0x320 = 0x1a3240), and there is a second 'bf8 = 0' write right
 * after the first log. Compiler aids: none.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern const char s_001a2f20[];

#define REG_cf022800 (*(volatile unsigned int *)0xcf022800)
#define REG_cf022bf8 (*(volatile unsigned int *)0xcf022bf8)

void FUN_a011553c(void)
{
    REG_cf022bf8 = 0;
    FUN_a00df170(s_001a2f20, REG_cf022800 & 0xff);
    REG_cf022bf8 = 0;
    REG_cf022800 = 0xaa;
    REG_cf022bf8 = 0;
    FUN_a00df170(s_001a2f20, REG_cf022800 & 0xff);
}
