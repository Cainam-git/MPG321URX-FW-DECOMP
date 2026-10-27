/* leon2m FUN_a01492f0 @ 0xa01492f0-0xa014931c (11 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00d47c8.
 * Stores v in byte 6 of 0xa802e3d0, calls FUN_a01198c8(v, 0) and tail-calls FUN_a01198c8 with that byte read
 * back and 1.
 * Source form: old-style (K&R) definition: v arrives as int, is stored unmasked and masked for the call.
 */
struct E3d0 { unsigned char p00[6]; unsigned char b06; };
extern struct E3d0 DAT_a802e3d0;
extern void FUN_a01198c8(unsigned int, unsigned char);

void FUN_a01492f0(v)
    unsigned char v;
{
    DAT_a802e3d0.b06 = v;
    FUN_a01198c8(v, 0);
    FUN_a01198c8(DAT_a802e3d0.b06, 1);
}
