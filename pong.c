include <stdio.h>
// include conio.h file for kbhit function
#include <conio.h>
#include <unistd.h>  //Для sleep

void display(int cross_pos, int toe_pos);
int pressing_key(void);
void sleeping_time();

int main() {
    int cross_position, toe_position;
    printf("Enter the \"X\" and \"O\" position:");

    if (scanf("%d%d", &cross_position, &toe_position) != 2 || cross_position < 0 || toe_position < 0) {
        printf("Invalid position");
        return -1;
    }

    int key_id = 0;
    int esc_key = 27;
    while (key_id != esc_key) {
      key_id = pressing_key();
      display(cross_position, toe_position);
      sleeping_time();
    }
}

void display(int cross_pos, int toe_pos) {
    int term_size_x = 80;
    int term_size_y = 25;

    char cross = 'X';
    char toe = '0';
    char space = ' ';

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
