/* leon2m FUN_a015463c @ 0xa015463c  command-string character. Flags: -mcpu=v8 -g, no -O (both
 * parameters are spilled to the stack and reloaded).
 *
 * Returns byte b of row a of the 8-byte-per-row table at 0x1A7656 (flash 0x2AF656):
 *   row 0 "5800100\r", row 1 "5800110\r", row 2 "580040:\r", row 3 "5800400\r", row 4 "5800410\r", row 5 "5800420\r".
 * Caller: FUN_a00bf110 ("--->UartSetI2CEnable") reads row 2, bytes 0 and 2..6, to build its reply frame (byte 1
 * replaced by 'b').
 */
extern const unsigned char DAT_001a7656[][8];
unsigned char FUN_a015463c(unsigned short a, unsigned short b)
{
    return DAT_001a7656[a][b];
}
