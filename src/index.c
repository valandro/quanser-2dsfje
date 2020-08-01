#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <galileo2io.h>
#include <utils.h>

int main(int argc, char *argv[])
{

    // Verifica se a placa em questao e Galileo Gen2
    if (board_name() != BOARD_GALILEO_GEN2)
    {
        perror("Unsupported device\n");
        return -1;
    }
}