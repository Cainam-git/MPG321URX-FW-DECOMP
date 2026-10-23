/* leon2m FUN_a01452d0 @ 0xa01452d0
 * Stores into the 16-bit field at bytes +0x03..+0x04 of the settings record at 0xA802E1A0 (it straddles the words
 * +0x00 and +0x04, so each store is two word read-modify-writes) first the byte argument a, then the 16-bit
 * argument v; writes the record back with FUN_a0153970(&record, 0), then tail-calls FUN_a0104f48(1, f, f) with
 * the field value f read back from the record. No direct callers (reached through a pointer).
 * Source form: the two field stores are separate statements; GCC merges them into one read-modify-write per word,
 * and the dead a << 24 term of the first store stays in the +0x04 word update as in the firmware.
 */
struct __attribute__((packed, aligned(4))) Settings {
    unsigned char b00, b01, b02;
    unsigned short h03:16;
    unsigned char rest[0x50 - 5];
};
extern struct Settings DAT_a802e1a0;
extern void FUN_a0153970(void *, unsigned char);
extern void FUN_a0104f48(unsigned char, unsigned short, unsigned short);

void FUN_a01452d0(unsigned char a, unsigned short v)
{
    DAT_a802e1a0.h03 = a;
    DAT_a802e1a0.h03 = v;
    FUN_a0153970(&DAT_a802e1a0, 0);
    FUN_a0104f48(1, DAT_a802e1a0.h03, DAT_a802e1a0.h03);
}
