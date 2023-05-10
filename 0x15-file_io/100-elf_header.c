#include <stdio.h>

#include <stdlib.h>

#include <elf.h>

#include <fcntl.h>

#include <unistd.h>

/**

 * print_error_and_exit - prints error message and exits program

 * @message: error message to print

 */

void print_error_and_exit(char *message)

{

	fprintf(stderr, "%s\n", message);	exit(1);

}

/**

 * main - displays the information contained in the ELF header of an ELF file

 * @argc: the number of command-line arguments

 * @argv: an array of command-line arguments

 *

 * Return: 0 on success, otherwise 1

 */

int main(int argc, char *argv[])

{

	int fd, i;

	Elf64_Ehdr header;

	if (argc != 2)

		print_error_and_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)

		print_error_and_exit("Error: could not open ELF file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))

		print_error_and_exit("Error: could not read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||

	    header.e_ident[EI_MAG1] != ELFMAG1 ||

	    header.e_ident[EI_MAG2] != ELFMAG2 ||

	    header.e_ident[EI_MAG3] != ELFMAG3)

		print_error_and_exit("Error: file is not an ELF file");

	printf("ELF Header:\n");

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)

		printf("%02x ", header.e_ident[i]);

	printf("\n");

	printf("  Class:                             %s\n",

	       header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");

	printf("  Data:                              %s\n",

	       header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :

	       (header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown"));

	printf("  Version:                           %d%s\n",

	       header.e_ident[EI_VERSION],

	       header.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");

	printf("  OS/ABI:                            ");

	switch (header.e_ident[EI_OSABI])

	{

		case ELFOSABI_SYSV:

			printf("UNIX - System V\n");

			break;

		case ELFOSABI_HPUX:

			printf("UNIX - HP-UX\n");

			break;

		case ELFOSABI_NETBSD:

			printf("UNIX - NetBSD\n");

			break;

		case ELFOSABI_LINUX:

			printf("UNIX - Linux\n");

			break;

		case ELFOSABI_SOLARIS:

			printf("UNIX - Solaris\n");

			break;

		case ELFOSABI_IRIX:

			printf("UNIX - IRIX\n");

			break;

		case ELFOSABI_FREEBSD:

			printf("UNIX - FreeBSD\n");

			break;

		case ELFOSABI_TRU64:

			printf("UNIX - TRU64\n");

			break;

		case ELFOSABI_ARM:

			printf("ARM\n");

			break;

		case ELFOSABI_STANDALONE:

			printf("Standalone App\n");

			break;

		default:

			printf("<unknown: %x>\n", header.e_identEI_OSABI);

			break;

}
printf("ABI Version: %d\n", header.e);
