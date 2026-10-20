/* leon2m FUN_a01451fc @ 0xa01451fc-0xa01452d0 (53 words), flags -mcpu=v8 -O3 -g.
 * Code facts: init sequence. Log FUN_a00df170(string 0x1a6e20); FUN_a0107a20(2, 0); ROM
 * func_0x4008992c(1); FUN_a0124f44(); FUN_a014512c(0, 1); FUN_a0124f08(); FUN_a0125c8c();
 * bit 18 of word 0 of the record DAT_a802e3d0 = FUN_a0137bb0() (it returns 0/1: and %i0,1);
 * FUN_a0138718(); FUN_a01396d8(); FUN_a0140a0c(); FUN_a0136600(record byte +0x33 = 0xa802e403);
 * FUN_a0136384(); FUN_a0136054(); FUN_a013874c(); FUN_a011d194(); FUN_a0135dc0();
 * func_0x4008992c(0); FUN_a00de65c(); FUN_a0124fd0(); tail FUN_a0133e34(). Returns nothing.
 * FUN_a01396d8 takes no arguments.
 * Source form: bit 18 is a 1-bit bit-field and +0x33 a byte of the same record (fw reads it as
 * [rec + 0x33]). Not volatile (RAM). Aids: none.
 */
struct E3D0 {
    unsigned int hi : 13;
    unsigned int b18 : 1;
    unsigned int lo : 18;
    unsigned char pad[0x33 - 4];
    unsigned char b33;
};
extern struct E3D0 DAT_a802e3d0;
extern const char s_001a6e20[];
extern void FUN_a00de65c(void);
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a0107a20(unsigned int, unsigned int);
extern void FUN_a011d194(void);
extern void FUN_a0124f08(void);
extern void FUN_a0124f44(void);
extern void FUN_a0124fd0(void);
extern void FUN_a0125c8c(void);
extern void FUN_a0133e34(void);
extern void FUN_a0135dc0(void);
extern void FUN_a0136054(void);
extern void FUN_a0136384(void);
extern void FUN_a0136600(unsigned char);
extern int FUN_a0137bb0(void);
extern void FUN_a0138718(void);
extern void FUN_a013874c(void);
extern void FUN_a01396d8(void);
extern void FUN_a0140a0c(void);
extern void FUN_a014512c(unsigned int, unsigned int);
extern void func_0x4008992c(unsigned int);

void FUN_a01451fc(void)
{
    FUN_a00df170(s_001a6e20);
    FUN_a0107a20(2, 0);
    func_0x4008992c(1);
    FUN_a0124f44();
    FUN_a014512c(0, 1);
    FUN_a0124f08();
    FUN_a0125c8c();
    DAT_a802e3d0.b18 = FUN_a0137bb0();
    FUN_a0138718();
    FUN_a01396d8();
    FUN_a0140a0c();
    FUN_a0136600(DAT_a802e3d0.b33);
    FUN_a0136384();
    FUN_a0136054();
    FUN_a013874c();
    FUN_a011d194();
    FUN_a0135dc0();
    func_0x4008992c(0);
    FUN_a00de65c();
    FUN_a0124fd0();
    FUN_a0133e34();
}
