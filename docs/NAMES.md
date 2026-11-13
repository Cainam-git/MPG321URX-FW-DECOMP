# Function names

Every function of the two LEON programs, of the three 8051 programs and of the Tensilica program has a descriptive name and a short description. This page says where the names are, how they are formed,
what each one rests on, and how the source files use them and are named after them.

## Where the names are

The source file of a function is `src/<section>/<subject>/<name>.c` (`.S` for assembly); the subject is usually the
first word of the name. The index pages below list every function by subject, with a link to its file.

| Place | Contents |
|---|---|
| Index pages: [main processor](names/leon2m.md), [input processor](names/leon2s.md), 8051 [boot loader](names/8051_bank0.md), [main application](names/8051_bank1.md) and [update agent](names/8051_bank2.md), and the [Tensilica program](names/tensilica.md) | The same names as readable tables, grouped by subject. |
| `symbols/<section>.names.json` (`leon2m`, `leon2s`, `8051_bank0`, `8051_bank1`, `8051_bank2`, `tensilica`) | The table: for every function label its name, a one-line description, parameters and return value where recorded, the subject, the basis of the name and the evidence for it, and one sentence in everyday words. |
| The source files in `src/<section>/<subject>/` | Each file is named after its function. The name and description stand at the top of the file's header comment, and the code uses the names (see [Names in the source](#names-in-the-source)). |
| `symbols/defs/<section>/<label>.h` | The side list of each C file: the names it uses, with the label behind each one. |
| `symbols/<section>.files.json` | The path of every source file, by function label (see [File names and folders](#file-names-and-folders)). |
| `symbols/<section>.data.json` | The names of stored data (see [Data names](#data-names)). |

The tables have 3,968 entries for the main processor, 1,702 for the input processor and 768 for
the three 8051 programs. They cover the functions, the toolchain library routines (under their library names) and
the jump tables (named after their function).

The table of the Tensilica program has 301 entries, one for each of its functions. Its entries hold
the name, the description, the subject, the basis and the evidence; the header comment of each function's file
describes the arguments and the return value.

## How a name is formed

Names are lower-case words joined by underscores, starting with the subject and then saying what the function
does: `nvram_write_settings_record`, `irq_mask_sources`, `hdmi_tx_ddc_read`. The subjects are:

| Prefix | Subject | Prefix | Subject |
|---|---|---|---|
| `startup_` | start-up | `panel_` | panel timing, output, power, PWM |
| `trap_`, `irq_` | traps and interrupts | `oled_` | OLED panel care |
| `timer_` | timers and delays | `pq_` | picture: colour, gamma, windows |
| `sys_` | channels, modes, configuration | `hdr_` | HDR |
| `input_` | video inputs | `osd_`, `font_` | on-screen menu and its fonts |
| `hdmi_`, `dp_` | HDMI and DisplayPort | `audio_` | sound |
| `hdcp_` | copy protection | `ldc_` | dimming processor and its hardware block |
| `edid_`, `ddc_` | EDID, DDC/CI and the service tool | `ipc_` | messages between the processors |
| `nvram_`, `flash_` | saved settings, flash memory | `power_`, `fwupd_` | power states, firmware update |
| `gpio_`, `i2c_`, `uart_`, `usb_` | pins and buses | `reg_`, `dbg_`, `lib_` | register access, debug, library |

Further conventions:

- **Original names are kept.** Where the firmware prints the name of its own function in a message, that name is
  used unchanged (`SYSAPI_WriteEEPROM`, `GlobalModeHandler`, `SetBrightness`, `DRV_HDMI21_LMS_To_EQ`). There are
  69 such names in the main processor, 83 in the input processor and 11 in the Tensilica program
  (`LDC_LoadPanel`, `LED_AS3824_Init`, `gpio_switch_mux`). Library routines
  keep their library names (`memcpy`, `vfprintf`).
- **`_api_`** marks a thin function of the layer that the menu and the control logic call; it forwards to the
  function named after it (`osd_api_set_position` forwards to `osd_set_position`).
- **`_user_apply_`** marks a function that applies one menu setting from the settings record.
- **`_copy`** marks a second, byte-identical copy of a function; further copies are numbered (`_copy2`, `_copy3`).
- **A number taken from an address** stands in a name only where nothing else tells two objects apart
  (`fwupd_set_value_08c9`, `data_at_7f9d`).
- **`_partN`** marks piece N of a function that the function table holds in several pieces (the trap code at the
  start of the input processor's program).
- **`_jump_table`** is the jump table of a switch statement of the named function.
- **`_entry`** marks a block of code that the 8051 compiler placed in front of a function and shared between
  several of its calls. Library routines of the 8051 compiler are named `lib_` plus their library name.
- **Names in the 8051 programs are at most 31 characters long**, because that compiler tells identifiers apart by
  their first 32 characters.
- **Numbers in a name** are the firmware's own numbers: a port, a pin, a register or a command
  (`gpio_set_port7_bit1_high`, `ldc_send_cmd_0x33`).

## Basis of a name

Each name records what it rests on. The `evidence` field of its entry names the text, table, caller or data.

| Basis | Meaning | Main processor | Input processor | 8051 programs | Tensilica program |
|---|---|---:|---:|---:|---:|
| proven | The firmware itself states it: a printed text, a menu text, the button table of the menu, a library routine matched byte for byte, a table position, or request and register numbers defined by a public standard (HDMI, DisplayPort, HDCP). | 1,252 | 583 | 379 | 112 |
| derived | Follows from the functions that call it, the functions it calls and the data it uses. | 1,363 | 519 | 273 | 124 |
| descriptive | Says exactly what the function does, but the firmware does not show what for. Typical cases are functions that nothing calls, and small functions that set one pin or one register bit. | 1,353 | 600 | 116 | 65 |

The meaning of a command sent from the main processor to the input processor was taken from the input
processor's own command handler (`ipc_dispatch_command`), which receives it.

## Names in the source

The checking tools build and link every function under its label (`FUN_a00dac38`, `FUN_CODE_151c`), and for the
LEON compiler the name of a symbol can change the generated code. The C files therefore use the names through the
preprocessor. Each file has a side list, `symbols/defs/<section>/<label>.h`, that defines every name the file uses
as the label behind it:

```c
/* Names used in the source of FUN_a00dac38; the label behind each name is what the checking tools link by.
   Written by tools/names/apply.py; the build puts this list in front of the file when it compiles it. */
#define FRCConfigPostFRC              FUN_a0107e44
#define dbg_printf                    FUN_a00df170
/* Stored data. */
#define panel_mode_rows               DAT_00198380
/* End of names. */
```

The source file itself holds only the header comment and the code. Every build step puts the side list in front of
the file, so the preprocessor puts the labels back before anything is compiled and the build stays byte-exact:

- GCC is given `-include symbols/defs/<section>/<label>.h`. A file compiled by hand needs the same (see the
  [build guide](BUILD.md#compiling-one-file-by-hand)).
- Keil C51 has no such option. The scripts write a temporary copy of the file for the compiler and put `#include`
  of the list in front of the copy's first line, so the line numbers in the compiler's messages and listing are
  those of the file.

The side lists are stored in git, so that the build does not depend on running a script first.

Three cases differ:

- A label stays in the code when its name is already used for something else in that file.
- Assembly files list the labels they use in their header instead.
- A function that the code of another program part calls under a second address (`func_0x...` or `FUN_...` with
  that address, see [stored addresses](REFERENCES.md)) is named in the same way: the side list maps the name to the
  spelling the file uses.

### Data names

Stored data is named the same way, from `symbols/<section>.data.json`: a noun that says what the object holds
(`user_settings`, `osd_menu_state`, `ipc_8051_tx_queue`); a field of a documented record carries the record's
name in front (`user_settings_brightness`). The tables have 1,177 entries for the main processor, 608 for the
input processor, 696 for the three 8051 programs and 61 for the Tensilica program, listed in the data index
pages: [main processor](names/leon2m-data.md), [input processor](names/leon2s-data.md), 8051
[boot loader](names/8051_bank0-data.md), [main application](names/8051_bank1-data.md) and
[update agent](names/8051_bank2-data.md), and the [Tensilica program](names/tensilica-data.md).

A data label without a name is one whose purpose the code does not show (mostly hardware registers) or a
printed text; the object keeps its label (`DAT_...`). The principal records are described in
[Data objects](DATA.md).

### Names in the Tensilica program

The Tensilica program is assembly source that is built without a preprocessor. There the names are the real
symbol names: `tools/names/xt_apply.py` renames the labels in all files of `src/tensilica/`, writes the name, the
label and the basis on the first two lines of each function file, and keeps each label in a comment next to its
definition. The bytes of the build do not change (`tools/xtensa_check.py`). A function is found by its address
from line 1 of its file. Data addresses that this program's code writes as plain numbers have names in the table
only.

## File names and folders

Each source file is named after its function and sits in a folder for the function's subject (the `topic` of its
entry in the table, the prefixes listed under [How a name is formed](#how-a-name-is-formed)):
`src/leon2m/panel/SYSAPI_GetPanelParamStruct.c` holds `FUN_a00dac38`. The first line of every file gives the name
and the label. Special cases:

- A file that holds a Keil module of several 8051 functions is named after the function whose label named the
  file.
- Library routines (`.lib` files) are in the `lib` folder of their section.
- Three names are not usable as file names (`.udiv`, `.umul` and `.urem` of the main processor's library); their
  files drop the dot and carry the address of the label as a suffix: `udiv_a0156a6c.lib`. A name that two files of
  a section would share would be treated the same way; no two files share a name.
- The function files of the Tensilica program are `src/tensilica/<subject>/<name>.S`, recorded in
  `symbols/tensilica.files.json`.

All tools find a function's source through `tools/srcpath.py`, which reads `symbols/<section>.files.json` and falls
back to `src/<section>/<label>.<ext>` for a label that has no entry (a newly accepted function, until the layout is
run again).

## Changing names

After a change of names, run in this order:

1. `apply.py` (for the Tensilica program `xt_apply.py`);
2. `layout.py` (for the Tensilica program `xt_layout.py`);
3. `pathrefs.py`;
4. `tools/refs/srclit.py` and `tools/refs/srcclass.py --export`, which make the list of address numbers in the
   source again (they record line numbers; `layout.py` does this when it moved a file);
5. `tools/rebuild.py`.

The scripts:

- `tools/names/apply.py <section>` writes the header lines, the side lists and the names in the code from the
  table, after undoing its own earlier changes, so it can be run again when a name changes. `--check` reports what
  it would change. `--remove` only undoes them and deletes the side lists. `--infile` writes each list into its
  file instead, below the header comment, and deletes the side lists; a later run without `--infile` moves the
  lists out again.
- `tools/names/xt_apply.py` renames the labels of the Tensilica program (see
  [above](#names-in-the-tensilica-program)); `--remove` turns every name back into its label.
- `tools/names/layout.py <section>` moves the files to the places their names give (with `git mv`) and writes
  `symbols/<section>.files.json`; it moves only the files whose place differs, so it can be run again after names
  change. It also rewrites the source paths that `symbols/<section>.json` records in its comments, and makes the
  list of address numbers in the source (`symbols/<section>.srcaddr.json`, which records file paths and line
  numbers) again. `--revert` moves every file back to `src/<section>/<label>.<ext>` and deletes that record.
- `tools/names/xt_layout.py` lays out the function files of the Tensilica program the same way; it also rewrites
  the `.include` lines of `src/tensilica/tensilica.S`, whose order is the address order of the program.
- `tools/names/pathrefs.py` corrects the comments and pages that mention a source file by its former name.
- `tools/names/index.py <section>` writes the index pages.
