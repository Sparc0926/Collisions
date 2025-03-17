#include <Block.h>
#include <stdio.h>

static GLuint vboBlock[_BLOCK_CNT], vaoBlock[_BLOCK_CNT];
static Block block[_BLOCK_CNT];

void BeginBlock(void)
{
    glGenBuffers(_BLOCK_CNT, vboBlock);
    glGenVertexArrays(_BLOCK_CNT, vaoBlock);
}


void AddBlock(int i, char x, char y, char w, char vel_x, char vel_y)
{
    for (int i = 0; i < _BLOCK_CNT; i++) {
        block[i].x = x;
        block[i].y = y;
        block[i].w = w;
        block[i].vel_x = vel_x;
        block[i].vel_y = vel_y;
    }
}

void UpdateBlock(void)
{
    for (int i = 0; i < _BLOCK_CNT; i++) {
        block[i].x += block[i].vel_x;
        block[i].y += block[i].vel_y;
    }
    // Collision detection
    for (int i = 0; i < _BLOCK_CNT; i++) {
        
    }
}

void DrawBlock(void)
{
    for (int i = 0; i < _BLOCK_CNT; i++) {
        unsigned char blockAttrib[8] = {
            block[i].x, block[i].y,
            block[i].x + block[i].w, block[i].y,
            block[i].x, block[i].y + block[i].w,
            block[i].x + block[i].w, block[i].y + block[i].w
        };
        glBindVertexArray(vaoBlock[i]);
        glBindBuffer(GL_ARRAY_BUFFER, vboBlock[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(char) * 8, blockAttrib, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 2, GL_BYTE, GL_TRUE, sizeof(char) * 2, NULL);
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
}

void EndBlock(void)
{
    glDeleteBuffers(_BLOCK_CNT, vboBlock);
    glDeleteVertexArrays(_BLOCK_CNT, vaoBlock);
}
