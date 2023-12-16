#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_command(char *input);
ssize_t custom_getline(char **line, size_t *n, FILE *stream);
#endif /* MAIN_H */
