/* leon2m FUN_a009cb0c @ 0xa009cb0c-0xa009cb8c (32 words), flags -mcpu=v8 -O3 -g.
 * Code facts: FUN_a00a93bc((word 0xa802afec - 122) & 0xff); loop: v = ((low halfword of the word) - 118) % 5
 * (signed, magic 0x66666667), word = v + 122, until FUN_a00aad30(v & 0xff) returns 1 (u8 test); tail call
 * FUN_a00a9650((word - 122) & 0xff, 1). Twin of FUN_a009cb8c (only the 118 differs).
 * Source form: the halfword is '(unsigned short)_DAT_a802afec' (fw lduh [%i1+0x3ee] on the word's own sethi:
 * combine narrows the word load; see FUN_a00920f4). The callees take u8 arguments.
 * Compiler aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009cb0c(void)
{
    int v;

    FUN_a00a93bc(_DAT_a802afec - 122);
    do {
        v = ((unsigned short)_DAT_a802afec - 118) % 5;
        _DAT_a802afec = v + 122;
    } while (FUN_a00aad30(v) != 1);
    FUN_a00a9650(_DAT_a802afec - 122, 1);
}
