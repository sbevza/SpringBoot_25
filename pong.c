include <stdio.h>
// include conio.h file for kbhit function
#include <conio.h>
#include <unistd.h>  //Для sleep

void display(int cross_pos, int toe_pos);
int pressing_key(void);
void sleeping_time();

struct Ball {
  int x;
  int y;
  int direction_x; // 0 - вправо, 1 - влево
  int direction_y; // 0 - вверх, 1 - вниз
} ball;

int main() {
    int term_size_x = 80;
    int term_size_y = 25;

    int win_flag = 0;
    int player_score_1 = 0;
    int player_score_2 = 0; 

    int key_id = 0;
    int esc_key = 27;

    ball.x = 40;
    ball.y = 12;
    ball.direction.x = 1; // 0 - вправо, 1 - влево
    ball.direction_y = 1; // 0 - вверх, 1 - вниз
    
    while (key_id != esc_key) {
      if (has_winner()) {
          break;
      }

      key_id = pressing_key();
      rockets_move(rocket1, rocket2, key_id);

      ball.x += ball.direction_x == 1 ? 1 : -1;

      ball.y += ball.direction_y == 1 ? 1 : -1;
      if (ball_y >= term_size_y) {
        ball_direction_y = 0;
      }
     if (ball_y <= 0) {
        ball_direction_y = 1;
      } 


      display();
      sleeping_time();
    }

    return 0;
}



void display(int cross_pos, int toe_pos) {
    int term_size_x = 80;
    int term_size_y = 25;
  
    int ball_x = 40;
    int ball_y = 12;

    char cross = 'X';
    char toe = '0';
    char space = ' ';

    int field [term_size_x][term_size_y] = {0};

    # int max_pos = (cross_pos > toe_pos) ? cross_pos : toe_pos;
    
    for (int i = 1; i <= term_size_y; i++) {
        for (int j = 1; j <= term_size_x; j++) {
          if (i == cross_pos) {
              printf("%c", cross);
          } else if (i == toe_pos) {
              printf("%c", toe);
          } else {
              printf("%c", space);
          }
        }
    }
}

int pressing_key(void) {
   // declare variable

    char ch;

    printf("Enter key ESC to exit \n");

    // define infinite loop for taking keys

    while (1) {

        if (kbhit) {

            // fetch typed character into ch

            ch = getch();

            if ((int)ch == 27)

                // when esc button is pressed, then it will exit from loop

                break;

            printf("You have entered : %c\n", ch);

        }

    }
void sleeping_time() {
    
     sleep (1);

    }
}
