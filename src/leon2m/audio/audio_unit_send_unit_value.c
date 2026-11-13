/* audio_unit_send_unit_value  (FUN_a014f374)
 *
 * Send a 16-bit value for the unit an id holds, if it holds one.
 * Name basis: descriptive - mailbox command 0x93 (unit index, value); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014f374, flags -mcpu=v8 -O2 -g.
 * Source form: the search (the same as audio_unit_find_unit) is a static helper inlined here; the send is a tail
 * call.
 */
/* The four 4-bit fields of audio_unit_owners (lowest first) hold the sound source assigned to each audio unit. */
#define AUDIO_UNIT_COUNT 4
extern unsigned short audio_unit_owners;
extern void ipc_set_audio_unit_frequency(unsigned char, unsigned short);

/* Return the index of the first unit that holds the sound source, or AUDIO_UNIT_COUNT when none does. */
static unsigned char find_unit(unsigned char source)
{
    unsigned char unit_index;
    for (unit_index = 0; unit_index < AUDIO_UNIT_COUNT; unit_index++)
        if (((audio_unit_owners >> (unit_index * 4)) & 0xf) == source)
            break;
    return unit_index;
}

/*
 * Send a frequency word to the audio unit that holds a sound source (mailbox command 0x93, through
 * ipc_set_audio_unit_frequency). Nothing is sent when the source holds no unit.
 *
 *   source     the sound source id to look for
 *   frequency  the frequency word for that unit
 */
void audio_unit_send_unit_value(unsigned char source, unsigned short frequency)
{
    unsigned char unit_index = find_unit(source);
    if (unit_index < AUDIO_UNIT_COUNT)
        ipc_set_audio_unit_frequency(unit_index, frequency);
}
