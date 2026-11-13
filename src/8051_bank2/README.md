# 8051 update agent (bank 2): the source folders

The source of this program: 158 files, one per function (a few files hold a Keil module of several functions), each named after its function and sorted into a folder for its subject. The first line of every file gives the function's name and its label (its address in the firmware).

| Folder | Subject | Files |
|---|---|---:|
| [`timer/`](timer/) | [Timers and delays](../../docs/names/8051_bank2.md#timer) | 2 |
| [`sys/`](sys/) | [System control: channels, modes, configuration](../../docs/names/8051_bank2.md#sys) | 2 |
| [`flash/`](flash/) | [Flash memory](../../docs/names/8051_bank2.md#flash) | 3 |
| [`fwupd/`](fwupd/) | [Firmware update](../../docs/names/8051_bank2.md#fwupd) | 52 |
| [`i2c/`](i2c/) | [I2C](../../docs/names/8051_bank2.md#i2c) | 7 |
| [`uart/`](uart/) | [Serial ports](../../docs/names/8051_bank2.md#uart) | 1 |
| [`usb/`](usb/) | [USB](../../docs/names/8051_bank2.md#usb) | 17 |
| [`reg/`](reg/) | [Register access](../../docs/names/8051_bank2.md#reg) | 3 |
| [`dbg/`](dbg/) | [Debug facilities](../../docs/names/8051_bank2.md#dbg) | 1 |
| [`lib/`](lib/) | [Library routines](../../docs/names/8051_bank2.md#lib) | 70 |

The [index page](../../docs/names/8051_bank2.md) lists every function of the program with a one-line description (285 entries, with the jump tables, library members and entry points that have no file of their own); the subject in the table above links to its part of that page. [Function names](../../docs/NAMES.md) describes how the names were given, and [How the firmware works: a guided tour](../../docs/TOUR.md) says what the programs do.
