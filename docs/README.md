# Documentation

The pages, grouped by what you want to do. Start with the [guided tour](TOUR.md).

## Understand the firmware

| Page | What it covers |
|---|---|
| [How the firmware works: a guided tour](TOUR.md) | **Start here.** What each processor's program does, from switching on to the picture, the menu, the settings and a firmware update, with the functions worth reading first. |
| [A worked example: the panel mode selection](EXAMPLE-PANEL-MODE.md) | One function read from top to bottom: how the panel's 240, 120 or 60 Hz mode is chosen, and what the two custom firmware files change. |
| [Firmware map](MAP.md) | How the firmware file is laid out, address numbering, the start-up sequence, the update path and the panel modes. |

## Look something up

| Page | What it covers |
|---|---|
| [Function names](NAMES.md) | What a function does: where the names are, how they were given and what each one rests on; with an index per program. |
| [Data objects](DATA.md) | The principal records and tables in memory, with their addresses and what they hold. The index pages of all named data are linked from [Function names](NAMES.md#data-names). |
| [Record fields](RECORDS.md) | The named fields of the settings records and the other principal records, by offset. |
| [Mailbox commands](MAILBOX.md) | The commands and messages between the main processor, the 8051 and the input processor, with the function that sends it and the function that carries it out. |
| [Stored addresses](REFERENCES.md) | Every stored address in the firmware file, how the list was made and checked, and the code found outside the function table. |
| [Glossary](GLOSSARY.md) | The project's terms, in plain words. |
| [Tools](../tools/README.md) | Every script. |

## Rebuild and verify

| Page | What it covers |
|---|---|
| [Build guide](BUILD.md) | Setting up the toolchains, rebuilding the firmware file, and checking, accepting and verifying functions. |
| [Workflow guide](WORKFLOW.md) | The matching method, where the source of a function comes from, how to read a source file and the [rules the source follows](WORKFLOW.md#rules-the-source-follows). |
| [Status report](STATUS.md) | Numbers per processor, how "matched" is defined, how each kind of entry is verified, reconstructed statements and remaining work. |
| [Matching guide](MATCHING-TRICKS.md) | Source forms that decide what GCC 3.4.4 and Keil C51 generate. |
| [Toolchains](TOOLCHAINS.md) | How the original compilers and their options were identified. |
| [Linked build](LINKING.md) | The programs of the two LEON processors as linked programs in which code and data can move, and the two proofs for it. |

## Change something

| Page | What it covers |
|---|---|
| [Modifying the firmware](MODIFYING.md) | Which changes are safe, and how to build and check a modified file. |
| [Menu fonts and texts](OSD-TEXT.md) | How the menu's fonts and texts are stored, the editable source in `src/osd/`, and how to change a text or a glyph. |
| [Firmware overview](../firmware/README.md) | The official firmware files, the two custom files and what they change, and the checksums. |
