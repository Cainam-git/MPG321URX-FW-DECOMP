/* FUN_a00c8aec (leon2s 0xa00c8aec-0xa00c8b18, 44 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Sets the 2-bit field st (bits 16..17 of word 0) of the 24-byte record DAT_a8078bb0[port] to 3 (same record
 * layout as FUN_a00c91f8). Called by FUN_a00d03a0.
 */
struct Rec24 {
    unsigned int a:3;
    unsigned int f28:1;
    unsigned int cnt:4;
    unsigned int f23:1;
    unsigned int mid:5;
    unsigned int st:2;
    unsigned int x:8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char pad[17];
};
extern struct Rec24 DAT_a8078bb0[];

void FUN_a00c8aec(unsigned char port)
{
    DAT_a8078bb0[port].st = 3;
}
