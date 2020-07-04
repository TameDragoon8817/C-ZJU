#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int number, N, i, guess;
    scanf("%d%d", &number, &N);
    for (i = 1; i <= (N + 1); i++)
    {
        scanf("%d", &guess);
        if (i == N + 1)
        {
            printf("Game Over\n");
            break;
        }
        else if (guess==number&&i==1){
            printf("Bingo!");
            break;
        }
        else if (guess >= 0 && guess == number &&(i < 3||i==3))
        {
            printf("Lucky You!\n");
            break;
        }
        else if (guess >= 0 && guess == number && i > 3)
        {
            printf("Good Guess!\n");
            break;
        }
        else if (guess < 0)
        {
            printf("Game Over\n");
            break;
        }
        else if (guess >= 0 && guess < number)
            printf("Too small\n");
        else if (guess >= 0 && guess > number)
            printf("Too big\n");
    }
    return 0;
}