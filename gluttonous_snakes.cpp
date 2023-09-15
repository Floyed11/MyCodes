//gluttonous_snakes for macOS

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

#define MAX_X  80
#define MAX_Y  24
#define MIN_X  0
#define MIN_Y  0
#define SNAKE_SIZE  3
#define FOOD_SIZE  1

int score = 0;
int speed = 500000;
int direction = 0;
int snake_size = SNAKE_SIZE;
int food_size = FOOD_SIZE;

struct snake_node
{
  int x;
  int y;
};

vector<snake_node> snake;
vector<snake_node> food;

void init();
void game();
void gameover();
void draw();
void move_snake();
void create_food();
void eat_food();

int main (int argc, char *argv[])
{
  init ();
  game ();
  gameover ();
  return 0;
}

void init ()
{
  initscr ();
  cbreak ();
  noecho ();
  keypad (stdscr, TRUE);
  curs_set (0);
  srand (time (NULL));
  snake_node node;
  node.x = MAX_X/2;
  node.y = MAX_Y/2;
  snake.push_back (node);
  create_food ();
  draw ();
}

void game ()
{
  while (1)
    {
      usleep (speed);
      move_snake ();
      eat_food ();
      draw ();
    }
}

void gameover ()
{
  sleep (2);
  endwin ();
  cout << "Game Over!" << endl;
  cout << "Your score is " << score << endl;
}

void draw ()
{
  clear ();
  for (int i = 0; i < MAX_X; i++)
    {
      mvaddch (0, i, '-');
      mvaddch (MAX_Y, i, '-');
    }
  for (int i = 0; i < MAX_Y; i++)
    {
      mvaddch (i, 0, '|');
      mvaddch (i, MAX_X, '|');
    }
  mvprintw (MAX_Y+1, 0, "score: %d", score);
  for (int i = 0; i < food.size (); i++)
    {
      mvaddch (food[i].y, food[i].x, '*');
    }
    for (int i = 0; i < snake.size (); i++)
        {
        mvaddch (snake[i].y, snake[i].x, 'o');
        }
    refresh ();
}

void move_snake ()
{
  int x = snake[0].x;
  int y = snake[0].y;
  switch (direction)
    {
    case 0:
      x++;
      break;
    case 1:
      y--;
      break;
    case 2:
      x--;
      break;
    case 3:
      y++;
      break;
    }
  if (x < MIN_X || x > MAX_X || y < MIN_Y || y > MAX_Y)
    {
      gameover ();
    }
  snake_node node;
  node.x = x;
  node.y = y;
  snake.insert (snake.begin (), node);
  if (snake.size () > snake_size)
    {
      snake.pop_back ();
    }
}

void create_food ()
{
  snake_node node;
  node.x = rand () % (MAX_X - MIN_X) + MIN_X;
  node.y = rand () % (MAX_Y - MIN_Y) + MIN_Y;
  food.push_back (node);
}

void eat_food ()
{
  for (int i = 0; i < food.size (); i++)
    {
      if (snake[0].x == food[i].x && snake[0].y == food[i].y)
        {
          score++;
          snake_size++;
          food.erase (food.begin () + i);
          create_food ();
        }
    }
}

