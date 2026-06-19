CC := gcc -m32 -ffreestanding -fno-stack-protector -fno-pie
LD := ld -m elf_i386
NASM := nasm
QEMU := qemu-system-i386

CFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra

# gera iso final
all: azulo.iso

# obj do boot
Binaries/boot.o: Bootloader/bootload.nasm
	mkdir -p Binaries
	$(NASM) -f elf32 $< -o $@

# obj do kernel
Binaries/kernel.o: Kernel/krnl.c
	mkdir -p Binaries
	$(CC) -c $< -o $@ $(CFLAGS)

# linka tudo pra gerar o bin do os
Binaries/azulo.bin: Binaries/boot.o Binaries/kernel.o Linker/linker.ld
	$(LD) -T Linker/linker.ld -o $@ -nostdlib Binaries/boot.o Binaries/kernel.o

# monta estrutura e cria iso com grub
azulo.iso: Binaries/azulo.bin
	mkdir -p Iso/Boot/Grub
	cp Binaries/azulo.bin Iso/Boot/azulo.bin
	grub-mkrescue -o azulo.iso Iso

# so rodar no qemu
run: azulo.iso
	$(QEMU) -cdrom azulo.iso

# limpa o lixo
clean:
	rm -rf Binaries azulo.iso

.PHONY: all run clean
