/* leon2m FUN_a012bc08 @ 0xa012bc08  (hand; -mcpu=v8 -O3 -g)
 *
 * Updates the output timing record of display channel 'id' (0x24-byte records at 0xA802D8DC) and reports it to
 * the small chip.
 *   div (split factor, only for id != 0) from the RAW panel row byte +6 (FUN_a01241fc() = 0xA802E378, the
 *   untransformed copy): 0x20 -> 1, 0x21 -> 2, 0x22 -> 4, 0x23 -> 8, 0x24 -> 1, 0x25 -> 2, anything else -> 1
 *   (two separate if-chains in the code: 0x20..0x23, then 0x24/0x25).
 *   FUN_a012b9a8(ch, &tm) fills a 24-byte timing block tm: eight 16-bit values h0..h7 at +0..+0xE, byte +0x14,
 *   byte +0x15 = bits per colour (set here from row byte +7, 0xA802E37F).
 *   The record is {u8 +0, +1, +2, +3; the same 24-byte timing block at +4; two words at +0x1C/+0x20}.
 *   update != 0: record timing = tm with h0, h2, h4, h5 divided by div (h1, h3, h6, h7, +0x14 copied), +0x15 = bits
 *                per colour, +1 = +2 = FUN_a00fd820(ch); then a copy of the whole record goes to FUN_a013832c(id, &copy).
 *   update == 0: record +0x18 (timing +0x14) = tm byte +0x14, +0x19 = bits per colour, and a 28-byte message
 *                {id, tm byte +0x14, bits per colour, 0...} is sent with FUN_a01370dc(0x51, 0x1C, msg, 0).
 * Row bytes 0x40 and 0x42 both give div 1. The bits-per-colour value and the timing of each output channel are
 * forwarded to the small chip (message 0x51).
 * The receiver is the SMALL CHIP (Leon2S): FUN_a01370dc writes the message with MailBox_Write
 *   (func_0x4008c5f8) to portal 1 (0x9F130100), 8 words at offset 0x80, after reading portal 1; FUN_a013832c sends its
 *   copy as command 0x50 through the same FUN_a01370dc.
 * Callers: no direct 'call 0xa012bc08' in asm/leon2m (reached indirectly).
 * keys:
 *   - the record EMBEDS the timing block type (struct Tm t at +4) and struct Tm has NAMED fields h0..h7: gcc's alias
 *     analysis (nonoverlapping_component_refs_p) then knows that a load of tm.hN and a store to rec.t.hM with N != M
 *     do not overlap, which gives the firmware's load/store order. With an array h[8] or two unrelated struct types
 *     the reads were moved next to each store (91-94.5 %).
 *   - stores in plain field order (h0..h7, +0x14, +0x15), +1/+2 first; else path: +0x14, +0x15, then the message.
 *   - the record copy for FUN_a013832c is written 'local = *(DAT_a802d8dc + id);' (DAT_a802d8dc[id] moves one load:
 *     99.31 %; memcpy(&local, &DAT_a802d8dc[id], sizeof local) also matches).
 *   - the 0x20 case of the first chain is a real 'div = 1' (gcc folds it away, but the compare stays).
 */

struct Tm
{
  unsigned short h0, h1, h2, h3, h4, h5, h6, h7;
  unsigned char pad[4];
  unsigned char b20;
  unsigned char b21;
  unsigned char pad2[2];
};
struct Rec
{
  unsigned char b0;
  unsigned char b1;
  unsigned char b2;
  unsigned char b3;
  struct Tm t;
  unsigned int w1c;
  unsigned int w20;
};
extern struct Rec DAT_a802d8dc[];
extern unsigned char DAT_a802e37f;
extern unsigned char *FUN_a01241fc(void);
extern unsigned char FUN_a00fd820(unsigned char);
extern void FUN_a012b9a8(unsigned char, struct Tm *);
extern void FUN_a013832c(unsigned char, struct Rec *);
extern void FUN_a01370dc(int, int, void *, int);
void FUN_a012bc08(unsigned char ch, unsigned char id, unsigned char update)
{
  struct Tm tm = {0};
  unsigned char msg[0x1c] = {0};
  struct Rec local;
  unsigned char *row = FUN_a01241fc();
  unsigned char r = FUN_a00fd820(ch);
  unsigned char div = 1;
  unsigned char bpc;
  if (id != 0)
  {
    if (row[6] == 0x20) div = 1;
    else if (row[6] == 0x21) div = 2;
    else if (row[6] == 0x22) div = 4;
    else if (row[6] == 0x23) div = 8;
    if (row[6] == 0x24) div = 1;
    else if (row[6] == 0x25) div = 2;
  }
  FUN_a012b9a8(ch, &tm);
  bpc = DAT_a802e37f;
  tm.b21 = bpc;
  if (update)
  {
    DAT_a802d8dc[id].b1 = r;
    DAT_a802d8dc[id].b2 = r;
    DAT_a802d8dc[id].t.h0 = tm.h0 / div;
    DAT_a802d8dc[id].t.h1 = tm.h1;
    DAT_a802d8dc[id].t.h2 = tm.h2 / div;
    DAT_a802d8dc[id].t.h3 = tm.h3;
    DAT_a802d8dc[id].t.h4 = tm.h4 / div;
    DAT_a802d8dc[id].t.h5 = tm.h5 / div;
    DAT_a802d8dc[id].t.h6 = tm.h6;
    DAT_a802d8dc[id].t.h7 = tm.h7;
    DAT_a802d8dc[id].t.b20 = tm.b20;
    DAT_a802d8dc[id].t.b21 = bpc;
    local = *(DAT_a802d8dc + id);
    FUN_a013832c(id, &local);
  }
  else
  {
    DAT_a802d8dc[id].t.b20 = tm.b20;
    DAT_a802d8dc[id].t.b21 = bpc;
    msg[0] = id;
    msg[1] = tm.b20;
    msg[2] = bpc;
    FUN_a01370dc(0x51, 0x1c, msg, 0);
  }
}
