/* leon2s FUN_a00cd4fc @ 0xa00cd4fc-0xa00cd5e4 (58 words), flags -mcpu=v8 -Os -g.
 * ch (u8); f = bits 16..17 of word 0 of the 24-byte record DAT_a8078bb0[ch] (lduh, and 3). If f != 2:
 * r = func_0xa0f9639c(0, 0x90, 0x68029, buf) (buf = 24 bytes at %fp-32); r != 0: f = 3, buf[0] = 0, return;
 * else if bit 0 of buf[0] is clear: f = 3, return. Then (f was 2, or buf[0] bit 0 set): f = 1; if bit 7 of
 * func_0xa0fb78b4(ch, 0x21): func_0xa0fb78fc(ch, 0x21, 0x80). void. Same record and field as FUN_a00cdc74 /
 * FUN_a00c8a80.
 * The field is a 2-bit bit-field (hi:14, f16:2, lo:16) of the record (the firmware reads it with lduh); the
 * r != 0 arm ends with the 'buf[0] = 0' store.
 */
struct Rec18 { unsigned int hi : 14; unsigned int f16 : 2; unsigned int lo : 16; unsigned char pad[0x14]; };
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char func_0xa0f9639c(unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned int func_0xa0fb78b4(unsigned char, unsigned int);
extern void func_0xa0fb78fc(unsigned char, unsigned int, unsigned int);

void FUN_a00cd4fc(unsigned char ch)
{
    unsigned char buf[24];

    if (DAT_a8078bb0[ch].f16 != 2) {
        if (func_0xa0f9639c(0, 0x90, 0x68029, buf) != 0) {
            DAT_a8078bb0[ch].f16 = 3;
            buf[0] = 0;
            return;
        }
        if ((buf[0] & 1) == 0) {
            DAT_a8078bb0[ch].f16 = 3;
            return;
        }
    }
    DAT_a8078bb0[ch].f16 = 1;
    if (func_0xa0fb78b4(ch, 0x21) & 0x80)
        func_0xa0fb78fc(ch, 0x21, 0x80);
}
