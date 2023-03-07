#include "stdio.h"
#include "stdbool.h"
#include "string.h"

#define MAX_STRING_LENGTH 1024

typedef enum {
  STATE_INITIAL,
  STATE_TWO,
  STATE_THREE,
  STATE_FOUR,
  STATE_SIX,
  STATE_ACCEPT
} state_t;

state_t transition(state_t current_state, char input) {
  if (current_state == STATE_INITIAL) {
    if (input == '0') return STATE_TWO;
    else return STATE_SIX;
  } else if (current_state == STATE_TWO) {
    if (input == '0') return STATE_TWO;
    else return STATE_THREE;
  } else if (current_state == STATE_THREE) {
    if (input == '0') return STATE_FOUR;
    else return STATE_TWO;
  } else if (current_state == STATE_FOUR) {
    if (input == '0') return STATE_TWO;
    else return STATE_ACCEPT;
  } else if (current_state == STATE_SIX) {
    if (input == '0') return STATE_TWO;
    else return STATE_SIX;
  } else if (current_state == STATE_ACCEPT) {
    return STATE_ACCEPT;
  }
}


int main() {
  char input[MAX_STRING_LENGTH];
  printf("Enter the input string: ");
  scanf("%s", input);

  state_t current = STATE_INITIAL;
  int len = strlen(input);

  for (int i = 0; i < len; i++) {
    current = transition(current, input[i]);
  }

  if (current == STATE_ACCEPT) {
    printf("String accepted.\n");
    return 0;
  }
  else
    printf("String rejected.\n");

  return 0;
}
