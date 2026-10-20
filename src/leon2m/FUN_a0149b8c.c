/* FUN_a0149b8c: copies the 16-byte record p (eight u16, 2-byte aligned, so GCC copies it halfword by halfword)
 * into a local and passes the copy to FUN_a013d1b4(ch, &copy). Callers: FUN_a00d79b0, FUN_a00d79f0,
 * FUN_a00d7a30, FUN_a00d7a70.
 */
struct H8 { unsigned short h[8]; };
extern void FUN_a013d1b4(unsigned char ch, struct H8 *v);

void FUN_a0149b8c(unsigned char ch, const struct H8 *p)
{
    struct H8 v = *p;

    FUN_a013d1b4(ch, &v);
}
