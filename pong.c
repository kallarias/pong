#include <stdio.h>

void print(int ball_x, int ball_y, int roc_1, int roc_2, int first, int second);
void tableTop(int first, int second, char gr_4, char gr_2);
int roc_pr_1(int roc_1);
int roc_pr_2(int roc_2);

int main() {
    int height = 80, weight = 25;
    int ball_x = height / 2 - 1;
    int ball_y = weight / 2 - 1;
    int dvizh_x = 1, dvizh_y = 1;
    int roc_1 = (weight / 2);
    int roc_2 = roc_1;
    char text;
    int first = 0, second = 0;

    print(ball_x, ball_y, roc_1, roc_2, first, second);

    while (1) {
        printf("\003\033[J");
        while (1) {
            scanf("%c", &text);
            if (text == 'a' || text == 'A') {
                roc_1 -= 1;
                break;
            } else if (text == 'z' || text == 'Z') {
                roc_1 += 1;
                break;
            } else if (text == 'k' || text == 'K') {
                roc_2 -= 1;
                break;
            } else if (text == 'm' || text == 'M') {
                roc_2 += 1;
                break;
            } else if (text == 32)
                break;
            else if (text == '\n')
                continue;
        }
        roc_1 = roc_pr_1(roc_1);
        roc_2 = roc_pr_2(roc_2);

        if (ball_x == 3) {
            if (roc_1 == ball_y || roc_1 + 1 == ball_y || roc_1 + 2 == ball_y) {
                if (ball_y == 25 || ball_y == 1) {
                    dvizh_y = dvizh_y * (-1);
                    dvizh_x = dvizh_x * (-1);
                } else
                    dvizh_x = dvizh_x * (-1);
            } else if (roc_1 - 1 == ball_y && dvizh_y == 1) {
                dvizh_x = dvizh_x * (-1);
                dvizh_y = dvizh_y * (-1);
            } else if (roc_1 + 3 == ball_y && dvizh_y == -1) {
                dvizh_x = dvizh_x * (-1);
                dvizh_y = dvizh_y * (-1);
            } else {
                second += 1;
                ball_x = height / 2 - 2;
                ball_y = weight / 2 - 2;
                dvizh_x = 1;
                dvizh_y = 1;
            }
        } else if (ball_x == 76) {
            if (roc_2 == ball_y || roc_2 + 1 == ball_y || roc_2 + 2 == ball_y) {
                if (ball_y == 25 || ball_y == 1) {
                    dvizh_y = dvizh_y * (-1);
                    dvizh_x = dvizh_x * (-1);
                } else
                    dvizh_x = dvizh_x * (-1);
            } else if (roc_2 - 1 == ball_y && dvizh_y == 1) {
                dvizh_x = dvizh_x * (-1);
                dvizh_y = dvizh_y * (-1);
            } else if (roc_2 + 3 == ball_y && dvizh_y == -1) {
                dvizh_x = dvizh_x * (-1);
                dvizh_y = dvizh_y * (-1);
            } else {
                first += 1;
                ball_x = height / 2;
                ball_y = weight / 2;
                dvizh_x = dvizh_x * (-1);
                dvizh_y = dvizh_y * (-1);
            }
        } else if (ball_y == 25 || ball_y == 1)
            dvizh_y = dvizh_y * (-1);
        ball_x += dvizh_x;
        ball_y += dvizh_y;
        print(ball_x, ball_y, roc_1, roc_2, first, second);
        if (first >= 21 || second >= 21) break;
    }
    return 0;
}

int roc_pr_1(int roc_1) {
    if (roc_1 < 1)
        roc_1 = 1;
    else if (roc_1 > 23)
        roc_1 = 23;
    return roc_1;
}

int roc_pr_2(int roc_2) {
    if (roc_2 < 1)
        roc_2 = 1;
    else if (roc_2 > 23)
        roc_2 = 23;
    return roc_2;
}

void print(int ball_x, int ball_y, int roc_1, int roc_2, int first, int second) {
    char gr_1 = ':';
    char gr_2 = '~';
    char gr_3 = '.';
    char gr_4 = '|';
    char gr_5 = '*';

    tableTop(first, second, gr_4, gr_2);

    for (int b = 1; b <= 25; b++) {
        printf("%c", gr_1);

        for (int c = 1; c <= 78; c++) {
            if (ball_x == c && ball_y == b)
                printf("%c", gr_5);
            else if (c == 2 && (b == roc_1 || b == roc_1 + 1 || b == roc_1 + 2))
                printf("%c", gr_4);
            else if (c == 77 && (b == roc_2 || b == roc_2 + 1 || b == roc_2 + 2))
                printf("%c", gr_4);
            else if (c == 39)
                printf("%c", gr_3);
            else
                printf(" ");
        }
        printf("%c", gr_1);
        printf("\n");
    }
    for (int a = 1; a <= 80; a++) {
        printf("%c", gr_2);
    }
    printf("\n");
}

void tableTop(int first, int second, char gr_4, char gr_2) {
    for (int a = 1; a <= 80; a++) {
        if (first >= 21 || second >= 21) {
            if (first >= 21) {
                printf("Player 1 WIN!!!!!");
                break;
            } else if (second >= 21) {
                printf("Player 2 WIN!!!!!");
                break;
            }
        } else {
            if (a == 34 && first >= 10)
                printf("%d", first);
            else if (a == 35 && first < 10)
                printf("%d", first);
            else if (a == 39 && first < 10)
                printf("%c", gr_4);
            else if (a == 38 && first >= 10)
                printf("%c", gr_4);
            else if (a == 42 && second >= 10)
                printf("%d", second);
            else if (a == 43 && second < 10)
                printf("%d", second);
        }
        printf(" ");
    }
    printf("\n");
    for (int a = 1; a <= 80; a++) {
        printf("%c", gr_2);
    }
    printf("\n");
}