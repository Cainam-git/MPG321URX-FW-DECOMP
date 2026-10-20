/* leon2s FUN_a00caee4 @ 0xa00caee4-0xa00caf78 (37 words), flags -mcpu=v8 -Os -g.
 * u8 ch. Sets the 2-bit field (bits 16..17) of word 0 of the 24-byte record DAT_a8078bb0[ch] to 1; buffer
 * DAT_a807ce50[0] = 5; FUN_a00c87e8(ch, 5, 0x8000); 32 reads buf[1 + i] = FUN_a00c7770(ch, 1) (u8 results);
 * then the sibcall FUN_a00c80f0(ch, DAT_a807ce50, 0x74, 0x60, 0x21). void.
 * The buffer bytes are FUN_a00c7770's return values; the record field is the Rec18 f16:2 bit-field (same
 * record as FUN_a00cd4fc); the buffer base DAT_a807ce50 serves both the stores and the FUN_a00c80f0 argument.
 */
struct Rec18 { unsigned int hi : 14; unsigned int f16 : 2; unsigned int lo : 16; unsigned char pad[0x14]; };
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a807ce50[];
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);
extern void FUN_a00c80f0(unsigned char, unsigned char *, int, int, int);

void FUN_a00caee4(unsigned char ch)
{
    unsigned char i;

    DAT_a8078bb0[ch].f16 = 1;
    DAT_a807ce50[0] = 5;
    FUN_a00c87e8(ch, 5, 0x8000);
    for (i = 0; i < 0x20; i++)
        DAT_a807ce50[1 + i] = FUN_a00c7770(ch, 1);
    FUN_a00c80f0(ch, DAT_a807ce50, 0x74, 0x60, 0x21);
}
