#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_buffer_info(FILE *stream, const char *stream_name) {
    if (stream == NULL) {
        printf("Failed to open %s\n", stream_name);
        return;
    }

    if (stream == stdin) {
        setvbuf(stream, NULL, _IOLBF, 0); // Set to line-buffered
        printf("Stream = %s, line buffered, buffer size = %d\n", stream_name, BUFSIZ);
    } else if (stream == stdout) {
        setvbuf(stream, NULL, _IOLBF, 0); // Set to line-buffered
        printf("Stream = %s, line buffered, buffer size = %d\n", stream_name, BUFSIZ);
    } else if (stream == stderr) {
        setvbuf(stream, NULL, _IONBF, 0); // Set to unbuffered
        printf("Stream = %s, unbuffered, buffer size = 0\n", stream_name);
    } else {
        // For file streams
        setvbuf(stream, NULL, _IOFBF, 0); // Set to fully buffered
        printf("Stream = %s, fully buffered, buffer size = %d\n", stream_name, BUFSIZ);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [stdin|stdout|stderr|file]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "stdin") == 0) {
        printf("Enter text: ");
        print_buffer_info(stdin, "stdin");
    } else if (strcmp(argv[1], "stdout") == 0) {
        print_buffer_info(stdout, "stdout");
    } else if (strcmp(argv[1], "stderr") == 0) {
        print_buffer_info(stderr, "stderr");
    } else {
        // Handle file input
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Failed to open file");
            return 1;
        }
        print_buffer_info(file, argv[1]);
        fclose(file);
    }

    return 0;
}

