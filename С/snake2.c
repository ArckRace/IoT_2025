#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define STEP_MS 100

#define MIN_Y  2
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10, CONTROLS=3};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
}control_buttons;

struct control_buttons default_controls[CONTROLS] = {
    {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
    {'s', 'w', 'a', 'd'},
    {'S', 'W', 'A', 'D'}
};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
}

/*
 Движение головы с учетом текущего направления движения
 */
int go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    int next_x = head->x;
    int next_y = head->y;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
        case LEFT:
            next_x = head->x - 1;
        break;
        case RIGHT:
            next_x = head->x + 1;
        break;
        case UP:
            next_y = head->y - 1;
        break;
        case DOWN:
            next_y = head->y + 1;
        break;
        default:
        break;
    }

    if (next_x < 0 || next_x >= max_x || next_y < MIN_Y || next_y >= max_y)
        return 1;

    head->x = next_x;
    head->y = next_y;
    mvprintw(head->y, head->x, "%c", ch);
    refresh();
    return 0;
}

int checkDirection(snake_t* snake, int32_t key)
{
    int new_direction = 0;

    for (int i = 0; i < CONTROLS; i++)
    {
        if (key == default_controls[i].down)
            new_direction = DOWN;
        else if (key == default_controls[i].up)
            new_direction = UP;
        else if (key == default_controls[i].right)
            new_direction = RIGHT;
        else if (key == default_controls[i].left)
            new_direction = LEFT;

        if (new_direction)
            break;
    }

    if (!new_direction)
        return 0;

    if ((snake->direction == LEFT && new_direction == RIGHT) ||
        (snake->direction == RIGHT && new_direction == LEFT) ||
        (snake->direction == UP && new_direction == DOWN) ||
        (snake->direction == DOWN && new_direction == UP))
        return 0;

    return new_direction;
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
    int new_direction = checkDirection(snake, key);
    if (new_direction)
        snake->direction = new_direction;
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

int isSelfCollision(const struct snake_t *snake)
{
    for (size_t i = 0; i < snake->tsize; i++)
    {
        if (snake->tail[i].x == snake->x && snake->tail[i].y == snake->y)
            return 1;
    }
    return 0;
}

int main()
{
snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake,START_TAIL_SIZE,10,10);
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0,"Use arrows or WASD for control. Press 'F10' for EXIT");
    timeout(0);    // Неблокирующий ввод
    int key_pressed=0;
    int game_over = 0;
    struct timespec last_tick;
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &last_tick);
    while( key_pressed != STOP_GAME && !game_over )
    {
        key_pressed = getch(); // Считываем клавишу
        if (key_pressed != ERR)
            changeDirection(snake, key_pressed);

        clock_gettime(CLOCK_MONOTONIC, &now);
        long elapsed_ms = (now.tv_sec - last_tick.tv_sec) * 1000L +
                          (now.tv_nsec - last_tick.tv_nsec) / 1000000L;
        if (elapsed_ms < STEP_MS)
        {
            usleep(1000);
            continue;
        }
        last_tick = now;

        if (go(snake))
        {
            game_over = 1;
            break;
        }
        if (isSelfCollision(snake))
        {
            game_over = 1;
            break;
        }
        goTail(snake);
    }
    if (game_over)
    {
        mvprintw(1, 0, "Game Over! You hit your tail. Press any key...");
        timeout(-1);
        getch();
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}