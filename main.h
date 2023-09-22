#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;
extern int child_exit_status;

char *isCommand(char *command);
char **split_line(char *line, int bufsize);

int _strcmp(char *str1, char *str2);
int _strcmpn(char *str1, char *str2, int len);
int _isInt(char *str);
int _strToInt(char *str);

char *_strcpy(char *src);
char *_strcon(char *str1, char *str2);
char *_intToStr(int n);

void _exitFromShell(char **args, char *line, char **argv);
void _perror(int error_num, ...);
void _puts(int n, ...);
void _cd(char **args, char *line, char **argv, char *commNum);

#endif
