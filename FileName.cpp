
#pragma warning(disable:4996)
#pragma execution_character_set("utf_8")
#include <windows.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <wchar.h>


#define black  "\x1B[30m"
#define red  "\x1B[31m"
#define green  "\x1B[32m"
#define yellow  "\x1B[33m"
#define blue  "\x1B[34m"
#define magnata  "\x1B[35m"
#define cyan  "\x1B[36m"
#define white  "\x1B[37m"


int count = 0;


typedef struct game_play_back {
    char move;
    game_play_back* next;
    game_play_back* prev;
}game;
game_play_back* head = NULL;
game_play_back* move_ment = NULL;
void add(char move) {
    if (head == NULL) {
        head = (game_play_back*)malloc(sizeof(game_play_back*));
        head->move = move;
        head->next = NULL;
        head->prev = NULL;
        move_ment = head;
    }
    else {
        game_play_back* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = (game_play_back*)malloc(sizeof(game_play_back*));
        temp->next->move = move;
        temp->next->next = NULL;
        temp->next->prev = temp;
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void scan_maze(char path[], char arr[][35]) {
    FILE* file;
    char ch;
    int i = 0, j = 0;

    file = fopen(path, "r");


    if (file) {
        for (j = 0; j < 17; j++) {
            for (i = 0; i < 34; i++)
                arr[j][i] = getc(file);

        }
        fclose(file);
        for (j = 0; j < 17; j++)
            arr[j][34] = '\0';
    }
}

void print_maze(char arr[][35]) {
    int i, j, k = 0;
    char colors[3][8] = { "\x1B[33m" ,"\x1B[32m" ,"\x1B[34m" };
    for (j = 0; j < 17; j++) {
        i = 0;
        while (arr[j][i] != '\0') {
            if (arr[j][i] == '0')
                printf("%s%c%s", red, 11, white);

            else if (arr[j][i] == '1')
                printf("%s%c%s", cyan, 232, white);

            else if (arr[j][i] == '2')
                printf("%s%c%s", yellow, 15, white);

            else if (arr[j][i] == '3')
                printf("%s%c%s", yellow, 233, white);

            else if (arr[j][i] == '&')
                printf("%s%c%s", yellow, 235, white);
            else if (arr[j][i] == '*') {
                gotoxy(i, j);
                printf("%s%c%s", colors[k], '*', white);
                k++;
                if (k == 3)
                    k = 0;
            }
            else
                printf("%c", arr[j][i]);
            i++;

        }
    }
    printf("+");
}
void maze(char colors[][8]) {
    int l = 0, t = 0, o = 0;

    gotoxy(60, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    for (l = 10; l < 25; l++) {
        gotoxy(63, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    for (l = 10; l < 25; l++) {
        gotoxy(64, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    gotoxy(65, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    for (l = 10; l < 25; l++) {
        gotoxy(76, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    for (l = 10; l < 25; l++) {
        gotoxy(77, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    gotoxy(78, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    for (l = 10; l < 25; l++) {
        gotoxy(90, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    for (l = 10; l < 25; l++) {
        gotoxy(91, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    gotoxy(92, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    o = 10;
    for (l = 95; l < 110; l++) {
        if (l == 102)
            l++;
        o++;
        gotoxy(l + 1, o);
        printf("%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    }
    t = 0;
    gotoxy(92, 17);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    gotoxy(112, 24);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);


    gotoxy(110, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    printf("%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    o = 10;
    for (l = 129; l > 110; l--) {
        if (l == 111 || l == 113 || l == 117 || l == 120 || l == 123 || l == 126 || l == 128)
            l--;
        o++;
        gotoxy(l, o);
        printf("%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    }


    for (l = 10; l < 25; l++) {
        gotoxy(132, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    for (l = 10; l < 25; l++) {
        gotoxy(133, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    gotoxy(134, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    gotoxy(134, 17);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c%s", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, white);
    gotoxy(0, 0);
}

int play(char move, char bordgame[2][17][35], int* which_path, int money[], int person, int cofficient_of_gold, int bombs[2][2], int x_y[2], char mode) {
    int i = 0, j = 0, k = 0, a = 0;
    int x = x_y[0], y = x_y[1];
    char colors[3][8] = { "\x1B[33m" ,"\x1B[32m" ,"\x1B[34m" };
    gotoxy(x, y);
    printf(" ");
    if (move == 'w' || move == 'W') {
        y--;
    }
    else if (move == 'a' || move == 'A') {
        x--;
    }

    else if (move == 'd' || move == 'D') {
        x++;
    }

    else if (move == 's' || move == 'S') {
        y++;
    }


    else if (move == 'p') {

        if (*which_path == 0)
            *which_path = 1;
        else
            *which_path = 0;

    }
    if (bordgame[*which_path][y][x] == '-' || bordgame[*which_path][y][x] == '|' || bordgame[*which_path][y][x] == '+') {
        return -1;
    }

    else if (abs(bombs[0][0] - x) <= 2 && abs(bombs[0][1] - y) <= 2) {
        for (i = bombs[0][0] - 2; i <= bombs[0][0] + 2; i++) {
            j = bombs[0][1] - 2;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (j = bombs[0][1] - 2; j <= bombs[0][1] + 2; j++) {
            i = bombs[0][0] + 2;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (i = bombs[0][0] + 2; i >= bombs[0][0] - 2; i--) {
            j = bombs[0][1] + 2;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (j = bombs[0][1] + 2; j >= bombs[0][1] - 2; j--) {
            i = bombs[0][0] - 2;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }


        for (i = bombs[0][0] - 1; i <= bombs[0][0] + 1; i++) {
            j = bombs[0][1] - 1;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }
        for (j = bombs[0][1] - 1; j <= bombs[0][1] + 1; j++) {
            i = bombs[0][0] + 1;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (i = bombs[0][0] + 1; i >= bombs[0][0] - 1; i--) {
            j = bombs[0][1] + 1;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (j = bombs[0][1] + 1; j >= bombs[0][1] - 1; j--) {
            i = bombs[0][0] - 1;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }
        gotoxy(bombs[0][0], bombs[0][1]);
        printf("%s%c\a%s", red, 11, white);
        _sleep(1000);
        return -1;
    }

    else if (abs(bombs[1][0] - x) <= 2 && abs(bombs[1][1] - y) <= 2) {
        for (i = bombs[1][0] - 2; i <= bombs[1][0] + 2; i++) {
            j = bombs[1][1] - 2;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);

                _sleep(100);
            }
        }

        for (j = bombs[1][1] - 2; j <= bombs[1][1] + 2; j++) {
            i = bombs[1][0] + 2;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (i = bombs[1][0] + 2; i >= bombs[1][0] - 2; i--) {
            j = bombs[1][1] + 2;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (j = bombs[1][1] + 2; j >= bombs[1][1] - 2; j--) {
            i = bombs[1][0] - 2;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }


        for (i = bombs[1][0] - 1; i <= bombs[1][0] + 1; i++) {
            j = bombs[1][1] - 1;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (j = bombs[1][1] - 1; j <= bombs[1][1] + 1; j++) {
            i = bombs[1][0] + 1;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (i = bombs[1][0] + 1; i >= bombs[1][0] - 1; i--) {
            j = bombs[1][1] + 1;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        for (j = bombs[1][1] + 1; j >= bombs[1][1] - 1; j--) {
            i = bombs[1][0] - 1;
            if (i > 0 && j > 0 && i < 32 && j < 16) {
                gotoxy(i, j);
                printf("%s%c\a%s", red, 11, white);
                _sleep(100);
            }
        }

        gotoxy(bombs[1][0], bombs[1][1]);
        printf("%s%c\a%s", red, 11, white);
        _sleep(1000);
        return -1;
    }

    else if (bordgame[*which_path][y][x] == '*') {
        bordgame[0][y][x] = ' ';
        bordgame[1][y][x] = ' ';
        money[person] += 10 * cofficient_of_gold;
    }


    else if (bordgame[*which_path][y][x] == '1') {

        for (j = 1; j < 16; j++)
            for (i = 1; i < 32; i++) {
                if (bordgame[*which_path][j][i] == '1' && (i != x || j != y)) {
                    x = i;
                    y = j;
                    x_y[0] = x, x_y[1] = y;
                    return 0;
                }
            }
    }

    else if (bordgame[*which_path][y][x] == '2') {

        for (j = 1; j < 16; j++)
            for (i = 1; i < 32; i++) {
                if (bordgame[*which_path][j][i] == '2' && (i != x || j != y)) {
                    x_y[0] = i, x_y[1] = j;
                    x = i, y = j;
                    return 0;
                }
            }
    }
    else if (bordgame[*which_path][y][x] == '3') {

        for (j = 1; j < 16; j++)
            for (i = 1; i < 32; i++) {
                if (bordgame[*which_path][j][i] == '3' && (i != x || j != y)) {
                    x_y[0] = i, x_y[1] = j;
                    x = i, y = j;
                    return 0;
                }
            }
    }



    else if (bordgame[*which_path][y][x] == '&') {
        bordgame[*which_path][y][x] = ' ';
        char tir = ' ';
        gotoxy(x, y);
        printf("%s%c%s", red, 2, white);
        gotoxy(0, 20);
        if (mode == 'p') {
            tir = getch();
            add(tir);
        }
        else {
            tir = move_ment->move;
            move_ment = move_ment->next;
        }
        if (tir == 'd' || tir == 'D') {
            for (i = x; i < 32; i++)
                if (bordgame[*which_path][y][i] == '-' || bordgame[*which_path][y][i] == '|' || bordgame[*which_path][y][i] == '+') {
                    bordgame[*which_path][y][i] = ' ';
                    gotoxy(i, y);
                    printf(" ");
                    break;
                }
        }
        else if (tir == 'a' || tir == 'A') {
            for (i = x; i > 0; i--)
                if (bordgame[*which_path][y][i] == '-' || bordgame[*which_path][y][i] == '|' || bordgame[*which_path][y][i] == '+') {
                    bordgame[*which_path][y][i] = ' ';
                    gotoxy(i, y);
                    printf(" ");
                    break;
                }
        }
        else if (tir == 'w' || tir == 'W') {
            for (i = y; i > 0; i--)
                if (bordgame[*which_path][i][x] == '-' || bordgame[*which_path][i][x] == '|' || bordgame[*which_path][i][x] == '+') {
                    bordgame[*which_path][i][x] = ' ';
                    gotoxy(x, i);
                    printf(" ");
                    break;
                }
        }
        else if (tir == 's' || tir == 'S') {
            for (i = y; i < 16; i++)
                if (bordgame[*which_path][i][x] == '-' || bordgame[*which_path][i][x] == '|' || bordgame[*which_path][i][x] == '+') {
                    bordgame[*which_path][i][x] = ' ';
                    gotoxy(x, i);
                    printf(" ");
                    break;
                }
        }
    }
    x_y[0] = x, x_y[1] = y;
}

void read_file(char** user_names, char** passwords, char** email, char** phone_num, int* money, int** three_game_coins, int** three_game_win, int** three_game_times) {
    FILE* file;
    int i;
    file = fopen("C:\\Users\\asus\\Desktop\\final project\\etelaat.txt", "r+");

    while (fscanf(file, "%s %s %s %s %d %d %d %d %d %d %d %d %d %d", user_names[count], passwords[count], email[count], phone_num[count], &money[count], &three_game_coins[count][0], &three_game_coins[count][1], &three_game_coins[count][2], &three_game_win[count][0], &three_game_win[count][1], &three_game_win[count][2], &three_game_times[count][0], &three_game_times[count][1], &three_game_times[count][2]) == 14) {
        //  printf("%s %s %s %s %d %d %d %d %d %d %d %d %d %d\n", user_names[count], passwords[count], email[count], phone_num[count], money[count], three_game_coins[count][0], three_game_coins[count][1], three_game_coins[count][2], three_game_win[count][0], three_game_win[count][1], three_game_win[count][2], three_game_times[count][0], three_game_times[count][1], three_game_times[count][2]);

        for (i = 0; user_names[count][i] <= 122 && user_names[count][i] >= 48; i++);
        user_names[count][i] = '\0';

        for (i = 0; passwords[count][i] <= 122 && passwords[count][i] >= 48; i++);
        passwords[count][i] = '\0';

        for (i = 0; email[count][i] <= 122 && email[count][i] >= 48; i++);
        email[count][i] = '\0';

        for (i = 0; phone_num[count][i] <= 122 && phone_num[count][i] >= 48; i++);
        phone_num[count][i] = '\0';

        count++;
        if (count % 10 == 0) {
            user_names = (char**)realloc(user_names, (count + 10) * sizeof(char**));
            for (i = count; i < count + 10; i++)
                user_names[i] = (char*)malloc(20 * sizeof(char*));

            passwords = (char**)realloc(passwords, (count + 10) * sizeof(char**));
            for (i = count; i < count + 10; i++)
                passwords[i] = (char*)malloc(11 * sizeof(char*));

            email = (char**)realloc(email, (count + 10) * sizeof(char**));
            for (i = count; i < count + 10; i++)
                email[i] = (char*)malloc(20 * sizeof(char*));

            phone_num = (char**)realloc(phone_num, (count + 10) * sizeof(char**));
            for (i = count; i < count + 10; i++)
                phone_num[i] = (char*)malloc(12 * sizeof(char*));

            money = (int*)realloc(passwords, (count + 10) * sizeof(int));
            three_game_coins = (int**)realloc(three_game_coins, (count + 10) * sizeof(int**));
            for (i = count; i < count + 10; i++)
                three_game_coins[i] = (int*)malloc(3 * sizeof(int*));

            three_game_win = (int**)realloc(three_game_win, (count + 10) * sizeof(int**));
            for (i = count; i < count + 10; i++)
                three_game_win[i] = (int*)malloc(3 * sizeof(int*));

            three_game_times = (int**)realloc(three_game_times, (count + 10) * sizeof(int**));
            for (i = count; i < count + 10; i++)
                three_game_times[i] = (int*)malloc(3 * sizeof(int*));

        }
    }

    fclose(file);
}


void save_file(char** user_names, char** passwords, char** email, char** phone_num, int* money, int** three_game_coins, int** three_game_win, int** three_game_times) {
    FILE* file;
    file = fopen("C:\\Users\\asus\\Desktop\\final project\\etelaat.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s %s %d", user_names[i], passwords[i], email[i], phone_num[i], money[i]);
        fprintf(file, " %d %d %d %d %d %d %d %d %d\n", three_game_coins[i][0], three_game_coins[i][1], three_game_coins[i][2], three_game_win[i][0], three_game_win[i][1], three_game_win[i][2], three_game_times[i][0], three_game_times[i][1], three_game_times[i][2]);

    }

    fclose(file);
}

int forget(char** passwords, char** email, char** phone_num) {
    char em[20], phone[12];
    int k = 0, i = 0, j = 0, w = 0, t = 0;
    char limit1[65];
    limit1[0] = '\0';
    char colors1[7][8] = { black,red,green,cyan,black,yellow,magnata };
    char what;
    char pas1[11];
    char pas2[11];
    system("cls");
    system("color 71");
    maze(colors1);
    for (i = 0; i < 50; i++)
        printf("%s%c", blue, 219);
    printf("\n");
    for (i = 1; i < 30; i++)
        printf("%c%c\t\t\t\t\t\t%c%c\n", 219, 219, 219, 219);
    for (i = 0; i < 50; i++)
        printf("%s%c", blue, 219);
    int xes1[4] = { 13,20,16,23 };
    int y = 8;
    gotoxy(5, 2);
    printf("%sLIMITS :", magnata);
    gotoxy(3, 5);
    for (i = 3; i < 46; i += 2)
        printf("%s%c ", green, 220);
    gotoxy(5, 8);
    printf("%semail >>", black);
    gotoxy(5, 11);
    printf("phone number >>");
    gotoxy(5, 14);
    printf("password >> ");
    gotoxy(5, 17);
    printf("password(again) >> ");
    gotoxy(5, 23);
    printf("SUBMIT");
    gotoxy(5, 26);
    printf("BACK%s", white);
    i = 0;
    while (1) {
        gotoxy(3, 3);
        for (int e = 3; e < 48; e++)
            printf(" ");
        gotoxy(3, 3);
        printf("%s", cyan);
        fputs(limit1, stdout);
        gotoxy(5, y);
        if (y == 8) {
            printf("%semail %s>>%s", green, red, yellow);
        }
        else if (y == 11)
            printf("%sphone number %s>>%s", green, red, yellow);
        else if (y == 14)
            printf("%spassword %s>>%s", green, red, yellow);
        else if (y == 17)
            printf("%spassword(again) %s>>%s", green, red, yellow);
        else if (y == 23)
            printf("%sSUBMIT", cyan);
        else if (y == 26)
            printf("%sBACK", cyan);
        what = getch();

        if (what == 'H') {
            if (y == 11) {
                gotoxy(5, 11);
                printf("%sphone number >>", black);
                y = 8;
                k--;
            }
            else if (y == 14) {
                gotoxy(5, 14);
                printf("%spassword >>", black);
                y = 11;
                k--;
            }
            else if (y == 17) {
                gotoxy(5, 17);
                printf("%spassword(again) >>", black);
                y = 14;
                k--;
            }
            else if (y == 23) {
                gotoxy(5, 23);
                printf("%sSUBMIT", magnata);
                y = 17;
                k--;
            }
            else if (y == 26) {
                gotoxy(5, 26);
                printf("%sBACK", magnata);
                y = 23;
                k--;
            }
        }

        else if (what == 'P') {
            if (y == 8) {
                gotoxy(5, 8);
                printf("%semail >>", black);
                y = 11;
                k++;
            }
            else if (y == 11) {
                gotoxy(5, 11);
                printf("%sphone number >>", black);
                y = 14;
                k++;
            }
            else if (y == 14) {
                gotoxy(5, 14);
                printf("%spassword >>", black);
                y = 17;
                k++;
            }
            else if (y == 17) {
                gotoxy(5, 17);
                printf("%spassword(again) >>", black);
                y = 23;
                k++;
            }

            else if (y == 23) {
                gotoxy(5, 23);
                printf("%sSUBMIT", magnata);
                y = 26;
                k++;
            }

        }
        else if (what == 13 && y == 23) {

            if (i == 0) {
                strcpy(limit1, "there is nothing in email!");
                continue;
            }
            else if (w != 11) {
                strcpy(limit1, "phone number should be 11 digits!");
                continue;
            }
            else if (j < 4 || t < 4 || t>10 || i>10) {
                strcpy(limit1, "password should be between 4 and 10 chrakter!");
                continue;
            }
            em[i] = '\0';
            phone[w] = '\0';
            pas1[j] = '\0';
            pas2[t] = '\0';
            gotoxy(5, 30);
            printf("%s\n%s\n%s\n%s\n", em, phone, pas1, pas2);

            for (int q = 0; q < count; q++) {
                printf("%s vs %s %d\n", em, email[q], strcmp(em, email[q]));
                if (strcmp(em, email[q]) == 0) {
                    if (strcmp(phone, phone_num[q]) == 0) {
                        if (strcmp(pas1, pas2) == 0) {
                            strcpy(passwords[q], pas1);
                            return(q + 1);
                        }
                        else {
                            strcpy(limit1, "first and secound password dosnt match!");
                        }
                    }

                    else {
                        if (strcmp(limit1, "first and secound password dosnt match!") != 0)
                            strcpy(limit1, "phone number isnt true!");
                    }
                }
                else {
                    if (strcmp(limit1, "phone number isnt true!") != 0 && strcmp(limit1, "first and secound password dosnt match!") != 0)
                        strcpy(limit1, "this email dont math to any accounts!");
                }
            }
            continue;
        }
        else if (what == 13 && y == 26) {
            return -1;
        }
        else if (what != -32 && k < 4) {
            if (what == 8) {
                if ((xes1[k] > 13 && y == 8) || (xes1[k] > 20 && y == 11) || (xes1[k] > 16 && y == 14) || (xes1[k] > 23 && y == 17)) {
                    xes1[k]--;
                    if (y == 8)
                        i--;
                    else if (y == 11)
                        w--;
                    else if (y == 14)
                        j--;
                    else if (y == 17)
                        t--;

                    gotoxy(xes1[k], y);
                    printf(" ");
                }
            }
            else {
                gotoxy(xes1[k], y);
                xes1[k]++;
                if (y == 8) {
                    if (i < 20) {
                        em[i] = what;
                        i++;
                        printf("%c", what);
                    }
                    else {
                        strcpy(limit1, "email should be under 20 chrakter!");
                        xes1[k]--;
                    }
                }
                else  if (y == 11) {
                    if (w < 11) {
                        if (what >= 48 && what < 58) {
                            phone[w] = what;
                            w++;
                            printf("%c", what);
                        }
                        else strcpy(limit1, "phone number only include digit!");
                    }
                    else {
                        strcpy(limit1, "phone number should be 11 digits!");
                        xes1[k]--;
                    }
                }

                else if (y == 14) {
                    if (j <= 9) {
                        pas1[j] = what;
                        j++;
                        printf("%s%c", yellow, '*');
                    }
                    else {
                        strcpy(limit1, "password should be between 4 and 10 chrakter!");
                        xes1[k]--;
                    }
                }
                else if (y == 17) {
                    if (t <= 9) {
                        pas2[t] = what;
                        t++;
                        printf("%s%c", yellow, '*');
                    }
                    else {
                        strcpy(limit1, "password should be between 4 and 10 chrakter!");
                        xes1[k]--;
                    }
                }
            }
        }

    }

}

int sign_in(char** user_names, char** passwords, char** email, char** phone_num, int* money, int** three_game_coins, int** three_game_win, int** three_game_times) {

    int k = 0, i = 0, x = 5, y = 8, j = 0, q = 0;
    char user[20], pas[11];
    char limit2[60] = { '\0' };
    char what;
    system("color 1f");
    char colors2[7][8] = { white,red,green,cyan,black,yellow,magnata };
    int l, o, t = 0;

    maze(colors2);
    for (i = 0; i < 50; i++)
        printf("%s%c", green, 219);
    printf("\n");
    for (i = 1; i < 30; i++)
        printf("%c%c\t\t\t\t\t\t%c%c\n", 219, 219, 219, 219);
    for (i = 0; i < 50; i++)
        printf("%s%c", green, 219);
    int xes2[2] = { 21,18 };
    gotoxy(5, 2);
    printf("%sLIMITS :", black);
    gotoxy(3, 5);
    for (i = 3; i < 46; i += 2)
        printf("%s%c ", green, 220);
    gotoxy(5, 8);
    printf("%suser name >>", white);
    gotoxy(5, 15);
    printf("password >>");
    gotoxy(5, 23);
    printf("SUBMIT");
    gotoxy(5, 26);
    printf("BACK%s", white);
    i = 0;
    while (1) {
        gotoxy(3, 3);
        for (int e = 3; e < 48; e++)
            printf(" ");
        gotoxy(3, 3);
        printf("%s", black);
        fputs(limit2, stdout);
        gotoxy(5, y);
        if (y == 8) {
            printf("%suser name %s>>%s", green, red, yellow);
        }
        else if (y == 15)
            printf("%spassword %s>>%s", green, red, yellow);

        else if (y == 23)
            printf("%sSUBMIT%s", green, yellow);
        else if (y == 26)
            printf("%sBACK%s", green, yellow);

        what = getch();

        if (what == 'H') {
            if (y == 15) {
                gotoxy(5, 15);
                printf("%spassword >>", white);
                x = 21;
                y = 8;
                k--;
            }

            else if (y == 23) {
                gotoxy(5, 23);
                printf("%sSUBMIT", white);
                x = 18;
                y = 15;
                k--;
            }
            else if (y == 26) {
                gotoxy(5, 26);
                printf("%sBACK", white);
                x = 18;
                y = 23;
                k--;
            }
        }

        else if (what == 'P') {
            if (y == 8) {
                gotoxy(5, 8);
                printf("%suser name >>", white);
                x = 18;
                y = 15;
                k++;
            }
            else if (y == 15) {
                gotoxy(5, 15);
                printf("%spassword >>", white);
                x = 13;
                y = 23;
                k++;
            }

            else if (y == 23) {
                gotoxy(5, 23);
                printf("%sSUBMIT", white);
                x = 18;
                y = 26;
                k++;
            }

        }
        else if (what == 13 && y == 23) {

            if (i == 0) {
                strcpy(limit2, "there is nothing in user name!");
                continue;
            }
            else if (j == 0) {
                strcpy(limit2, "password should be between 4 and 10 chrakter!");
                continue;
            }
            pas[j] = '\0';
            user[i] = '\0';
            gotoxy(21, 8);

            for (q = 0; q < count; q++)
                if (strcmp(user, user_names[q]) == 0)
                    if (strcmp(pas, passwords[q]) == 0)
                        return(q + 1);
                    else {
                        strcpy(limit2, "password isnt true!");
                        gotoxy(18, 15);
                        for (q = 0; q < j; q++)
                            printf(" ");
                        xes2[1] = 18;
                        j = 0;
                    }
            if (strcmp(limit2, "password isnt true!") != 0) {
                strcpy(limit2, "user name not found!");
                gotoxy(21, 8);
                for (q = 0; q < i; q++)
                    printf(" ");
                xes2[0] = 21;
                i = 0;
            }
            continue;
        }
        else if (what == 13 && y == 26) {
            return -1;
        }
        else if (what != -32 && k < 2) {
            if (what == 8) {
                if ((xes2[k] > 21 && y == 8) || (xes2[k] > 18 && y == 15)) {
                    xes2[k]--;
                    if (y == 8)
                        i--;
                    else if (y == 15)
                        j--;

                    gotoxy(xes2[k], y);
                    printf(" ");
                }
            }
            else {
                gotoxy(xes2[k], y);
                xes2[k]++;
                if (y == 8) {
                    if (i < 20) {
                        user[i] = what;
                        i++;
                        printf("%c", what);
                    }
                    else {
                        strcpy(limit2, "user name should be under 20 chrakter!");
                        xes2[k]--;
                    }
                }


                else if (y == 15) {
                    if (j <= 9) {

                        pas[j] = what;
                        j++;
                        printf("%s%c", yellow, '*');
                    }
                    else {
                        strcpy(limit2, "password should be between 4 and 10 chrakter!");
                        xes2[k]--;
                    }
                }
            }
        }


    }
}

int sign_up(char** user_names, char** passwords, char** email, char** phone_num, int* money, int** three_game_coins, int** three_game_win, int** three_game_times)
{
    system("color Df");
    char user[20], pas[11];
    char  em[20], phone[12];
    int i, k = 0;
    char colors3[7][8] = { white,red,green,cyan,black,yellow,magnata };
    int l, o, t = 0;
    maze(colors3);

    for (i = 0; i < 50; i++)
        printf("%s%c", red, 219);
    printf("\n");
    for (i = 1; i < 30; i++)
        printf("%c%c\t\t\t\t\t\t%c%c\n", 219, 219, 219, 219);
    for (i = 0; i < 50; i++)
        printf("%s%c", red, 219);
    int xes3[4] = { 21,16,23,18 };
    gotoxy(5, 2);
    printf("%sLIMITS :", red);
    gotoxy(3, 5);
    for (i = 3; i < 46; i += 2)
        printf("%s%c ", green, 220);
    gotoxy(5, 8);
    printf("%suser name >>", blue);
    gotoxy(5, 11);
    printf("email >>");
    gotoxy(5, 14);
    printf("phone number >>");
    gotoxy(5, 17);
    printf("password >>");
    gotoxy(5, 23);
    printf("SUBMIT");
    gotoxy(5, 26);
    printf("BACK%s", white);

    int x = 20;
    int y = 8;
    char what;
    i = 0;
    int j = 0, q = 0, w = 0;
    char limit3[50] = "";

    while (1) {
        gotoxy(3, 3);
        for (int e = 3; e < 48; e++)
            printf(" ");
        gotoxy(3, 3);
        printf("%s", black);
        fputs(limit3, stdout);
        gotoxy(5, y);
        if (y == 8) {
            printf("%suser name %s>>%s", green, red, yellow);
        }
        else if (y == 11)
            printf("%semail %s>>%s", green, red, yellow);
        else if (y == 14)
            printf("%sphone number %s>>%s", green, red, yellow);
        else if (y == 17)
            printf("%spassword %s>>%s", green, red, yellow);
        else if (y == 23)
            printf("%sSUBMIT%s", green, yellow);
        else if (y == 26)
            printf("%sBACK%s", green, yellow);

        what = getch();

        if (what == 'H') {
            if (y == 11) {
                gotoxy(5, 11);
                printf("%semail >>%s", blue, white);
                x = 21;
                y -= 3;
                k--;
            }
            else if (y == 14) {
                gotoxy(5, 14);
                printf("%sphone number >>%s", blue, white);
                x = 10;
                y -= 3;
                k--;
            }
            else if (y == 17) {
                gotoxy(5, 17);
                printf("%spassword >>%s", blue, white);
                x = 16;
                y -= 3;
                k--;
            }
            else if (y == 23) {
                gotoxy(5, 23);
                printf("%sSUBMIT%s", blue, white);
                x = 13;
                y = 17;
                k--;
            }
            else if (y == 26) {
                gotoxy(5, 26);
                printf("%sBACK%s", blue, white);
                x = 13;
                y = 23;
                k--;
            }
        }

        else if (what == 'P') {
            if (y == 8) {
                gotoxy(5, 8);
                printf("%suser name >>%s", blue, white);
                x = 10;
                y += 3;
                k++;
            }
            else if (y == 11) {
                gotoxy(5, 11);
                printf("%semail >>%s", blue, white);
                x = 16;
                y += 3;
                k++;
            }
            else if (y == 14) {
                gotoxy(5, 14);
                printf("%sphone number >>%s", blue, white);
                x = 13;
                y += 3;
                k++;
            }
            else if (y == 17) {
                gotoxy(5, 17);
                printf("%spassword >>%s", blue, white);
                x = 10;
                y += 6;
                k++;
            }
            else if (y == 23) {
                gotoxy(5, 23);
                printf("%sSUBMIT%s", blue, white);
                x = 10;
                y = 26;
                k++;
            }

        }
        else if (what == 13 && y == 23) {
            if (q != 11) {
                strcpy(limit3, "phone should be 11 number!");
                continue;
            }
            else if (w < 4 || w>10) {
                strcpy(limit3, "password should be between 4 and 10 chrakter!");
                continue;
            }
            else if (i == 0) {
                strcpy(limit3, "there is nothing in user name!");
                continue;
            }
            else if (j == 0) {
                strcpy(limit3, "there is nothing in email!");
                continue;
            }

            user[i] = '\0';
            gotoxy(21, 8);
            for (int t = 0; t < i; t++)
                printf(" ");

            for (i = 0; i < count; i++)
                if (strcmp(user, user_names[i]) == 0) {
                    strcpy(limit3, "this user name used try another!");
                    continue;
                }
            xes3[0] = 21, xes3[1] = 16, xes3[2] = 23, xes3[3] = 18;
            strcpy(user_names[count], user);
            pas[w] = '\0';
            strcpy(passwords[count], pas);
            phone[q] = '\0';
            strcpy(phone_num[count], phone);
            em[j] = '\0';
            strcpy(email[count], em);

            break;
        }
        else if (what == 13 && y == 26) {
            return -1;
        }
        else if (what != -32 && k < 4) {
            if (what == 8) {
                if ((xes3[k] > 21 && y == 8) || (xes3[k] > 16 && y == 11) || (xes3[k] > 23 && y == 14) || (xes3[k] > 18 && y == 17)) {
                    xes3[k]--;
                    if (y == 8)
                        i--;
                    else if (y == 11)
                        j--;
                    else if (y == 14)
                        q--;
                    else if (y == 17)
                        w--;
                    gotoxy(xes3[k], y);
                    printf(" ");
                }
            }
            else {
                gotoxy(xes3[k], y);
                xes3[k]++;
                if (y == 8) {
                    if (i < 20) {
                        user[i] = what;
                        i++;
                        printf("%c", what);
                    }
                    else {
                        strcpy(limit3, "user name should be under 20 chrakter!");
                        xes3[k]--;
                    }
                }
                else if (y == 11) {
                    if (j < 20) {
                        em[j] = what;
                        j++;
                        printf("%c", what);
                    }
                    else {
                        strcpy(limit3, "email should be under 20 chrakter!");
                        xes3[k]--;
                    }
                }
                else if (y == 14) {
                    if (q < 11) {
                        if (what >= 48 && what < 58) {
                            phone[q] = what;
                            q++;
                            printf("%c", what);
                        }
                        else {
                            xes3[k]--;
                            strcpy(limit3, "phone number include numbers only");
                        }
                    }
                    else {
                        strcpy(limit3, "phone number should be 11 number!");
                        xes3[k]--;
                    }
                }
                else if (y == 17) {
                    if (w <= 9) {
                        pas[w] = what;
                        w++;
                        printf("%s%c", yellow, '*');
                    }
                    else {
                        strcpy(limit3, "password should be between 4 and 10 chrakter!");
                        xes3[k]--;
                    }
                }
            }
        }


    }

    system("cls");

    FILE* file;
    money[count] = 0;
    for (i = 0; i < 3; i++) {
        three_game_coins[count][i] = -1;
        three_game_win[count][i] = -1;
        three_game_times[count][i] = -1;
    }

    file = fopen("C:\\Users\\asus\\Desktop\\final project\\etelaat.txt", "a");

    fprintf(file, "\n%s %s %s %s %d -1 -1 -1 -1 -1 -1 -1 -1 -1", user_names[count], passwords[count], email[count], phone_num[count], money[count]);
    fclose(file);
    count++;
    system("color 0f");
    return 1;
}

char first_menu(char** user_names, char** passwords, char** email, char** phone_num, int* money, int** three_game_coins, int** three_game_win, int** three_game_times) {
    char menuchose;
    int person = 0, a;
    char menu[4][30] = { {"1- Sign in" },{"2- Sign up"},{"3- Forgot password"},{"4- Save and exit"} };
    while (1) {
        person = 0;
        system("color 71");
        printf("\n\t %s *** %sMenu%s ***\n\n", black, red, black);
        printf("   %s%s\n", blue, menu[0]);
        printf("   %s%s\n", yellow, menu[1]);
        printf("   %s%s\n", green, menu[2]);
        printf("   %s%s\n", cyan, menu[3]);

        printf("\n\t%swhich one you whant?\t", black);

        menuchose = getch();
        if (menuchose < 49 || menuchose>52) {
            system("cls");
            continue;
        }

        system("cls");
        system("color 0f");
        printf("%s", white);

        if (menuchose == 49) {
            read_file(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times);
            if ((person = sign_in(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times)) == -1) {
                system("cls");
                count = 0;
                continue;
            }
            else
                break;
        }

        else if (menuchose == 50) {
            read_file(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times);
            if (sign_up(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times) == -1) {
                system("cls");
                count = 0;
                continue;
            }

            person = count;
            count++;
            break;
        }
        else if (menuchose == 51) {
            read_file(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times);
            if ((person = forget(passwords, email, phone_num)) == -1) {
                system("cls");
                count = 0;
                continue;
            }
            save_file(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times);
            break;
        }
        else if (menuchose == 52)
            exit(0);


        else
            printf("\t\tIt was wrong input! Try again.\n%s", red, white);

    }
    return person;

}

void secound_menu(char** user_names, char** passwords, char** email, char** phone_num, int* money, int person, char** massages, char** senders, char** recivers, char** read, char** mysender, int* howsend, int* date, int** three_game_coins, int** three_game_win, int** three_game_times) {
    system("color 0f");
    char menuchose;
    char menuchose2;
    char colors[3][8] = { "\x1B[33m" ,"\x1B[32m" ,"\x1B[34m" };
    int cofficient_of_gold = 1, lives_number = 1, time_limit = 45, time_cofficeint = 1;
    char menu2[3][2][60] = { {{"C:\\Users\\asus\\Desktop\\final project\\Pizza.txt"},{"C:\\Users\\asus\\Desktop\\final project\\Pizza1.txt"}}, {{"C:\\Users\\asus\\Desktop\\final project\\Nodel.txt"},{"C:\\Users\\asus\\Desktop\\final project\\Nodel1.txt"}}, {{"C:\\Users\\asus\\Desktop\\final project\\Hamberger.txt"},{"C:\\Users\\asus\\Desktop\\final project\\Hamberger1.txt"}} };
    int win = 0, lose = 0;
    int bombs[2][2];
    int a = 0, which_path;
    char move;
    int x_y[2] = { 1,1 };
    int i, j, k = 0, rez;
    int x = 1, y = 1;
    char bordgame[2][17][35];
    char last_path[2][60];
    char menu[8][35] = { {"1- games history" },{"2- change password"},{"3- massages"},{"4- best players"},{"5- buy gold"},{"6- start a new game"},{"7- play back last game"},{"8- Exit"} };
    while (1) {
        system("cls");
        printf("\n\t %s *** %sMenu%s ***\n\n", white, red, white);
        printf("   %s%s\n", blue, menu[0]);
        printf("   %s%s\n", yellow, menu[1]);
        printf("   %s%s\n", green, menu[2]);
        printf("   %s%s\n", magnata, menu[3]);
        printf("   %s%s\n", cyan, menu[4]);
        printf("   %s%s\n", red, menu[5]);
        printf("   %s%s\n", blue, menu[6]);
        printf("   %s%s\n", yellow, menu[7]);

        printf("\n\t%swhich one you whant?\t", white);
        menuchose = getch();
        if (menuchose < 49 || menuchose>57)
            continue;

        system("cls");

        if (menuchose == 49) {
            system("cls");
            printf("\n\t%s*** %sGAME HISTORY%s ***%s\n", blue, cyan, blue, white);

            printf("\n\n    %suser name: %s%s \t\t %scoins: %s%d%s", magnata, yellow, user_names[person], magnata, yellow, money[person], white);
            if (three_game_coins[person][0] >= 0) {
                if (three_game_win[person][0] == 0)
                    printf("\n\n    %slast game played: %slosed,  %scoins collected: %s%d%s\n", green, red, green, yellow, three_game_coins[person][0], white);
                else
                    printf("\n\n    %slast game played: %swin,  %scoins collected: %s%d, %stime left: %s%d%s\n", green, cyan, green, yellow, three_game_coins[person][0], green, yellow, three_game_times[person][0], white);
            }
            if (three_game_coins[person][1] >= 0) {
                if (three_game_win[person][1] == 0)
                    printf("\n\n    %sone to last game played: %slosed,  %scoins collected: %s%d%s\n", green, red, green, yellow, three_game_coins[person][1], white);
                else
                    printf("\n\n    %sone to last game played: %swin,  %scoins collected: %s%d, %stime left: %s%d%s\n", green, cyan, green, yellow, three_game_coins[person][1], green, yellow, three_game_times[person][1], white);
            }
            if (three_game_coins[person][2] >= 0) {
                if (three_game_win[person][2] == 0)
                    printf("\n\n    %stwo to last game played: %slosed,  %scoins collected: %s%d%s\n", green, red, green, yellow, three_game_coins[person][2], white);
                else
                    printf("\n\n    %stwo to last game played: %swin,  %scoins collected: %s%d, %stime left: %s%d%s\n", green, cyan, green, yellow, three_game_coins[person][2], green, yellow, three_game_times[person][2], white);

            }
            printf("\n\n\t%spress enter to go back to menu%s", red, white);
            char n = getch();
            if (n == '\n')
                continue;
        }

        else if (menuchose == 50) {//change pas
            int k = 0, i = 0, j = 0, w = 0, t = 0;
            char limit4[50];
            limit4[0] = '\0';
            char colors4[7][8] = { black,red,green,cyan,black,yellow,magnata };
            char what;
            char current_pas[11];
            char pas1[11];
            char pas2[11];
            system("cls");
            system("color 71");
            maze(colors4);
            for (i = 0; i < 50; i++)
                printf("%s%c", blue, 219);
            printf("\n");
            for (i = 1; i < 30; i++)
                printf("%c%c\t\t\t\t\t\t%c%c\n", 219, 219, 219, 219);
            for (i = 0; i < 50; i++)
                printf("%s%c", blue, 219);
            int xes4[4] = { 26,22,29 };
            int y = 8;
            gotoxy(5, 2);
            printf("%sLIMITS :", magnata);
            gotoxy(3, 5);
            for (i = 3; i < 46; i += 2)
                printf("%s%c ", green, 220);
            gotoxy(5, 8);
            printf("%scurrent password >>", black);
            gotoxy(5, 14);
            printf("new password >>");
            gotoxy(5, 17);
            printf("new password(again) >> ");
            gotoxy(5, 23);
            printf("SUBMIT");
            gotoxy(5, 26);
            printf("BACK%s", white);
            i = 0;
            while (1) {
                gotoxy(3, 3);
                for (int e = 3; e < 48; e++)
                    printf(" ");

                gotoxy(3, 3);
                printf("%s", cyan);
                fputs(limit4, stdout);
                gotoxy(5, y);
                if (y == 8) {
                    printf("%scurrent password %s>>%s", green, red, yellow);
                }

                else if (y == 14)
                    printf("%snew password %s>>%s", green, red, yellow);
                else if (y == 17)
                    printf("%snew password(again) %s>>%s", green, red, yellow);
                else if (y == 23)
                    printf("%sSUBMIT", cyan);
                else if (y == 26)
                    printf("%sBACK", cyan);
                what = getch();

                if (what == 'H') {

                    if (y == 14) {
                        gotoxy(5, 14);
                        printf("%snew password >>", black);
                        y = 8;
                        k--;
                    }
                    else if (y == 17) {
                        gotoxy(5, 17);
                        printf("%snew password(again) >>", black);
                        y = 14;
                        k--;
                    }
                    else if (y == 23) {
                        gotoxy(5, 23);
                        printf("%sSUBMIT", magnata);
                        y = 17;
                        k--;
                    }
                    else if (y == 26) {
                        gotoxy(5, 26);
                        printf("%sBACK", magnata);
                        y = 23;
                        k--;
                    }
                }

                else if (what == 'P') {
                    if (y == 8) {
                        gotoxy(5, 8);
                        printf("%scurrent password >>", black);
                        y = 14;
                        k++;
                    }

                    else if (y == 14) {
                        gotoxy(5, 14);
                        printf("%snew password >>", black);
                        y = 17;
                        k++;
                    }
                    else if (y == 17) {
                        gotoxy(5, 17);
                        printf("%snew password(again) >>", black);
                        y = 23;
                        k++;
                    }

                    else if (y == 23) {
                        gotoxy(5, 23);
                        printf("%sSUBMIT", magnata);
                        y = 26;
                        k++;
                    }

                }
                else if (what == 13 && y == 23) {

                    if (i >= 4 && i < 11 && j >= 4 && j < 11 && t >= 4 && t < 11) {
                        current_pas[i] = '\0';

                        if (strcmp(current_pas, passwords[person]) == 0) {

                            pas1[j] = '\0';
                            pas2[t] = '\0';

                            if (strcmp(pas1, pas2) == 0) {
                                strcpy(passwords[person], pas1);
                                save_file(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times);
                                system("color 0f");
                                break;
                            }
                            else {
                                strcpy(limit4, "first and secount password dont match!");
                                continue;
                            }
                        }
                        else
                            strcpy(limit4, "current password is wrong!");
                    }
                    else
                        strcpy(limit4, "every passwords should be 4 to 10 chrackter");
                }
                else if (what == 13 && y == 26) {
                    system("color 0f");
                    break;
                }
                else if (what != -32) {
                    if (what == 8) {
                        if ((xes4[k] > 26 && y == 8) || (xes4[k] > 22 && y == 14) || (xes4[k] > 29 && y == 17)) {
                            xes4[k]--;
                            if (y == 8)
                                i--;

                            else if (y == 14)
                                j--;
                            else if (y == 17)
                                t--;

                            gotoxy(xes4[k], y);
                            printf(" ");
                        }
                    }
                    else {
                        gotoxy(xes4[k], y);

                        if (y == 8) {
                            if (i < 10) {
                                current_pas[i] = what;
                                i++;
                                printf("%c", what);
                                xes4[k]++;
                            }

                        }


                        else if (y == 14) {
                            if (j <= 9) {
                                pas1[j] = what;
                                j++;
                                xes4[k]++;
                                printf("%s%c", yellow, '*');
                            }

                        }
                        else if (y == 17) {
                            if (t <= 9) {
                                xes4[k]++;
                                pas2[t] = what;
                                t++;
                                printf("%s%c", yellow, '*');
                            }

                        }
                    }
                }

            }

        }

        else if (menuchose == 51) {//gaping
            int p = 0, s = 0;
            int i = 0, flag = 0, k = 0;
            while (1) {

                FILE* file;

                file = fopen("C:\\Users\\asus\\Desktop\\final project\\massages.txt", "r+");

                while (fscanf(file, "%s %s %s %d ", senders[p], recivers[p], read[p], &date[p]) == 4) {
                    k = 0;
                    while (fscanf(file, "%c", &massages[p][k]) == 1) {
                        if (massages[p][k] == '*') {
                            massages[p][k] = '\0';
                            break;
                        }
                        k++;
                    }
                    flag = 0;
                    k = 0;
                    if (strcmp(user_names[person], recivers[p]) == 0 && strcmp(read[p], "unread") == 0)
                        if (s == 0) {
                            strcpy(mysender[0], senders[p]);
                            s++;
                            howsend[0] = 1;
                        }
                        else {
                            for (i = 0; i < s; i++) {
                                if (strcmp(mysender[i], senders[p]) == 0) {
                                    howsend[i]++;
                                    flag = 1;
                                    break;
                                }

                            }
                            if (flag == 0) {
                                strcpy(mysender[s], senders[p]);
                                howsend[s] = 1;
                                s++;
                            }
                        }

                    p++;
                    if (p % 10 == 0) {
                        massages = (char**)realloc(massages, (p + 10) * sizeof(char*));
                        for (i = p; i < p + 10; i++)
                            massages[i] = (char*)malloc(500 * sizeof(char));

                        senders = (char**)realloc(senders, (p + 10) * sizeof(char*));
                        for (i = p; i < p + 10; i++)
                            senders[i] = (char*)malloc(21 * sizeof(char));

                        recivers = (char**)realloc(recivers, (p + 10) * sizeof(char*));
                        for (i = p; i < p + 10; i++)
                            recivers[i] = (char*)malloc(21 * sizeof(char));

                        read = (char**)realloc(read, (p + 10) * sizeof(char*));
                        for (i = p; i < p + 10; i++)
                            read[i] = (char*)malloc(7 * sizeof(char));

                        mysender = (char**)realloc(mysender, (p + 10) * sizeof(char*));
                        for (i = p; i < p + 10; i++)
                            mysender[i] = (char*)malloc(21 * sizeof(char));

                        howsend = (int*)realloc(mysender, (p + 10) * sizeof(int));
                        date = (int*)realloc(date, (p + 10) * sizeof(int));
                    }

                }
                int l = 0;
                char** tartib = (char**)malloc(count * sizeof(char*));
                char what;
                int y = 11;

                for (l; l < count; l++)
                    tartib[l] = (char*)malloc(20 * sizeof(char));
                l = 0;
                int* how_much_tartib = (int*)malloc(count * sizeof(count));
                fclose(file);
                system("color 1f");
                for (i = 0; i < 42; i++)
                    printf("%s%c", green, 219);
                printf("\n");
                for (i = 1; i < 13 + 2 * count; i++)
                    printf("%c%c\t\t\t\t\t%c%c\n", 219, 219, 219, 219);
                for (i = 0; i < 42; i++)
                    printf("%s%c", green, 219);

                gotoxy(12, 2);
                printf("%sMASAGES ", black);
                gotoxy(3, 4);
                for (i = 3; i < 38; i += 2)
                    printf("%s%c ", green, 220);
                gotoxy(5, 8);
                printf("%sWho do you want to massage?%s\n\n", black, white);
                gotoxy(3, 10 + 2 * count);
                printf("%sBACK%s", black, white);
                gotoxy(5, 10);
                for (i = 0; i < s; i++) {
                    int max = 0;
                    for (k = 0; k < s; k++)
                        if (howsend[k] > max)
                            max = howsend[k];
                    for (k = 0; k < s; k++)
                        if (max == howsend[k]) {
                            printf("\n\t%s%s %s(%d)%s\n", magnata, mysender[k], yellow, howsend[k], white);
                            strcpy(tartib[l], mysender[k]);
                            how_much_tartib[l] = howsend[k];
                            l++;
                            howsend[k] = 0;
                            break;
                        }
                }

                for (i = 0; i < count; i++) {
                    flag = 1;
                    for (k = 0; k < s; k++) {
                        if (strcmp(user_names[i], mysender[k]) == 0) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 1 && i != person) {
                        printf("\n\t%s%s %s(0)%s\n", magnata, user_names[i], yellow, white);
                        strcpy(tartib[l], user_names[i]);
                        how_much_tartib[l] = 0;
                        l++;
                    }
                }
                gotoxy(8, y);
                printf("%s%s%s (%d)", black, tartib[(y - 11) / 2], white, how_much_tartib[(y - 11) / 2]);
                flag = 1;
                while (1) {


                    what = getch();

                    if (what == 'H') {
                        if (y == 10 + 2 * count) {
                            gotoxy(3, 10 + 2 * count);
                            printf("%sBACK%s", black, white);
                            y -= 3;
                            gotoxy(8, y);
                            printf("%s%s%s (%d)", black, tartib[(y - 11) / 2], white, how_much_tartib[(y - 11) / 2]);
                        }
                        else if (y > 11) {
                            gotoxy(8, y);
                            printf("%s%s%s (%d)%s", magnata, tartib[(y - 11) / 2], yellow, how_much_tartib[(y - 11) / 2], white);
                            y -= 2;
                            gotoxy(8, y);
                            printf("%s%s%s (%d)", black, tartib[(y - 11) / 2], white, how_much_tartib[(y - 11) / 2]);
                        }
                    }
                    else if (what == 'P') {
                        if (y < 6 + count * 2) {
                            gotoxy(8, y);
                            printf("%s%s%s (%d)%s", magnata, tartib[(y - 11) / 2], yellow, how_much_tartib[(y - 11) / 2], white);
                            y += 2;
                            gotoxy(8, y);
                            printf("%s%s%s (%d)", black, tartib[(y - 11) / 2], white, how_much_tartib[(y - 11) / 2]);
                        }
                        else if (y == 7 + 2 * count) {
                            gotoxy(8, y);
                            printf("%s%s%s (%d)%s", magnata, tartib[(y - 11) / 2], yellow, how_much_tartib[(y - 11) / 2], white);
                            gotoxy(3, y += 3);
                            printf("%sBACK", white);
                        }
                    }
                    else if (what == 13) {
                        if (y == 10 + 2 * count) {
                            flag = 0;
                            system("color 0f");
                        }
                        system("cls");
                        break;
                    }
                }
                if (flag == 0)
                    break;
                int j;
                int last_date = 1;
                char new_reciver[21];
                int lines = 0;
                strcpy(new_reciver, tartib[(y - 11) / 2]);

                system("cls");
                system("color Df");


                gotoxy(5, 2);
                printf("%sMassage to %s%s", black, red, new_reciver);
                gotoxy(3, 4);
                for (i = 3; i < 46; i += 2)
                    printf("%s%c ", green, 220);
                y = 7;

                for (i = 0; i <= p; i++) {
                    for (j = 0; j <= p; j++) {
                        if (date[j] == i + 1 && strcmp(recivers[j], new_reciver) == 0 && strcmp(senders[j], user_names[person]) == 0) {
                            gotoxy(5, y);
                            printf("%s", green);
                            for (int u = 0; massages[i][u] != '\0'; u++) {
                                if (massages[j][u] != '#')
                                    printf("%c", massages[j][u]);
                                else {
                                    y++;
                                    lines++;
                                    gotoxy(5, y);
                                }
                            }
                            last_date = i + 1;
                            y += 2;
                            lines += 2;
                            break;
                        }
                        else if (date[j] == i + 1 && strcmp(recivers[j], user_names[person]) == 0 && strcmp(senders[j], new_reciver) == 0) {
                            gotoxy(8, y);
                            printf("%s", blue);
                            for (int u = 0; massages[j][u] != '\0'; u++) {
                                if (massages[j][u] != '#')
                                    printf("%c", massages[j][u]);
                                else {
                                    y++;
                                    lines++;
                                    gotoxy(8, y);
                                }
                            }
                            last_date = i + 1;
                            y += 2;
                            lines += 2;
                            break;
                        }
                    }
                }


                for (i = 0; i < 50; i++) {
                    gotoxy(i, 0);
                    printf("%s%c", red, 219);
                }

                for (i = 1; i < 20 + lines; i++) {
                    gotoxy(0, i);
                    printf("%c%c", 219, 219);
                    gotoxy(48, i);
                    printf("%c%c", 219, 219);
                }
                for (i = 0; i < 50; i++) {
                    gotoxy(i, 20 + lines);
                    printf("%s%c", red, 219);
                }


                for (i = 0; i <= p; i++)
                    if (strcmp(recivers[i], user_names[person]) == 0 && strcmp(senders[i], new_reciver) == 0) {
                        strcpy(read[i], "read");
                    }
                int flag_save = 0;
                int where_is = 5;
                char new_massage[500];
                int which_word = 0;
                int y_new_massage = y += 2;
                int y_send = y + 4;
                int y_back = y + 6;
                gotoxy(5, y_new_massage);
                printf("%sNew massage :%s", white, green);
                y_new_massage++;
                y++;
                x = 5;
                gotoxy(3, y_send);
                printf("%sSEND", black);
                gotoxy(3, y_back);
                printf("BACK%s", green);
                while (1) {
                    if (where_is > 45) {
                        if (y_new_massage - y_send < 2) {
                            lines += 1;
                            y_send += 1;
                            y_back += 1;
                            gotoxy(0, 1 + y_new_massage);
                            printf("%s", red);
                            for (i = 1 + y_new_massage; i < 20 + lines; i++)
                                printf("%c%c                                              %c%c\n", 219, 219, 219, 219);
                            for (i = 0; i < 50; i++)
                                printf("%s%c", red, 219);
                            gotoxy(3, y_send);
                            printf("%sSEND", black);
                            gotoxy(3, y_back);
                            printf("BACK%s", green);
                        }
                        new_massage[which_word] = '#';
                        which_word++;
                        y_new_massage++;
                        y++;
                        where_is = 5;
                    }

                    gotoxy(x, y);
                    what = getch();
                    if (what == 13) {
                        if (y != y_send && y != y_back) {
                            if (y_new_massage - y_send < 2) {
                                lines += 1;
                                y_send += 1;
                                y_back += 1;
                                gotoxy(0, 1 + y_new_massage);
                                printf("%s", red);
                                for (i = 1 + y_new_massage; i < 20 + lines; i++)
                                    printf("%c%c                                              %c%c\n", 219, 219, 219, 219);
                                for (i = 0; i < 50; i++)
                                    printf("%s%c", red, 219);
                                gotoxy(3, y_send);
                                printf("%sSEND", black);
                                gotoxy(3, y_back);
                                printf("BACK%s", green);
                            }
                            new_massage[which_word] = '#';
                            which_word++;
                            y_new_massage++;
                            y++;
                            where_is = 5;
                        }

                        else if (y == y_send) {
                            new_massage[which_word] = '\0';

                            strcpy(senders[p], user_names[person]);
                            strcpy(recivers[p], new_reciver);
                            strcpy(read[p], "unread");
                            strcpy(massages[p], new_massage);
                            date[p] = last_date + 1;

                            file = fopen("C:\\Users\\asus\\Desktop\\final project\\massages.txt", "w");
                            for (i = 0; i <= p; i++)
                                fprintf(file, "%s %s %s %d %s*\n", senders[i], recivers[i], read[i], date[i], massages[i]);
                            fclose(file);
                            system("cls");
                            p = 0;
                            break;
                        }
                        else if (y == y_back) {
                            system("cls");
                            p = 0;
                            break;
                        }
                    }

                    else if (what == 'H') {
                        if (y == y_back) {
                            gotoxy(3, y);
                            printf("%sBACK", black);
                            y = y_send;
                            gotoxy(3, y);
                            printf("%sSEND", white);
                        }
                        else  if (y == y_send) {
                            gotoxy(3, y);
                            printf("%sSEND%s", black, green);
                            y = y_new_massage;

                        }
                    }

                    else if (what == 'P') {


                        if (y == y_send) {
                            gotoxy(3, y);
                            printf("%sSEND", black);
                            y = y_back;
                            gotoxy(3, y);
                            printf("%sBACK", white);
                        }
                        else  if (y == y_new_massage) {
                            y = y_send;
                            gotoxy(3, y);
                            printf("%sSEND", white);


                        }
                    }

                    else if (what != -32) {
                        gotoxy(where_is, y);
                        printf("%c", what);
                        where_is++;
                        new_massage[which_word] = what;
                        which_word++;

                    }
                }

            }
        }

        else if (menuchose == 52) {//best player
            int k = 0, max = 0, j = 0., g = 0, flag = 1, j2 = 0;
            int best[10];
            if (count < 10)
                k = count;
            else
                k = 10;
            printf("\n\t%s%d %sbest players (each home show 10 points) :%s", red, k, cyan, white);
            for (i = 0; i < k; i++) {
                max = 0;
                for (j = 0; j < count; j++) {
                    flag = 1;
                    for (g = 0; g < 10; g++)
                        if (best[g] == j) {
                            flag = 0;
                            break;
                        }
                    if (money[j] > max && flag == 1) {
                        max = money[j];
                        j2 = j;
                    }
                }


                best[i] = j2;
                printf("\n\n\t%s%s %s:  ", yellow, user_names[i], white);
                max = max / 10;
                for (max; max > 0; max--)
                    printf("%s%c%s", blue, 219, white);
            }
            printf("\n\t%spress enter to back to the menu%s", red, white);
            char n = getch();
            if (n == '\n')
                continue;
        }

        else if (menuchose == 53) {//cheat
            char cheat[20];
            int lose = 0, win = 0;
            printf("\n\t%sITS TIME TO CHEAT!%s\n", green, white);
            printf("\t%senter your code:  %s", yellow, white);
            scanf("%s", cheat);
            if (strcmp(cheat, "bp_project") == 0) {
                money[person] += 100;
            }
            else {
                printf("%s\tDONT EXIST THAT CODE!%s", red, white);
                _sleep(1500);
            }
        }

        else if (menuchose == 54) {
            win = 0;
            while (1) {
                system("cls");
                printf("\n\t %s *** %sMAPS%s ***\n\n", white, red, white);
                printf("   %s%s%s(close your eyes!)\n", blue, "1- Pizza", green);
                printf("   %s%s%s(wear shoses!)\n", yellow, "2- Nodel", cyan);
                printf("   %s%s%s(are you shure!)\n", green, "3- Hamberger", magnata);
                printf("   %s%s\n", cyan, "4- Exit from game box");

                printf("\n\t%sWhich one you whant?(Enter its number only)\t", white);
                int which_path = 0;
                menuchose2 = getch();
                if (menuchose2 < 49 || menuchose2>52)
                    continue;
                menuchose2 -= 48;

                if (menuchose2 == 4) {
                    system("cls");
                    break;
                }

                system("cls");
                char path[2][60], bordgame[2][17][35];
                strcpy(path[0], menu2[menuchose2 - 1][0]);
                strcpy(path[1], menu2[menuchose2 - 1][1]);
                scan_maze(path[0], bordgame[0]);
                scan_maze(path[1], bordgame[1]);

                int menuchose3;
                char menu3[5][55] = { {"1- Time slow down(cost: 60)"},{"2- Show all of table few secound at begining(cost: 50)"},{"3- Double gold from stars(80)"},{"4- Start from last game(cost: 100)"},{"5- No extention "} };
                system("cls");
                while (1) {
                    time_cofficeint = 1, cofficient_of_gold = 1;
                    x_y[0] = 1, x_y[1] = 1;

                    printf("\n\t %s *** %sExtenyions%s ***\n\n", white, red, white);
                    printf("   %s%s\n", blue, menu3[0]);
                    printf("   %s%s\n", yellow, menu3[1]);
                    printf("   %s%s\n", green, menu3[2]);
                    printf("   %s%s\n", magnata, menu3[3]);
                    printf("   %s%s\n", cyan, menu3[4]);

                    printf("\n\t%sWhich one you whant?(Enter its number only)\t", white);

                    menuchose3 = getch();
                    if (menuchose3 < 49 || menuchose3>53) {
                        system("cls");
                        continue;
                    }
                    menuchose3 -= 48;
                    if (menuchose3 == 1) {
                        if (money[person] - 60 >= 0) {
                            money[person] -= 60;
                            time_cofficeint = 2;
                            break;
                        }
                        else {
                            system("cls");
                            printf("\n\t%sNot enogh gold you have! Your golds are: %s%d%s\n", red, yellow, money[person], white);
                        }
                    }

                    else if (menuchose3 == 2) {
                        if (money[person] - 50 >= 0) {
                            money[person] -= 50;
                            system("cls");
                            print_maze(bordgame[which_path]);
                            _sleep(3000);
                            system("cls");
                            break;
                        }
                        else {
                            system("cls");
                            printf("\n\t%sNot enogh gold you have! Your golds are: %s%d%s\n", red, yellow, money[person], white);
                        }
                    }

                    else if (menuchose3 == 3) {
                        if (money[person] - 80 >= 0) {
                            money[person] -= 80;
                            cofficient_of_gold = 2;
                            break;
                        }
                        else {
                            system("cls");
                            printf("\n\t%sNot enogh gold you have! Your golds are: %s%d%s\n", red, yellow, money[person], white);
                        }
                    }

                    else if (menuchose3 == 4) {
                        move_ment = head;
                        which_path = 0;
                        int* w = &which_path;
                        x_y[0] = 1, x_y[1] = 1;
                        if (money[person] - 100 >= 0) {
                            if (head == NULL) {
                                printf("%s\n\tYou dont played any game to go from last of it!%s", red, white);
                                _sleep(2000);
                                system("cls");
                                continue;
                            }
                            if (rez == 1) {
                                printf("%s\n\tYou won last game so you cant go ahead!%s", red, white);
                                _sleep(2000);
                                system("cls");
                                continue;
                            }

                            strcpy(path[0], last_path[0]);
                            strcpy(path[1], last_path[1]);
                            scan_maze(path[0], bordgame[0]);
                            scan_maze(path[1], bordgame[1]);
                            while (move_ment->next != NULL) {
                                move = move_ment->move;
                                play(move, bordgame, w, money, person, cofficient_of_gold, bombs, x_y, 'b');
                                move_ment = move_ment->next;
                            }
                            money[person] -= 100;
                            break;
                        }
                        else {
                            system("cls");
                            printf("\n\t%sNot enogh gold you have! Your golds are: %s%d%s\n", red, yellow, money[person], white);
                        }
                    }

                    else if (menuchose3 == 5)
                        break;
                }

                system("cls");
                print_maze(bordgame[which_path]);
                a = 0;
                for (j = 1; j < 16; j++)
                    for (i = 1; i < 32; i++)
                        if (bordgame[0][j][i] == '0') {
                            bombs[a][0] = i;
                            bombs[a][1] = j;
                            a++;
                            if (a == 2)
                                break;
                        }

                head = NULL;
                time_t time1 = time(NULL);
                time_t time2;
                int money_copy = money[person];
                while (1) {
                    x = x_y[0], y = x_y[1];
                    time2 = time(NULL);

                    for (j = 1; j < 16; j++)
                        for (i = 1; i < 32; i++)
                            if (i == x && j == y) {
                                gotoxy(x, y);
                                printf("%s%c%s", red, 2, white);
                            }
                            else if (i >= x - 9 && i <= x + 9 && j <= y + 5 && j >= y - 5) {
                                gotoxy(i, j);
                                if (bordgame[which_path][j][i] == '*') {
                                    printf("%s%c%s", colors[k], '*', white);
                                    k++;
                                    if (k == 3)
                                        k = 0;
                                }
                                else if (bordgame[which_path][j][i] == '0')
                                    printf("%s%c%s", red, 11, white);

                                else if (bordgame[which_path][j][i] == '1')
                                    printf("%s%c%s", cyan, 232, white);

                                else if (bordgame[which_path][j][i] == '2')
                                    printf("%s%c%s", yellow, 15, white);

                                else if (bordgame[which_path][j][i] == '3')
                                    printf("%s%c%s", yellow, 233, white);

                                else if (bordgame[which_path][j][i] == '&')
                                    printf("%s%c%s", yellow, 235, white);

                                else
                                    printf("%c", bordgame[which_path][j][i]);
                            }
                            else if (bordgame[which_path][j][i] == '*') {
                                gotoxy(i, j);
                                printf("%s%c%s", colors[k], '*', white);
                                k++;
                                if (k == 3)
                                    k = 0;
                            }
                            else
                            {
                                gotoxy(i, j);
                                putchar(' ');
                            }


                    if ((time_limit * time_cofficeint - (int)(time2 - time1)) > 0) {
                        gotoxy(40, 1);
                        for (int k = 0; k < 11; k++)
                            printf("%s%c %s", green, 223, white);
                        gotoxy(40, 2);
                        printf("%c%sYour left time: %s%d %s%c%s", 219, cyan, yellow, time_limit * time_cofficeint - (int)(time2 - time1), green, 219, white);
                        gotoxy(40, 3);
                        for (int k = 0; k < 11; k++)
                            printf("%s%c %s", green, 220, white);
                    }
                    else {
                        system("cls");
                        printf("\n\t");
                        for (int k = 0; k < 11; k++)
                            printf("%s%c ", green, 223);
                        printf("\n\t%c%s Your time finished%s%c%s\n\t", 219, red, green, 219, white);
                        for (int k = 0; k < 11; k++)
                            printf("%s%c %s", green, 220, white);
                        printf("%s", white);
                        _sleep(1500);
                        rez = -1;
                        break;
                    }

                    gotoxy(0, 20);
                    move = getch();
                    add(move);
                    gotoxy(x, y);
                    printf(" ");

                    gotoxy(0, 20);
                    printf(" ");
                    int* w = &which_path;
                    rez = play(move, bordgame, w, money, person, cofficient_of_gold, bombs, x_y, 'p');
                    if ((x_y[0] == 32 && x_y[1] == 16) || (x_y[0] == 33 && x_y[1] == 16) || (x_y[0] == 32 && x_y[1] == 15) || (x_y[0] == 33 && x_y[1] == 15))
                        rez = 1;
                    if (rez == 1) {
                        win = 1;
                        system("cls");
                        printf("\n\n\t\t%s-----------------------------------------------------------------------\n", green);
                        _sleep(150);
                        printf("\t\t|%c%c%c%c  %c%c%c   %c%c%c%c%c%c   %c%c  %c%c%c     %c%c%c%c  %c%c  %c%c%c%c    %c%c%c%c%c%c     %c%c%c%c%c%c |\n", 177, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
                        _sleep(150);
                        printf("\t\t|%c%c%c%c  %c%c%c  %c%c%c %c%c%c  %c%c%c  %c%c%c    %c%c%c%c%c  %c%c   %c%c%c   %c%c%c%c%c%c%c    %c%c%c%c%c%c%c |\n", 177, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 177, 178, 178, 177, 178, 178, 177, 177, 178, 178);
                        _sleep(150);
                        printf("\t\t| %c%c%c  %c%c%c  %c%c%c %c%c%c  %c%c%c  %c%c%c     %c%c%c  %c%c%c  %c%c%c    %c%c%c %c%c%c    %c%c%c %c%c%c |\n", 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178);
                        _sleep(150);
                        printf("\t\t| %c%c%c  %c%c%c  %c%c%c %c%c%c  %c%c%c  %c%c%c     %c%c%c%c%c%c%c%c%c%c%c%c     %c%c%c %c%c%c    %c%c%c %c%c%c |\n", 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178);
                        _sleep(150);
                        printf("\t\t| %c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c    %c%c%c  %c%c |\n", 177, 178, 178, 178, 178, 178, 178, 178, 177, 178, 178, 178, 178, 178, 178, 177, 178, 178, 178, 178, 178, 178, 178, 177, 177, 177, 178, 178, 178, 177, 177, 178, 178, 178, 177, 178, 178, 178, 178, 178, 178, 177, 178, 178, 178, 178, 178);
                        _sleep(150);
                        printf("\t\t| %c%c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c         %c%c%c%c%c     %c%c%c  %c%c |\n", 177, 177, 177, 177, 177, 178, 178, 178, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177);
                        _sleep(150);
                        printf("\t\t| %c%c%c %c%c%c%c                                                            |\n", 178, 178, 178, 177, 178, 178, 178);
                        _sleep(150);
                        printf("\t\t| %c%c%c%c%c%c%c%c                                                            |\n", 177, 178, 178, 178, 178, 178, 178, 178);
                        _sleep(150);
                        printf("\t\t|  %c%c%c%c%c%c                                                             |\n", 177, 177, 177, 177, 177, 177);
                        _sleep(150);
                        printf("\t\t'---------------------------------------------------------------------'%s\n", white);
                        _sleep(3000);
                        money[person] += (time_limit * time_cofficeint - (int)(time2 - time1)) / 2;

                        if (three_game_coins[person][0] >= 0) {
                            if (three_game_coins[person][1] >= 0) {
                                three_game_coins[person][2] = three_game_coins[person][1];
                                three_game_coins[person][1] = three_game_coins[person][0];
                                three_game_coins[person][0] = money[person] - money_copy;

                                three_game_times[person][2] = three_game_times[person][1];
                                three_game_times[person][1] = three_game_times[person][0];
                                three_game_times[person][0] = (time_limit * time_cofficeint - (int)(time2 - time1));

                                three_game_win[person][2] = three_game_win[person][1];
                                three_game_win[person][1] = three_game_win[person][0];
                                three_game_win[person][0] = 1;
                            }
                            else {
                                three_game_coins[person][1] = three_game_coins[person][0];
                                three_game_coins[person][0] = money[person] - money_copy;

                                three_game_times[person][1] = three_game_times[person][0];
                                three_game_times[person][0] = (time_limit * time_cofficeint - (int)(time2 - time1));

                                three_game_win[person][1] = three_game_win[person][0];
                                three_game_win[person][0] = 1;
                            }
                        }
                        else {
                            three_game_coins[person][0] = money[person] - money_copy;

                            three_game_times[person][0] = (time_limit * time_cofficeint - (int)(time2 - time1));

                            three_game_win[person][0] = 1;
                        }

                        save_file(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times);
                        break;
                    }
                    else if (rez == -1)
                        break;
                }
                if (rez == -1) {
                    system("cls");
                    printf("\n\n\t\t%s-----------------------------------------------------------------------\n", red);
                    _sleep(150);
                    printf("\t\t|                                        %c%c%c                  %c%c%c     |\n", 178, 178, 178, 178, 178, 178);
                    _sleep(150);
                    printf("\t\t|                                       %c%c%c%c                %c%c%c%c%c     |\n", 177, 177, 178, 178, 177, 177, 178, 178, 178);
                    _sleep(150);
                    printf("\t\t|   %c%c%c   %c%c%c    %c%c%c%c%c%c   %c%c%c   %c%c       %c%c%c   %c%c%c%c%c  %c%c%c%c   %c%c%c%c%c%c%c  |\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
                    _sleep(150);
                    printf("\t\t|  %c%c%c%c  %c%c%c     %c%c%c%c%c%c  %c%c%c%c  %c%c%c       %c%c%c %c%c%c%c%c%c%c  %c%c   %c%c%c%c%c%c%c    |\n", 177, 177, 178, 178, 177, 178, 178, 178, 178, 177, 177, 178, 178, 177, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 177, 178, 178, 178, 178, 177, 177, 177, 178, 178, 178, 177);
                    _sleep(150);
                    printf("\t\t|   %c%c%c  %c%c%c    %c%c%c %c%c%c   %c%c%c  %c%c%c       %c%c%c %c%c%c %c%c%c%c%c%c%c%c%c   %c%c%c%c     |\n", 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 177, 178, 178, 178, 178, 177, 178, 178, 178);
                    _sleep(150);
                    printf("\t\t|   %c%c%c  %c%c%c    %c%c%c %c%c%c   %c%c%c  %c%c%c       %c%c%c %c%c%c %c%c%c%c%c%c%c%c%c   %c%c%c%c %c%c%c |\n", 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 178, 178, 177, 177, 177, 177, 178, 178, 177, 178, 178, 178, 178, 178, 178);
                    _sleep(150);
                    printf("\t\t|  %c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c   %c%c%c%c%c%c%c  |\n", 177, 177, 178, 178, 178, 178, 178, 178, 178, 177, 177, 178, 178, 178, 178, 178, 178, 177, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 177, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 177, 177, 178, 178, 178, 178, 178);
                    _sleep(150);
                    printf("\t\t|   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c     %c%c%c%c%c%c%c      %c%c%c%c%c  %c%c%c%c  %c%c%c%c%c%c     %c%c%c%c%c  |\n", 177, 177, 177, 177, 177, 178, 178, 178, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177);
                    _sleep(150);
                    printf("\t\t|   %c%c%c %c%c%c%c                                                          |\n", 178, 178, 178, 177, 178, 178, 178);
                    _sleep(150);
                    printf("\t\t|   %c%c%c%c%c%c%c%c                                                          |\n", 177, 177, 178, 178, 178, 178, 178, 178);
                    _sleep(150);
                    printf("\t\t|    %c%c%c%c%c%c                                                           |\n", 177, 177, 177, 177, 177, 177);
                    _sleep(150);
                    printf("\t\t-----------------------------------------------------------------------%s\n", white);
                    Sleep(3000);
                    system("cls");


                    if (three_game_coins[person][0] >= 0) {
                        if (three_game_coins[person][1] >= 0) {
                            three_game_coins[person][2] = three_game_coins[person][1];
                            three_game_coins[person][1] = three_game_coins[person][0];
                            three_game_coins[person][0] = money[person] - money_copy;

                            three_game_times[person][2] = three_game_times[person][1];
                            three_game_times[person][1] = three_game_times[person][0];
                            three_game_times[person][0] = 45 * time_cofficeint - (time_limit * time_cofficeint - (int)(time2 - time1));

                            three_game_win[person][2] = three_game_win[person][1];
                            three_game_win[person][1] = three_game_win[person][0];
                            three_game_win[person][0] = 0;
                        }
                        else {
                            three_game_coins[person][1] = three_game_coins[person][0];
                            three_game_coins[person][0] = money[person] - money_copy;

                            three_game_times[person][1] = three_game_times[person][0];
                            three_game_times[person][0] = 45 * time_cofficeint - (time_limit * time_cofficeint - (int)(time2 - time1));

                            three_game_win[person][1] = three_game_win[person][0];
                            three_game_win[person][0] = 0;
                        }
                    }
                    else {
                        three_game_coins[person][0] = money[person] - money_copy;

                        three_game_times[person][0] = 45 * time_cofficeint - (time_limit * time_cofficeint - (int)(time2 - time1));

                        three_game_win[person][0] = 0;
                    }

                    save_file(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times);

                    strcpy(last_path[0], path[0]);
                    strcpy(last_path[1], path[1]);

                    break;
                }
            }
        }


        else if (menuchose == 55) {
            char whicn_path_copy;
            char back_move;
            if (head == NULL) {
                printf("%s\n\tYou dont played any game to reviwe it now!%s", red, white);
                _sleep(2000);
                continue;
            }

            else {
                int* w = &which_path;
                char path[2][60];
                strcpy(path[0], menu2[menuchose2 - 1][0]);
                strcpy(path[1], menu2[menuchose2 - 1][1]);
                scan_maze(path[0], bordgame[0]);
                scan_maze(path[1], bordgame[1]);
                which_path = 0;
                system("cls");
                int which_path_copy = which_path;
                x_y[0] = 1;
                x_y[1] = 1;
                which_path = 0;
                move_ment = head;

                x_y[0] = 1, x_y[1] = 1;
                print_maze(bordgame[which_path]);
                while (1) {
                    if (which_path != which_path_copy) {
                        system("cls");
                        which_path_copy = which_path;
                        print_maze(bordgame[which_path]);
                    }

                    gotoxy(x_y[0], x_y[1]);
                    printf("%s%c%s", red, 2, white);

                    for (int i = 38; i <= 78; i += 2) {
                        gotoxy(i, 2);
                        printf("%s%c%s ", green, 220, white);
                    }
                    gotoxy(38, 4);
                    printf("%s%c %sIf want to exit reviwe mode press %sesc %s%c%s", green, 219, red, yellow, green, 219, white);
                    for (int i = 38; i <= 78; i += 2) {
                        gotoxy(i, 6);
                        printf("%s%c %s", green, 223, white);
                    }
                    back_move = getch();
                    gotoxy(x, y);
                    printf(" ");
                    if (back_move == 27)
                        break;

                    if (back_move == 'd' && move_ment->next != NULL) {
                        move = move_ment->move;
                        move_ment = move_ment->next;
                        rez = play(move, bordgame, w, money, person, cofficient_of_gold, bombs, x_y, 'b');
                    }

                    else if (back_move == 'd' && move_ment->next == NULL) {
                        if (win == 1) {
                            for (int i = 38; i <= 60; i += 2) {
                                gotoxy(i, 8);
                                printf("%s%c%s ", green, 220, white);
                            }
                            gotoxy(8, 10);
                            gotoxy(38, 10);
                            printf("%s%c %sThats when you win!%s%c%s", green, 219, yellow, green, 219, white);
                            for (int i = 38; i <= 60; i += 2) {
                                gotoxy(i, 12);
                                printf("%s%c%s ", green, 223, white);
                            }
                        }

                        else {
                            for (int i = 38; i <= 60; i += 2) {
                                gotoxy(i, 8);
                                printf("%s%c%s ", red, 220, white);
                            }
                            gotoxy(8, 10);
                            gotoxy(38, 10);
                            printf("%s%c %sThats when you lose!%s%c%s", red, 219, yellow, red, 219, white);
                            for (int i = 38; i <= 60; i += 2) {
                                gotoxy(i, 12);
                                printf("%s%c%s ", red, 223, white);
                            }
                        }
                        _sleep(2000);
                        system("cls");
                        break;
                    }

                    else if (back_move == 'a' && move_ment->prev != NULL) {
                        move_ment = move_ment->prev;
                        if (move_ment->move == 'a')
                            move = 'd';
                        else if (move_ment->move == 'd')
                            move = 'a';
                        else if (move_ment->move == 's')
                            move = 'w';
                        else if (move_ment->move == 'w')
                            move = 's';

                        rez = play(move, bordgame, w, money, person, cofficient_of_gold, bombs, x_y, 'b');
                    }

                }
            }
        }
        else if (menuchose == 56)
            exit(0);
    }
}

int main()
{
    char back_ground_colors[8][10] = { "color 0f" , "color 1f", "color 2f", "color 3f", "color 4f", "color 5f", "color 6f", "color 7f" };
    char colors2[7][8] = { "\x1B[31m","\x1B[35m","\x1B[36m","\x1B[37m", "\x1B[33m" ,"\x1B[32m" ,"\x1B[34m" };

    FILE* file;
    int i = 0, j = 0;
    char menuchose;
    char wellcome[17] = "Wellcome to MAZE";

    char colors[7][8] = { "\x1B[31m","\x1B[32m","\x1B[33m" ,"\x1B[34m" ,"\x1B[35m","\x1B[36m","\x1B[37m" };
    int l, o, t = 0;
    gotoxy(60, 10);

    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    gotoxy(30, 2);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    for (l = 10; l < 25; l++) {
        gotoxy(63, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    for (l = 10; l < 25; l++) {
        gotoxy(64, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    gotoxy(30, 4);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    gotoxy(65, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    gotoxy(30, 6);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    for (l = 10; l < 25; l++) {
        gotoxy(76, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    for (l = 10; l < 25; l++) {
        gotoxy(77, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    gotoxy(30, 8);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    gotoxy(78, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    gotoxy(30, 10);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    for (l = 10; l < 25; l++) {
        gotoxy(90, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    for (l = 10; l < 25; l++) {
        gotoxy(91, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }

    gotoxy(30, 12);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    gotoxy(92, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    o = 10;
    for (l = 95; l < 110; l++) {
        if (l == 102)
            l++;
        o++;
        gotoxy(l + 1, o);
        printf("%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    }
    t = 0;

    gotoxy(30, 14);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    gotoxy(92, 17);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    gotoxy(30, 16);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    gotoxy(112, 24);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    gotoxy(30, 18);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    gotoxy(110, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    printf("%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    gotoxy(30, 20);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    o = 10;
    for (l = 129; l > 110; l--) {
        if (l == 111 || l == 113 || l == 117 || l == 120 || l == 123 || l == 126 || l == 128)
            l--;
        o++;
        gotoxy(l, o);
        printf("%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    }
    gotoxy(30, 22);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    for (l = 10; l < 25; l++) {
        gotoxy(132, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }
    for (l = 10; l < 25; l++) {
        gotoxy(133, l);
        printf("%s%c", colors[(t++) % 7], 219);
    }

    gotoxy(30, 24);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);
    gotoxy(134, 24);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    gotoxy(30, 26);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    gotoxy(134, 10);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);

    gotoxy(30, 28);
    for (i = 0; i < 16; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    _sleep(1000);

    gotoxy(134, 17);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219);
    printf("%s%c%s%c%s%c%s%c%s", colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, colors[(t++) % 7], 219, white);

    gotoxy(30, 30);
    for (i = 0; i < 12; i++) {
        printf("%s%c\a", colors2[i % 7], wellcome[i]);

    }
    for (i = 2; i < 30; i += 2)
    {
        gotoxy(42, i);
        printf("      ");
    }
    _sleep(5000);
    system("cls");
    char** user_names = (char**)malloc(10 * sizeof(char**));
    for (i = 0; i < 10; i++)
        user_names[i] = (char*)malloc(20 * sizeof(char*));

    char** passwords = (char**)malloc(10 * sizeof(char**));
    for (i = 0; i < 10; i++)
        passwords[i] = (char*)malloc(11 * sizeof(char*));

    char** email = (char**)malloc(10 * sizeof(char**));
    for (i = 0; i < 10; i++)
        email[i] = (char*)malloc(20 * sizeof(char*));

    char** phone_num = (char**)malloc(10 * sizeof(char**));
    for (i = 0; i < 10; i++)
        phone_num[i] = (char*)malloc(12 * sizeof(char*));

    int* money = (int*)malloc(10 * sizeof(int));
    int* wines = (int*)malloc(10 * sizeof(int));
    int* loses = (int*)malloc(10 * sizeof(int));

    char** massages;
    char** senders;
    char** recivers;
    char** read;
    char** mysender;
    int* howsend;
    int* date;
    int** three_game_coins;
    int** three_game_win;
    int** three_game_times;

    massages = (char**)malloc(10 * sizeof(char**));
    for (i = 0; i < 10; i++)
        massages[i] = (char*)malloc(500 * sizeof(char));

    senders = (char**)malloc(10 * sizeof(char*));
    for (i = 0; i < 10; i++)
        senders[i] = (char*)malloc(21 * sizeof(char*));

    recivers = (char**)malloc(10 * sizeof(char**));
    for (i = 0; i < 10; i++)
        recivers[i] = (char*)malloc(21 * sizeof(char*));

    read = (char**)malloc(10 * sizeof(char*));
    for (i = 0; i < 10; i++)
        read[i] = (char*)malloc(7 * sizeof(char*));

    mysender = (char**)malloc(10 * sizeof(char**));
    for (i = 0; i < 10; i++)
        mysender[i] = (char*)malloc(21 * sizeof(char*));

    howsend = (int*)malloc(10 * sizeof(int*));
    date = (int*)malloc(10 * sizeof(int*));

    three_game_coins = (int**)malloc(10 * sizeof(int**));
    for (i = 0; i < 10; i++)
        three_game_coins[i] = (int*)malloc(3 * sizeof(int*));

    three_game_win = (int**)malloc(10 * sizeof(int**));
    for (i = 0; i < 10; i++)
        three_game_win[i] = (int*)malloc(3 * sizeof(int*));

    three_game_times = (int**)malloc(10 * sizeof(int**));
    for (i = 0; i < 10; i++)
        three_game_times[i] = (int*)malloc(3 * sizeof(int*));

    int person = first_menu(user_names, passwords, email, phone_num, money, three_game_coins, three_game_win, three_game_times);
    secound_menu(user_names, passwords, email, phone_num, money, person - 1, massages, senders, recivers, read, mysender, howsend, date, three_game_coins, three_game_win, three_game_times);

    return 0;
}
