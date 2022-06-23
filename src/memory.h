#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED
void load_to_mem(char*);
void show_mem();
long im_access(int index);
long dm_access(int index);
void write_to_mem(long data, int index);

#endif // LOADER_H_INCLUDED
