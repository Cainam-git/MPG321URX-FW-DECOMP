# Modifying the firmware

The decompiled source makes it possible to change the firmware with a full understanding of what the change does.
A mistake can still make the monitor unusable, though, and in the worst case it can no longer receive a new
firmware. This guide explains why, which changes are safe, and how to build a modified file step by step.

## Why some mistakes cannot be undone

New firmware reaches the monitor through MSI Gaming Intelligence. The update path only works while the monitor runs
normally:

1. The helper processor (8051) starts first and starts the main processor.
2. The main processor works through its start-up code, shows the logo and enters its main loop.
3. Only the main loop answers MSI's update tool and opens the helper processor's update channel.
4. The helper processor checks that the main processor stays alive. If it stops responding, the helper processor
   switches everything off.

A change that makes the main processor stop **before its main loop** therefore takes the update path down with it.
Every restart runs into the same problem, and the monitor can no longer be updated over USB.

A change that only affects the main loop is far less dangerous. In the worst case the picture is wrong, but the
monitor still answers the update tool, and the original firmware can be flashed back.

The details of the start-up sequence and the update path are in the [firmware map](MAP.md).

## Rules for safe changes

| Rule | Why |
|---|---|
| **Change existing values only.** Modify numbers, constants or data inside functions that are matched and understood, at their original location. | The surrounding code stays exactly as MSI built it, and the effect of the change can be worked out from the source. |
| **Never add code.** No new code in unused areas of the file, no jumps to new code, no hooks. | Added code can only be reached through a new jump, and a wrong jump fails before anything can be checked. |
| **Stay off the start-up path.** Leave functions that run before the main loop unchanged, unless the change provably gives the same result during start-up. | A fault there makes the monitor unrecoverable (see above). |
| **Keep the no-signal behaviour.** When a changed function also runs at start-up, its result with no input connected must stay exactly the same. | Start-up then follows the original path. |
| **Never touch the boot loader.** 8051 bank 0, the partition table and the slot area (file offsets 0x0000–0x7FFF) stay unchanged. | They decide which firmware the monitor starts. |
| **Use CPU addresses for branches.** If a branch must change, compute it from the CPU address (file offset − 0x108000), not from the number in a Ghidra function name. | The two numberings differ by 0xA0060000. A branch computed from the wrong numbering jumps to an address where no code exists. |
| **Do not read another processor's memory.** | Each processor has its own memory; addresses of one processor mean nothing to another. |

## Building a modified file

Work through every step for every build. Each one is quick, and together they catch the mistakes that matter.

1. **Start from the official file.** Use an unmodified copy of `firmware/MSI_MPG321URX_V021_7F69.bin`, and check its
   size (2,820,096 bytes) and SHA-256 (see the [firmware overview](../firmware/README.md)).
2. **Check before changing.** Confirm that every byte you are about to change still has its original value.
3. **Compare the whole file.** Afterwards, exactly the planned bytes must differ, and nothing else.
4. **Check the protected areas.** Confirm that the boot loader, partition table and slot area (0x0000–0x7FFF) and the
   start-up functions are byte-identical to the original.
5. **Read the result back.** Disassemble the changed function from both files. Only the intended instructions may
   differ, and every jump target must be the same.
6. **Work out the behaviour.** For every case that matters, including the no-signal case, work out from the changed
   instructions what the function now does, and compare it with the original.
7. **Name the file.** MSI's tool expects `MSI_MPG321URX_V021_XXXX.bin`, where `XXXX` is the 16-bit sum of all bytes
   in the file, in uppercase hexadecimal. Compute it from the finished file.
8. **Get a second check.** Have someone (or a separate tool) repeat steps 1 to 7 from the files alone. If the results
   differ in any way, stop.

## Flashing and recovery

- MSI Gaming Intelligence has accepted every modified file that was named this way. It refuses versions it considers
  too old, such as FW.016.
- Keep the official FW.021 file at hand. If a change gives a wrong or black picture but the monitor still responds,
  disconnect the video source, restart the monitor and flash the official file again.
- Never interrupt the power while flashing.

## Example

The two versions in `firmware/custom/` follow these rules. Each changes only the numbers in a few instructions of
the panel mode selection (`FUN_a00dac38`). It adds no code, and its result with no signal connected is identical to
the original. The [firmware overview](../firmware/README.md) describes what they change and why.
