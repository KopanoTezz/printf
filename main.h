#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS (1 << 0)
#define F_PLUS (1 << 1)
#define F_ZERO (1 << 2)
#define F_HASH (1 << 3)
#define F_SPACE (1 << 4)

#define S_LONG 1
#define S_SHORT 2

int get_flags(const char *format, int *k);
int get_precision(const char *format, int *k, va_list list);
int get_size(const char *format, int *k);
int get_width(const char *format, int *k, va_list list);

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);
void print_buffer(char buffer[], int *buff_ind);

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types);
int print_string(va_list types);

int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
