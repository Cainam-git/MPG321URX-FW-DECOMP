/* FUN_a01181a4: clears a group of state bytes.
 * Writes 6 to byte 3 of the 4-byte record at 0xa8027a90 and 0 to bytes 0, 1 and 2, and clears the two
 * separate bytes 0xa802c98c and 0xa802c98d. Called from FUN_a014d5f4.
 * The record is one object (its address is kept in a register and the bytes are stored by offset);
 * byte 2 is written before byte 1 in the source, which gives the firmware order.
 */
struct Rec4 { unsigned char b0, b1, b2, b3; };
extern struct Rec4 DAT_a8027a90;
extern unsigned char DAT_a802c98c;
extern unsigned char DAT_a802c98d;

void FUN_a01181a4(void)
{
    DAT_a8027a90.b3 = 6;
    DAT_a8027a90.b0 = 0;
    DAT_a802c98d = 0;
    DAT_a802c98c = 0;
    DAT_a8027a90.b2 = 0;
    DAT_a8027a90.b1 = 0;
}
