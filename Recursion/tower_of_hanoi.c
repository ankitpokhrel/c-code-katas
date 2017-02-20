#include <stdio.h>

void tower_of_hanoi(int disk, char from, char aux, char to)
{
    if (disk <= 1) {
        printf("Move disk %d from pole %c to %c\n", disk, from, to);

        return;
    }

    tower_of_hanoi(disk - 1, from, to, aux);
    printf("Move disk %d from pole %c to %c\n", disk, from, to);
    tower_of_hanoi(disk - 1, aux, from, to);
}

int main()
{
    tower_of_hanoi(3, 'A', 'B', 'C');

    return 0;
}
