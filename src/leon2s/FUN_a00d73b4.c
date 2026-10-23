/* leon2s FUN_a00d73b4 @ 0xa00d73b4-0xa00d74ec, -mcpu=v8 -Os -g.
 * (out, u8 a, u8 b, u8 type), void. src = FUN_a00d66bc(a, b); nothing when src is 0. Otherwise a switch on
 * type tail-calls one converter with (out, src): 0x10 FUN_a00d6b4c, 0x11 FUN_a00d6b98, 0x12 FUN_a00d6c98,
 * 0x13 FUN_a00d6cfc, 0x16 FUN_a00d6dac, 0x17 FUN_a00d6df8, 0x18 FUN_a00d6e94, 0x19 FUN_a00d6f70,
 * 0x1a FUN_a00d714c, 0x1b FUN_a00d7210, 0x1c FUN_a00d7274, 0x38 FUN_a00d72d8; type 0x1f and other values
 * do nothing.
 * Source form: 'case 0x1f: return;' keeps 0x1f in the compare tree (it sets the root at 0x18); FUN_a00d66bc's
 * result is used as a byte pointer.
 */
extern unsigned char *FUN_a00d66bc(unsigned int, unsigned int);
extern void FUN_a00d6b4c(void *, unsigned char *);
extern void FUN_a00d6b98(void *, unsigned char *);
extern void FUN_a00d6c98(void *, unsigned char *);
extern void FUN_a00d6cfc(void *, unsigned char *);
extern void FUN_a00d6dac(void *, unsigned char *);
extern void FUN_a00d6df8(void *, unsigned char *);
extern void FUN_a00d6e94(void *, unsigned char *);
extern void FUN_a00d6f70(void *, unsigned char *);
extern void FUN_a00d714c(void *, unsigned char *);
extern void FUN_a00d7210(void *, unsigned char *);
extern void FUN_a00d7274(void *, unsigned char *);
extern void FUN_a00d72d8(void *, unsigned char *);

void FUN_a00d73b4(void *out, unsigned char a, unsigned char b, unsigned char type)
{
    unsigned char *src = FUN_a00d66bc(a, b);

    if (src == 0)
        return;
    switch (type) {
    case 0x10: FUN_a00d6b4c(out, src); break;
    case 0x11: FUN_a00d6b98(out, src); break;
    case 0x12: FUN_a00d6c98(out, src); break;
    case 0x13: FUN_a00d6cfc(out, src); break;
    case 0x16: FUN_a00d6dac(out, src); break;
    case 0x17: FUN_a00d6df8(out, src); break;
    case 0x18: FUN_a00d6e94(out, src); break;
    case 0x19: FUN_a00d6f70(out, src); break;
    case 0x1a: FUN_a00d714c(out, src); break;
    case 0x1b: FUN_a00d7210(out, src); break;
    case 0x1c: FUN_a00d7274(out, src); break;
    case 0x1f: return;
    case 0x38: FUN_a00d72d8(out, src); break;
    }
}
