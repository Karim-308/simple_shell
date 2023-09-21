#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>

char *isCommand(char *);

char **split_line(char *line, int bufsize);

int _strcmp(char *, char *);

int _strcmpn(char *, char *, int);

char *_strcpy(char *);

char *_strcon(char *, char *);

int _isInt(char *);

int _strToInt(char *);

void _exitFromShell(char **, char *, char **);

void _perror(int, ...);

char *_intToStr(int n);

#endif

