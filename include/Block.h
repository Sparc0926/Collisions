#ifndef BLOCK_H
#define BLOCK_H

#include <glew.h>

#define _BLOCK_CNT 1

typedef struct Block Block;

struct Block {
    char x, y, w;
    float mass, vel_x, vel_y;
};

void begin_block(void);

void add_block(int i, char x, char y, char w, char vel_x, char vel_y);
void draw_block(void);
void update_block(void);

void end_block(void);

#endif//BLOCK_H