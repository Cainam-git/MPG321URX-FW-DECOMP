/* FUN_a00d0798 (leon2s 0xa00d0798-0xa00d0828, 144 bytes), flags -mcpu=v8 -Os -g.
 * Sets the 2-bit state field st (bits 16..17 of word 0) of the 24-byte record port of DAT_a8078bb0 to 1. When the
 * ROM routine func_0xa0f98af0(0) returns 0 sets st to 0; otherwise calls FUN_a00d0530(10, 300), sets st to 1 and
 * tail-calls FUN_a00cca38(0). Record layout as in FUN_a00cb1d4.
 */
struct Rec24 {
    unsigned int top:4;
    unsigned int cnt:4;
    unsigned int mid:6;
    unsigned int st:2;
    unsigned int low:16;
    unsigned char b4[20];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned char func_0xa0f98af0(unsigned int);
extern void FUN_a00d0530(unsigned int, unsigned int);
extern void FUN_a00cca38(unsigned char);

void FUN_a00d0798(unsigned char port)
{
    DAT_a8078bb0[port].st = 1;
    if (func_0xa0f98af0(0) == 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    FUN_a00d0530(10, 300);
    DAT_a8078bb0[port].st = 1;
    FUN_a00cca38(0);
}
