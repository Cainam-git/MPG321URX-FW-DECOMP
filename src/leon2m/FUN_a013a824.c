/* leon2m FUN_a013a824 @ 0xa013a824 (-mcpu=v8 -O2 -g)
 * Reads one word from mailbox portal 2 at offset 0x4C into a zeroed local (MailBox_Read, func_0x4008c4d0(2, 0x4c,
 * &w, 1)) and returns its byte 1 ((w & 0xff00) >> 8). No parameters. The single unsigned int local gives the clr
 * [%fp-12] / ld [%fp-12] pair of the target.
 */
extern void func_0x4008c4d0();

unsigned int FUN_a013a824(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(2, 0x4c, &local_c, 1);
    return (local_c & 0xff00) >> 8;
}
