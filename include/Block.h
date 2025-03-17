#ifndef BLOCK_H
#define BLOCK_H

#include <glew.h>

#define _BLOCK_CNT 1

typedef struct Block Block;

struct Block {
    char x, y, w;
    float mass, vel_x, vel_y;
};

void BeginBlock(void);

void AddBlock(int i, char x, char y, char w, char vel_x, char vel_y);
void DrawBlock(void);
void UpdateBlock(void);

void EndBlock(void);

#endif//BLOCK_H