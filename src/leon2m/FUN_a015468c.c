/* leon2m FUN_a015468c @ 0xa015468c-0xa01546ec (24 words), flags -mcpu=v8 -g (unoptimised: both parameters are
 * spilled to the stack and reloaded). Called by FUN_a00bb260 and FUN_a00bb908.
 * Returns byte b of row a of the 11-byte-per-row table at 0x1a7a6e, whose rows are ASCII frames such as
 * "5b0010000\xff\r", "5b0050000\xff\r", "5b0010200\xff\r", "5b00400\xff\xff\xff\r" (0xff = unused byte).
 * Same form as FUN_a015463c (8-byte rows at 0x1a7656).
 */
extern const unsigned char DAT_001a7a6e[][11];
unsigned char FUN_a015468c(unsigned short a, unsigned short b)
{
    return DAT_001a7a6e[a][b];
}
