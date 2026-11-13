/* audio_unit_send_owner_slots  (FUN_a014eba4)
 *
 * Send one command for every slot that belongs to an owner.
 * Name basis: descriptive - mailbox command 0x92 (owner, slot, value, 1) per matching slot; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014eba4 @ 0xa014eba4, flags -mcpu=v8 -O3 -g (also exact with -msoft-float).
 * Source form the exact build depends on: the table read goes through 'static inline get(n)', an inlined
 * accessor with no code of its own. With a direct 'owner == audio_slot_owners[i]' the compiler emits the compare
 * operands in the other order than the firmware and the loop shape shifts; the accessor's return conversion
 * gives the firmware order. The callee is declared with its real prototype: void, four unsigned char
 * parameters (see ipc_route_audio_source).
 */
extern unsigned char audio_slot_owners[];
extern void ipc_route_audio_source(unsigned char, unsigned char, unsigned char, unsigned char);
static inline unsigned char get(unsigned char n) { return audio_slot_owners[n]; }

/*
 * For every audio output slot (0..8) owned by the source "owner", ask the input processor to route that
 * source to the slot: ipc_route_audio_source(owner, slot, value, 1). "value" is passed on unchanged.
 * Nothing calls it.
 */
void audio_unit_send_owner_slots(unsigned char owner, unsigned char value)
{
  unsigned char slot;
  for (slot = 0; slot <= 8; slot++)
    if (owner == get(slot))
      ipc_route_audio_source(owner, slot, value, 1);
}
