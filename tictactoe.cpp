#include <stdio.h>

int p1, p2, i, choice, check;
char move = 'O';

int turn[9] = {1, 2, 1, 2, 1, 2, 1, 2, 1};
char bd[9] = {32, 32, 32, 32, 32, 32, 32, 32, 32};

int main()
{

    printf("\n=== Welcome to Tic Tac Toe. ===\n");
    printf("\n");
    printf("\nHere are some quick Instructions.");
    printf("\n");
    printf("\t1. Player 1 is \"X\" and Player 2 is \"O\"");
    printf("\n");
    printf("\t2. The board is configured like so:");
    printf("\n");
    printf("\n\t\t 7 | 8 | 9\n\t\t--- --- ---\n\t\t 4 | 5 | 6\n\t\t--- --- ---\n\t\t 1 | 2 | 3");
    printf("\n");
    printf("\nSo Lets Start.");

    for (i = 0; i <= 8; i++)
    {

    re_move:

        printf("\n\n %c | %c | %c\n--- --- ---\n %c | %c | %c\n--- --- ---\n %c | %c | %c", bd[6], bd[7], bd[8], bd[3], bd[4], bd[5], bd[0], bd[1], bd[2]);
        printf("\n");

        check = i % 2;

        if (check == 0)
        {
            move = 'X';
        }

        printf("Player %d's turn. (%c)\n", turn[i], move);
        scanf("%d", &choice);
        printf("\n");

        if (bd[choice - 1] == 32)
        {

            printf("====================");
            bd[choice - 1] = move;

            if (bd[6] != 32 && (bd[6] == bd[7] && bd[7] == bd[8]))
            {

                printf("\n\n======%c Wins======\n", move);
                break;
            }

            if (bd[3] != 32 && (bd[3] == bd[4] && bd[4] == bd[5]))
            {

                printf("\n\n======%c Wins======\n", move);
                break;
            }

            if (bd[0] != 32 && (bd[0] == bd[1] && bd[1] == bd[2]))
            {

                printf("\n\n======%c Wins======\n", move);
                break;
            }

            if (bd[6] != 32 && (bd[6] == bd[3] && bd[3] == bd[0]))
            {

                printf("\n\n======%c Wins======\n", move);
                break;
            }

            if (bd[7] != 32 && (bd[7] == bd[4] && bd[4] == bd[1]))
            {

                printf("\n\n======%c Wins======\n", move);
                break;
            }

            if (bd[8] != 32 && (bd[8] == bd[6] && bd[6] == bd[2]))
            {

                printf("\n\n======%c Wins======\n", move);
                break;
            }

            if (bd[6] != 32 && (bd[6] == bd[4] && bd[4] == bd[2]))
            {

                printf("\n\n======%c Wins======\n", move);
                break;
            }

            if (bd[8] != 32 && (bd[8] == bd[4] && bd[4] == bd[0]))
            {

                printf("\n\n======%c Wins======\n", move);
                break;
            }

            move = 'O';
        }

        else
        {

            printf("\n\nThis place is alredy played. Please choose another move to play.\n");
            goto re_move;
        }
    }

    printf("\n %c | %c | %c\n--- --- ---\n %c | %c | %c\n--- --- ---\n %c | %c | %c", bd[6], bd[7], bd[8], bd[3], bd[4], bd[5], bd[0], bd[1], bd[2]);
    printf("\n====================");
    return 0;
}
