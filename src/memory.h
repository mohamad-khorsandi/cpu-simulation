#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED
void load_to_mem(char*);
void show_mem();
long mem_access(int index);

int mem_sz;
long* mem;
#endif // LOADER_H_INCLUDED
