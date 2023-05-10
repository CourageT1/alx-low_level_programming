#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#include <elf.h>

/**

 * main - displays the information contained in the ELF header

 *        at the start of an ELF file.

 * @argc: the number of arguments.

 * @argv: an array of pointers to the arguments.

 *

 * Return: 0 on success, 98 on failure.

 */

int main(int argc, char **argv)

{

    int fd;

    Elf64_Ehdr header;

    if (argc != 2)

    {

        fprintf(stderr, "Usage: elf_header elf_filename\n");

        return (98);

    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)

    {

        perror("Error: failed to open file");

        return (98);

    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))

    {

        perror("Error: failed to read ELF header from file");

        return (98);

    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||

        header.e_ident[EI_MAG1] != ELFMAG1 ||

        header.e_ident[EI_MAG2] != ELFMAG2 ||

        header.e_ident[EI_MAG3] != ELFMAG3)

    {

        perror("Error: file is not an ELF file");

        return (98);

    }

    printf("Magic:   ");

    printf("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",

           header.e_ident[EI_MAG0], header.e_ident[EI_MAG1],

           header.e_ident[EI_MAG2], header.e_ident[EI_MAG3],

           header.e_ident[EI_CLASS], header.e_ident[EI_DATA],

           header.e_ident[EI_VERSION], header.e_ident[EI_OSABI],

           header.e_ident[EI_ABIVERSION], header.e_ident[EI_PAD],

           header.e_type, header.e_machine, header.e_version,

           header.e_entry, header.e_phoff, header.e_shoff,

           header.e_flags, header.e_ehsize, header.e_phentsize,

           header.e_phnum, header.e_shentsize, header.e_shnum,

           header.e_shstrndx);

    printf("Class:                             %s\n",

           header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");

    printf("Data:                              %s\n",

           header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :

           "2's complement, big endian");

    printf("Version:                           %d (current)\n",

           header.e_ident[EI_VERSION]);

    printf("OS/ABI:                            %s\n",

           header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" :

           "Unknown");

    printf("ABI Version:                       %d\n",

           header.e_ident[EI_ABIVERSION]);

    printf("Type:                              ");

    switch (header.e_type)

    {

    case ET_NONE:

        printf("NONE (No file type)\n");

        break;

    case ET_REL:

        printf("REL (Relocatable file)\n");

        break;

    case ET_EXEC:

        printf("EXEC (Executable file)\n");

        break;

    case ET_DYN:

        printf

