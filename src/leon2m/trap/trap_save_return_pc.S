! trap_save_return_pc  (FUN_a0029054)
!
! Copy the trapped PC/nPC to %l5/%l6 and fall into the halt path that follows.
! Note: No trap slot or code jumps here; it is the entry of the unreferenced halt path.
! Name basis: descriptive - code only; no references in the image
!
! Matching notes
! --------------
! leon2m FUN_a0029054 @ 0xa0029054  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0029054
	.type FUN_a0029054, #function
FUN_a0029054:
! Unreached: no trap-table slot, call or stored word points at 0xA0029054. Written as the start of a trap
! handler: it keeps the trapped PC and nPC and steps back to the trapped window, then falls into
! trap_enter_halt_loop (0xA0029060), which re-enters the trap window and calls the endless loop.
	mov  %l1, %l5                     ! keep the trapped PC in %l5
	mov  %l2, %l6                     ! keep the trapped nPC in %l6
	restore                           ! step back to the trapped window; trap_enter_halt_loop follows
	.size FUN_a0029054, .-FUN_a0029054
