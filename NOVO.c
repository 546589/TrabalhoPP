/*
    Cria um jogo similar ao Batalha Naval. Nesse jogo, uma frota está escondida no oceano,
    portanto, você não consegue perceber onde estão as naves que compõem a frota. O objetivo
    do jogo é você destruir a frota, isto é, afundar todas as naves com a quantidade de torpedos
    disponível.

    por Jhully Vitoria, 2021
    por Pedro Pinel, 2021
    por Luis Arthur, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MD = 1; // Selecionador de modo PLAY(0) / CORR(1)


void
initOcean(char ocean[6][6])
{
    int i = 0;
    int j = 0;


    for(i=1;i<=5;i++)
        {
        for(j=1;j<=5;j++)
            {
            ocean[i][j] = ' ';

            }
        }
    ocean[0][0] = ' ';

    ocean[1][0] = 'A';
    ocean[2][0] = 'B';
    ocean[3][0] = 'C';
    ocean[4][0] = 'D';
    ocean[5][0] = 'E';

    ocean[0][1] = '1';
    ocean[0][2] = '2';
    ocean[0][3] = '3';
    ocean[0][4] = '4';
    ocean[0][5] = '5';


}


void
showOcean(char ocean[6][6])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 6; i++)
        {
            printf("\n");

            for(j = 0; j < 6; j++)
            {
                if (i == 0)
                {
                        printf(" %c  ", ocean[i][j]);
                }
                else
                {
                    if(MD == 0)
                    {
                        if(ocean[i][j]=='S')
                        {
                            printf("   |");
                        }
                        else
                        {
                            printf(" %c |", ocean[i][j]);
                        }
                    }
                    if(MD == 1)
                    {
                        printf(" %c |", ocean[i][j]);
                    }
                }
            }

        printf("\n   +---+---+---+---+---+");
        }


}

void
showInventory (int d, int s, int t)
{
    printf("\n\n Destruidores: %d\n Submarinos--: %d\n Torepedos---: %d\n",d,s,t);
}

void
submarinesIntoOcean (char ocean[6][6])
{
    int loop = 0;
    int X = rand() %5;
    int Y = rand() %5;
    while(X == 0 || Y == 0)
    {
         X = rand() %5;
         Y = rand() %5;
    }

    printf("X:%d  Y:%d \n",X,Y);

    if(ocean[X+1][Y]=='S'&& X-1 != 0)
        {
            X--;
        }
    if(ocean[X-1][Y]=='S'&& X+1 < 6)
        {
            X++;
        }
    if(ocean[X][Y+1]=='S'&& Y-1 != 0)
        {
            Y--;
        }
    if(ocean[X][Y-1]=='S'&& Y+1 < 6)
        {
            Y++;
        }

    ocean[X][Y] = 'S';

}


int
main()
{

    char ocean[6][6];
    int d = 0;
    int s = 3;
    int t = 6;

    int i = 0;
    int j = 0;
    char tentativa[2];
    int ativo =1;
    int coluna = 0;
    int fileira = 0;

    initOcean(ocean);
    for(i=1;i<=s;i++)
    {
        submarinesIntoOcean (ocean);
    }

    while(ativo!=0)
    {
        showOcean(ocean);
        showInventory (d,s,t);

        printf("onde deseja soltar o torpedo?");
        scanf("%s",&tentativa);

        coluna = tentativa[1] - '0';

        if(tentativa[0]=='A')
            {
                fileira = 1;
            }
        if(tentativa[0]=='B')
            {
                fileira = 2;
            }
        if(tentativa[0]=='C')
            {
                fileira = 3;
            }
        if(tentativa[0]=='D')
            {
                fileira = 4;
            }
        if(tentativa[0] == 'E')
            {
                fileira = 5;
            }

        for(i=1;i<=5;i++)
        {
            for(j=1;j<=5;j++)
                {
                    if(ocean[i][j]=='S'&& fileira == i || coluna == j)
                        {
                            printf("funciona ");
                        }
                }
        }


    }

    return 0;
}
