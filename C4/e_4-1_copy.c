#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define COPY_BUFFER 4096

int main(int argc, char *argv[]) {
    int fromFileFD, toFileFD;
    int readNumber;
    char buff[COPY_BUFFER];

    if (argc < 3 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        printf("Usage: copy from-old-file to-new-file.\n");
        exit(EXIT_FAILURE);
    }

    fromFileFD = open(argv[1], O_RDONLY);
    if (fromFileFD == -1) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    toFileFD = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (toFileFD == -1) {
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((readNumber = read(fromFileFD, buff, COPY_BUFFER)) > 0) {
        if (write(toFileFD, buff, readNumber) != readNumber) {
            printf("%s\n", "Write File Failed.");
            exit(EXIT_FAILURE);
        }
    }

    if (readNumber <= -1) {
        perror("Error Reading");
        exit(EXIT_FAILURE);
    }

    close(fromFileFD);
    close(toFileFD);

    return EXIT_SUCCESS;
}
