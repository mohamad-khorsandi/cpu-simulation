#ifndef REGISTER_FILE_H_INCLUDED
#define REGISTER_FILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int get_regiter(int index);
void write_to_rf(long data, int index);
void show_rf();
#endif // REGISTER_FILE_H_INCLUDED
