/* leon2m FUN_a0154458
 * Copies the 0x50-byte ROM default record S (ROM 0x20170, see FUN_a0153c74) to RAM 0xA802E1A0. Called by
 * FUN_a0142380 right after FUN_a015440c (the 0x30-byte part at ROM 0x20140 to RAM 0xA802E1F0).
 * Source form: the record types and the ROM block at 0x20000 as in FUN_a0153c74; the structures are 8-byte aligned
 * (no-code type attribute), so the copy is done inline with ldd/std pairs; the ROM base 0x20000 is set with sethi
 * alone and the field offset is added in each load.
 */
struct Rec { unsigned char a[0x1a]; unsigned char b1a; unsigned char c[0x1d];
             unsigned short h38, ver, chk, h3e, h40, magic2; unsigned char d[0xc]; } __attribute__((aligned(8)));
struct Part { unsigned char a[0x28]; unsigned short magic1; unsigned char c[6]; } __attribute__((aligned(8)));
struct NV { struct Part p; struct Rec r; };
struct Defaults { unsigned char other[0x140]; struct NV nv; };   /* 0x000..0x13F: not read here */
extern const struct Defaults DAT_00020000;
extern struct Rec DAT_a802e1a0;

void FUN_a0154458(void)
{
    DAT_a802e1a0 = DAT_00020000.nv.r;
}
