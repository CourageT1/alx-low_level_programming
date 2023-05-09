#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

typedef struct {

    unsigned char magic[4];
    unsigned char class;
    unsigned char data;
    unsigned char version;
    unsigned char osabi;
    unsigned char abiversion;
    unsigned char pad[7];
    short type;
    short machine;
    int version2;
    unsigned long entry;
    unsigned long phoff;
    unsigned long shoff;
    int flags;
    short ehsize;
    short phentsize;
    short phnum;
    short shentsize;
    short shnum;
    short shstrndx;

} Elf64_Ehdr;

void print_error(char *message)

{

    printf("Error: %s\n", message);

    exit(98);

}

void print_elf_header(Elf64_Ehdr *header)

{

    printf("  Magic:   ");

    for (int i = 0; i < 4; i++) {

        printf("%02x ", header->magic[i]);

    }

    printf("\n");

    printf("  Class:                             %s\n", header->class == 1 ? "ELF32" : "ELF64");

    printf("  Data:                              %s\n", header->data == 1 ? "2's complement, little endian" : "2's complement, big endian");

    printf("  Version:                           %d%s\n", header->version, header->version == 1 ? " (current)" : "");

    printf("  OS/ABI:                            %d\n", header->osabi);

    printf("  ABI Version:                       %d\n", header->abiversion);

    printf("  Type:                              %d\n", header->type);

    printf("  Entry point address:               0x%lx\n", header->entry);

}

int main(int argc, char *argv[])

{

    if (argc != 2) {

        print_error("Wrong number of arguments");

    }

    char *filename = argv[1];

    int fd = open(filename, O_RDONLY);

    if (fd == -1) {

        print_error(strerror(errno));

    }

    Elf64_Ehdr header;

    ssize_t num_read = read(fd, &header, sizeof(header));

    if (num_read != sizeof(header)) {

        print_error(strerror(errno));

    }

    if (memcmp(header.magic, "\x7f""ELF", 4) != 0) {

        print_error("Not an ELF file");

    }

    print_elf_header(&header);

    close(fd);

    return 0;

}

