/* leon2m FUN_a009aec8 @ 0xa009aec8-0xa009af8c (49 words)  MATCH (-mcpu=v8 -O3 -g, twin)
 * Same code as FUN_a009ad40 (whose header describes it) with other constants: base 0xd4 instead of 0xd0 and step
 * offset 0xd3 instead of 0xcf. The word 0xa802afec steps forwards through 0xd4..0xd7: FUN_a00a93bc(afec - 0xd4),
 * then t = ((low halfword of afec) - 0xd3) % 4 and afec = t + 0xd4 until FUN_a00aad30(t) returns 1;
 * FUN_a00a9650(afec - 0xd4, 1); FUN_a00a813c(1, FUN_a01445fc(byte 0xa8025c55), flag) with flag 0 when
 * FUN_a014459c(afec - 0xd4) equals byte 0xa8025c55, else 1.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern unsigned char FUN_a01445fc(unsigned char);

void FUN_a009aec8(void)
{
    int t;

    FUN_a00a93bc(_DAT_a802afec - 0xd4);
    do {
        t = (unsigned short)_DAT_a802afec - 0xd3;
        t = t % 4;
        _DAT_a802afec = t + 0xd4;
    } while (FUN_a00aad30(t) != 1);
    FUN_a00a9650(_DAT_a802afec - 0xd4, 1);
    if (FUN_a014459c(_DAT_a802afec - 0xd4) == DAT_a8025c55)
        FUN_a00a813c(1, FUN_a01445fc(DAT_a8025c55), 0);
    else
        FUN_a00a813c(1, FUN_a01445fc(DAT_a8025c55), 1);
}
