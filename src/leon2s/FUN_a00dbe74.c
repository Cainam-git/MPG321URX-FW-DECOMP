/* leon2s FUN_a00dbe74 @ 0xa00dbe74-0xa00dbed4 (24 words, incl. the merged unreachable tail FUN_a00dbecc), flags
 * -mcpu=v8 -Os -g.
 * If byte 0xa8078841 & 0x30: FUN_a00db784(); i = byte 0xa8078832; if byte 0xa8078828[i] == byte
 * 0xa8078830[i]: tail FUN_a00dbc8c(). void.
 * 0xa8078830 is a second byte array indexed by the same i (firmware 'or 0x30' + [base + i]).
 */
extern unsigned char DAT_a8078828[];
extern unsigned char DAT_a8078830[];
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078841;
extern void FUN_a00db784(void);
extern void FUN_a00dbc8c(void);

void FUN_a00dbe74(void)
{
    if (DAT_a8078841 & 0x30)
        FUN_a00db784();
    if (DAT_a8078828[DAT_a8078832] == DAT_a8078830[DAT_a8078832])
        FUN_a00dbc8c();
}
