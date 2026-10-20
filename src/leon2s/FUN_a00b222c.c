/* FUN_a00b222c (leon2s 0xa00b222c-0xa00b229c, 112 bytes, leaf), flags -mcpu=v8 -Os -g.
 * For a non-zero id: finds the first of the 16 24-byte task records DAT_a80793b8 whose word at +0x10 equals id
 * and clears that word; when none matches, tail-calls FUN_a0073044 with s_a006c640
 * ("Can not find S/W timer!" per Ghidra). Record layout as in FUN_a00618d8 / FUN_a00b229c. The record pointer t is
 * taken in the loop and used for the clear (the firmware walks a record pointer).
 */
struct Task {
    unsigned int periodic;
    unsigned char active;
    unsigned char pending;
    unsigned char _6[2];
    unsigned int period;
    unsigned int count;
    unsigned int enabled;
    void (*fn)(void);
};
extern struct Task DAT_a80793b8[16];
extern char s_a006c640[];
extern int FUN_a0073044(const char *, ...);

void FUN_a00b222c(unsigned int id)
{
    int i;
    struct Task *t;

    if (id == 0)
        return;
    for (i = 0; i < 16; i++) {
        t = &DAT_a80793b8[i];
        if (t->enabled == id)
            break;
    }
    if (i == 16) {
        FUN_a0073044(s_a006c640);
        return;
    }
    t->enabled = 0;
}
