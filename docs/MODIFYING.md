# Modifying the firmware

A mistake in a modified firmware can make the monitor unusable, and in the worst case the monitor can no longer
receive a new firmware. This guide explains why, which changes are safe, and how to build a modified file step by
step.

## Why some mistakes cannot be undone

New firmware reaches the monitor through MSI Gaming Intelligence. The update path only works while the monitor runs
normally:

1. The helper processor (8051) starts first and starts the main processor.
2. The main processor works through its start-up code, shows the logo and enters its main loop.
3. Only the main loop answers MSI's update tool and opens the helper processor's update channel.
4. The helper processor checks that the main processor stays alive. If it stops responding, the helper processor
   switches everything off.

A change that makes the main processor stop **before its main loop** takes the update path down with it. Every
restart runs into the same problem, and the monitor can no longer be updated through MSI's tool.

The firmware offers no way back from this. The boot loader of the helper processor checks nothing and has no
update mode, no key combination and no second copy to fall back on, and the update agent on the USB controller
only writes when the main processor commands it (see the [update path](MAP.md#update-path)). The flash chip of
a monitor whose main processor no longer reaches its main loop has to be written from outside, with a flash programmer (a hardware tool connected to the flash chip on the circuit
board); this repository describes no procedure for that.

A change that only affects the main loop is far less dangerous. In the worst case the picture is wrong, but the
monitor still answers the update tool, and the original firmware can be flashed back.

The [firmware map](MAP.md) has the details of the start-up sequence and the update path.

## Rules for safe changes

These rules are for changes made directly in the firmware file. In the [linked build](LINKING.md) of the two LEON
processors code can grow and move, but it is proven on the PC only. Until a firmware built that way has been tested
on a monitor with a way to recover it, the rules below stand.

| Rule | Why |
|---|---|
| **Change existing values only.** Modify numbers, constants or data inside functions whose source is understood, at their original location. | The surrounding code stays exactly as MSI built it, and the effect of the change can be worked out from the source. |
| **Never add code.** No new code in unused areas of the file, no jumps to new code, no hooks. | Added code can only be reached through a new jump, and a wrong jump fails before anything can be checked. |
| **Stay off the start-up path.** Leave functions that run before the main loop unchanged, unless the change provably gives the same result during start-up. | A fault there makes the monitor unrecoverable (see above). |
| **Keep the no-signal behaviour.** When a changed function also runs at start-up, its result with no input connected must stay exactly the same. | Start-up then follows the original path. |
| **Never touch the boot loader.** 8051 bank 0, the partition table and the slot area (file offsets 0x0000–0x7FFF) stay unchanged. | They decide which firmware the monitor starts. |
| **Use CPU addresses for branches.** If a branch must change, compute it from the CPU address (file offset − 0x108000), not from the number in a Ghidra function name. | The two numberings differ by 0xA0060000. A branch computed from the wrong numbering jumps to an address where no code exists. |
| **Do not read another processor's memory.** | Each processor has its own memory; addresses of one processor mean nothing to another. |

**Menu texts and fonts** are the one part that is changed in the source, not in place: the build of `src/osd/` moves
texts inside the menu area, rewrites the tables that point to them and keeps every address that code or records
outside the area refer to (see [Menu fonts and texts](OSD-TEXT.md#changing-a-text-or-a-glyph)). No firmware file
built that way has been run on a monitor, and whether a changed menu area can disturb start-up has not been examined.

## Building a modified file

Work through every step for every build.

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
- Never interrupt the power while flashing. An update that is cut off leaves the flash partly written, and the boot
  loader starts whatever is there without checking it.

## Example

The two versions in `firmware/custom/` follow these rules. Each changes only the numbers in a few instructions of
the panel mode selection (`SYSAPI_GetPanelParamStruct` (`FUN_a00dac38`)), adds no code, and gives the same result
as the original when no signal is connected. The [firmware overview](../firmware/README.md) describes what they
change and why; the [worked example](EXAMPLE-PANEL-MODE.md) reads the function line by line.
