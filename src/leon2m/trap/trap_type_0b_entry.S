! trap_type_0b_entry  (FUN_a00280b0)
!
! Trap table slot 0x0b (type 0b): reads %psr and %tbr and jumps to the handler at 0xa0029220.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a00280b0 @ 0xa00280b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00280b0
	.type FUN_a00280b0, #function
FUN_a00280b0:
! Slot of trap type 0x0B, watchpoint_detected. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! trap_handle_faults at 0xA0029220, which runs a copy of the trapped instruction
! from RAM 0xA8027B9C and then goes on at the old nPC.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029000), %l4       ! upper bits of the handler address 0xA0029220
	jmp  %l4 + 0x220                  ! jump to 0xA0029220: run the trapped instruction from RAM
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a00280b0, .-FUN_a00280b0
