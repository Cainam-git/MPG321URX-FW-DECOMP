/* leon2m FUN_a013497c @ 0xa013497c-0xa0134de0 (1124 bytes, 281 insns)  BYTE-EXACT
 * Flags: -mcpu=v8 -O3 -g (also -mcpu=v8 -O3 -g -msoft-float): jf 100 match=True, rawcmp 0/281 mismatches (both).
 *
 * What it does: decodes one 5-word message from mailbox portal 0 (the 8051; called by the slot poll
 * FUN_a0134de0). Word 0: bits 0-3 type, bits 4-7 flags (bit 0 = last part), bits 8-15 port,
 * bits 16-23 byte count (clamped to 16), bits 24-31 part index. Words 1-4 are unpacked big-endian into a zeroed
 * 16-byte local. Types: 1 = EDID part -> 0x7FF-byte buffer 0xA802DE40 at part*16 (range check off + len <= 0x7fe,
 * else debug "EDID address out of range! %d"; debug "EDID%d" + one "%x " per byte), last part -> DAT_a802cb8e =
 * total, DAT_a802cb8f = 1; 2 = I2C part -> same buffer, last part -> debug "I2C%x" port, DAT_a802cb92 = total,
 * DAT_a802cb93 = 1; 3 = UART bytes -> receive ring DAT_a802dd90[port] (port <= 4 else "UART buf index over!"),
 * overflow flag set when the next write index equals the read index; 4 = block into the struct at 0xA802D9C6
 * (data at +4 + part*16; last part -> port (+0), len (u16 at +2) = total, ready (+0x84) = 1); 5 = IR bytes ->
 * 64-byte buffer 0xA802DD50 at count DAT_a802cb94 (u16, stops at 0x40), debug dump "IR%x " / "%x " / "%x\r\n".
 * Type 0 and types > 5 do nothing. Input: msg = pointer to the 5 words. Output: none.
 *
 * Match facts: (1) source order of the prologue: 'len' extraction first, then flags, type, port, idx (idx
 *   last = its srl kills w0, register weight 0 in sched1), and only THEN the block with 'data[16] = {0}'; with the
 *   init before the extractions sched1 keeps the second zero store early, the DImode zero pair outranks the
 *   len/flags temps in local-alloc and takes %o4/%o5 (fw %o2/%o3). (2) TWO count variables: 'len' (u8) is clamped in
 *   place and used by the loops and the case-1 range check (fw %l0), 'cnt = len' is an unsigned short used for the
 *   unpack call and the totals (fw %l3, zero-extended; 'off + cnt' keeps off first). (3) case 2 computes the total
 *   into an unsigned char temp BEFORE the debug print (fw add in the bne delay slot after the call). (4) case 4
 *   writes 'cnt + off' and stores port, len, ready in that order. (5) case 1 is if (in range) { ... } else { error }
 *   (if/else arm order sets the rename ticks; the early-break form leaves the error string HIGH in %l0, fw %l5).
 * Further forms: off = idx * 16 is unsigned short ('and 0xff0'); the unpack loop is an inlined static
 *   function with an unsigned short count; case 3 'next' is unsigned int.
 * Compiler aids (no code): case 3 compares '(int)next == rd' - fold puts a bare variable second, the cast keeps the
 *   firmware operand order 'cmp next, rd'; the value is <= 0x1f, an equality test, so the cast changes nothing.
 * Callees: FUN_a00dd614(level) debug-level test returning unsigned char; FUN_a00df170 = debug printf (int, K&R).
 */
struct UartRing { unsigned char wr, rd, data[32], ovf; };
struct Msg4 { unsigned char port, pad; unsigned short len; unsigned char data[0x80]; unsigned char ready; };
extern struct UartRing DAT_a802dd90[];
extern struct Msg4 DAT_a802d9c6;
extern unsigned char DAT_a802de40[];
extern unsigned char DAT_a802dd50[];
extern unsigned short DAT_a802cb94;
extern unsigned char DAT_a802cb8e, DAT_a802cb8f, DAT_a802cb92, DAT_a802cb93;
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170();
extern char s_001a53e0[];
extern const char s_001a54b0[], s_001a54b8[], s_001a54c0[], s_001a54d0[], s_001a54f0[], s_001a5508[];

static void unpack(unsigned char *dst, unsigned int *src, unsigned short len)
{
    unsigned char i;
    unsigned char n = (len + 3) / 4;
    for (i = 0; i < n; i++) {
        dst[i * 4] = src[i] >> 24;
        dst[i * 4 + 1] = src[i] >> 16;
        dst[i * 4 + 2] = src[i] >> 8;
        dst[i * 4 + 3] = src[i];
    }
}

void FUN_a013497c(unsigned int *msg)
{
    unsigned int w0;
    unsigned char type, flags, port, len, idx, i;
    unsigned int next;
    unsigned short off; unsigned short cnt;

    w0 = msg[0];
    len = w0 >> 16;
    flags = (w0 >> 4) & 0xf;
    type = w0 & 0xf;
    port = w0 >> 8;
    idx = w0 >> 24;
    {
    unsigned char data[16] = {0};
    if (len > 16) len = 16;
    cnt = len;
    unpack(data, &msg[1], cnt);
    off = idx * 16;
    switch (type) {
    case 0:
        break;
    case 1:
        if (off + len <= 0x7fe) {
            if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a54c0, 1);
            for (i = 0; i < len; i++) {
                DAT_a802de40[off + i] = data[i];
                if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a54b8, data[i]);
            }
            if (flags & 1) {
                DAT_a802cb8e = off + cnt;
                DAT_a802cb8f = 1;
            }
        } else {
            if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a54d0, 1);
        }
        break;
    case 2:
        for (i = 0; i < len; i++)
            DAT_a802de40[off + i] = data[i];
        if (flags & 1) {
            unsigned char tot = off + cnt;
            if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a54f0, port);
            DAT_a802cb92 = tot;
            DAT_a802cb93 = 1;
        }
        break;
    case 3:
        if (port > 4) {
            FUN_a00df170(s_001a53e0);
            break;
        }
        for (i = 0; i < len; i++) {
            DAT_a802dd90[port].data[DAT_a802dd90[port].wr] = data[i];
            next = (DAT_a802dd90[port].wr + 1) & 0x1f;
            if ((int)next == DAT_a802dd90[port].rd) DAT_a802dd90[port].ovf = 1;
            DAT_a802dd90[port].wr = next;
        }
        break;
    case 4:
        for (i = 0; i < len; i++)
            DAT_a802d9c6.data[off + i] = data[i];
        if (flags & 1) {
            DAT_a802d9c6.port = port;
            DAT_a802d9c6.len = cnt + off;
            DAT_a802d9c6.ready = 1;
        }
        break;
    case 5:
        for (i = 0; i < len; i++) {
            if (DAT_a802cb94 > 0x3f) break;
            DAT_a802dd50[DAT_a802cb94] = data[i];
            DAT_a802cb94++;
        }
        if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a54b0, 0);
        for (i = 0; i < len; i++)
            if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a54b8, data[i]);
        if (FUN_a00dd614(0x20)) FUN_a00df170(s_001a5508, 1);
        break;
    }
    }
}
