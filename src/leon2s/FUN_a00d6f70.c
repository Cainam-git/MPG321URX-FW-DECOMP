/* FUN_a00d6f70 (leon2s 0xa00d6f70-0xa00d714c, 476 bytes), flags -mcpu=v8 -Os -g. Leaf.
 * void (struct Out *o, u8 *s). k = (s[0] >> 4) - 1, off = k / 2 plus 1 when k is odd; bytes are read from
 * s[off + i] with a running u16 index i starting at 3. Copies bit-fields into the 0x1e-byte record o: the low
 * 7 bits of byte 3 into o byte 0, the high nibble and the low 2 bits (n) of byte 4 into o byte 1; then for
 * e < n one 13-byte entry o->e[e]: low 7 bits of the next byte, a length byte len, len data bytes, then bit 4
 * and the low nibble of the next byte into the entry's last byte; finally the low 7 bits of the next byte into
 * o byte 0x1c and the following byte into o byte 0x1d. Same record layout as FUN_a00d6724.
 * Source form: the header bytes are read through the running index too ('i = 3; ... i++;'), every read
 * indexes as s[off + i] (with i++ where the index advances).
 */
struct B7 { unsigned char x : 1; unsigned char a : 7; };
struct B1 { unsigned char hi : 4; unsigned char y : 2; unsigned char n : 2; };
struct BE { unsigned char z : 3; unsigned char f : 1; unsigned char g : 4; };
struct Ent { struct B7 h; unsigned char len; unsigned char d[10]; struct BE t; };
struct Out { struct B7 h; struct B1 b1; struct Ent e[2]; struct B7 t; unsigned char u; };

void FUN_a00d6f70(struct Out *o, unsigned char *s)
{
    unsigned char off, e, m;
    unsigned short i;
    int k, h;

    k = (s[0] >> 4) - 1;
    h = k / 2;
    off = h;
    if (k & 1)
        off = h + 1;
    i = 3;
    o->h.a = ((struct B7 *)&s[off + i])->a;
    i++;
    o->b1.hi = ((struct B1 *)&s[off + i])->hi;
    o->b1.n = ((struct B1 *)&s[off + i])->n;
    i++;
    for (e = 0; e < o->b1.n; e++) {
        o->e[e].h.a = ((struct B7 *)&s[off + i++])->a;
        o->e[e].len = s[off + i++];
        for (m = 0; m < o->e[e].len; m++)
            o->e[e].d[m] = s[off + i++];
        o->e[e].t.f = ((struct BE *)&s[off + i])->f;
        o->e[e].t.g = ((struct BE *)&s[off + i])->g;
        i++;
    }
    o->t.a = ((struct B7 *)&s[off + i++])->a;
    o->u = s[off + i];
}
