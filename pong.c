#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>  //Для sleep

#define PLAYER_SIZE 3

#define TERM_SIZE_X 80
#define TERM_SIZE_Y 25

#define WINNING_SCORE 20

struct Ball {
  int x;
  int y;
  int direction_x; // 0 - вправо, 1 - влево
  int direction_y; // 0 - вверх, 1 - вниз
} ball;

void display(int, int, int, int);
int pressing_key();
void sleeping_time();
void ball_movement(int, int);
void players_movement(int, int, int);
int has_winner(int, int);
int ball_bound_checking_x(int, int, int, int, int);

int main() {
  int term_size_x = 80;
  int term_size_y = 25;

  int player1_y = 12;
  int player1_score = 0;

  int player2_y = 12;
  int player2_score = 0;

  int key_id = 0;
  char esc_key = 'q';

  int ball_x = TERM_SIZE_X / 2;
  int ball_y = TERM_SIZE_Y / 2;
  int ball_direction_x = 1; // 0 - вправо, 1 - влево
  int ball_direction_y = 1; // 0 - вверх, 1 - вниз

  while (key_id != esc_key) {
    if (has_winner(player1_score, player2_score)) {
      break;
    }

    key_id = pressing_key();
    players_movement(player1_y, player2_y, key_id);
    ball_movement(ball);
    ball_direction_x = ball_bound_checking(player1_y, player2_y, ball_x, ball_direction_x);
    display(player1_y, player2_y, ball_x, ball_y, ball_direction_x);
    //sleeping_time();
  }

  return 0;
}

int ball_bound_checking_x(int player1_y, int player2_y, int ball_x, int ball_y, int ball_direction_x) {
  int result = 0;
  if ((ball_direction_x == 1 && ball_x == TERM_SIZE_X && ball_y == player2_y)
     || (ball_direction_x == 1 && ball_x == TERM_SIZE_X && ball_y == player2_y + 1)
     || (ball_direction_x == 1 && ball_x == TERM_SIZE_X && ball_y == player2_y + 2)) {
        
        result = 0;
  }
  
  if ((ball_direction_x == 0 && ball_x == 1 && ball_y == player1_y)
     || (ball_direction_x == 0 && ball_x == 1 && ball_y == player1_y + 1)
     || (ball_direction_x == 0 && ball_x == 1 && ball_y == player1_y + 2)) {
        
        result = 1;
  }
}

int has_winner(int player1, int player2) {
  int result = 0;
  if (player1 >= WINNING_SCORE || player2 >= WINNING_SCORE) {
    result = player1 > player2 ? 1 : 2;
    printf("Победил %d игрок", result);
  }
  return result;
}

void ball_movement(Ball ball) {
//  ball.x += ball.direction_x == 1 ? 1 : -1;
//
//  ball.y += ball.direction_y == 1 ? 1 : -1;
//
//  if (ball.y >= term_size_y) {
//    ball_direction_y = 0;
//  }
//  if (ball.y <= 0) {
//    ball_direction_y = 1;
//  }
}

void players_movement(int player1, int player2, int key_id) {

  switch (key_id) {
    case 'k':
      if (player2 > 0) {
        player2--;
      }
      break;
    case 'm':
      if ((player2 + PLAYER_SIZE) < TERM_SIZE_Y) {
        player2++;
      }
      break;
    case 'a':
      if (player1 > 0) {
        player1--;
      }
      break;
    case 'z':
      if ((player1 + PLAYER_SIZE) < TERM_SIZE_Y) {
        player1++;
      };
      break;
    default:break;
  }

}

void display(int player1, int player2, int ball_x, int ball_y) {

  char cross = 'X';
  char ball = '0';
  char space = ' ';

  // int field[term_size_x][term_size_y] = {0};

  for (int i = 1; i <= TERM_SIZE_Y; i++) {
    for (int j = 1; j <= TERM_SIZE_X; j++) {
      // рисуем мяч
      if (i == ball_  && j == ball_x) {
        printf("%c", ball);
      } 
      
      // рисуем игрока 1
      else if (i == 1 && j == player1) {
        printf("%c", cross);
      }
      else if (i == 1 && j == player1 + 1) {
        printf("%c", cross);
      }
      else if (i == 1 && j == player1 + 2) {
        printf("%c", cross);
      }

      // рисуем игрока 2
      else if (i == TERM_SIZE_X && j == player2) {
        printf("%c", cross);
      }
      else if (i == TERM_SIZE_X && j == player2 + 1) {
        printf("%c", cross);
      }
      else if (i == TERM_SIZE_X && j == player2 + 2) {
        printf("%c", cross);
      }
      
      // пустота
      else {
        printf("%c", space);
      }

//      if (i == "cross_pos") {
//        printf("%c", cross);
//      } else if (i == toe_pos) {
//        printf("%c", toe);
//      } else {
//        printf("%c", space);
    }
  }
}

void sleeping_time() {
  sleep(1);
}

int pressing_key() {

  char c = 'a';
  printf("Enter key or enter \"Q\" to exit:\n");
  scanf("%c", &c);

  return c;
}


