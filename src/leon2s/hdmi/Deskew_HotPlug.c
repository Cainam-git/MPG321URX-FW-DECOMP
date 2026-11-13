/* Deskew_HotPlug  (Deskew_HotPlug)
 *
 * Request a hot-plug toggle of a port after a deskew failure.
 *   phyidx: PHY 0..3
 * Name basis: proven - original name printed: 'Deskew_HotPlug Toggle Phyidx(%d)'; sets bit phyidx of a request
 *   byte
 *
 * Matching notes
 * --------------
 * leon2s Deskew_HotPlug @ 0xa0077e7c, flags -mcpu=v8 -Os.
 * Source form: a switch on the masked phyidx; the print format is the data object DAT_a0067400.
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned char input_port_event_flags;
extern const char DAT_a0067400[];

/* Prints "Deskew_HotPlug Toggle Phyidx(%d)" and sets bit phyidx of input_port_event_flags for PHY 0..3;
 * any other value sets nothing.
 *   phyidx: PHY 0..3 */
void Deskew_HotPlug(int phyidx)
{
    phyidx &= 0xff;
    dbg_printf(DAT_a0067400, phyidx);
    switch (phyidx) {
        case 0: input_port_event_flags |= 1; break;
        case 1: input_port_event_flags |= 2; break;
        case 2: input_port_event_flags |= 4; break;
        case 3: input_port_event_flags |= 8; break;
    }
}
