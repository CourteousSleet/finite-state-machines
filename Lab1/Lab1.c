#include "stdio.h"
#include "stdbool.h"

#define MAX_STRING_LENGTH 1024

typedef enum {
  STATE_INITIAL,
  STATE_ZERO,
  STATE_ONE,
  STATE_ZERO_ONE,
  STATE_ACCEPT
} state_t;

state_t transition(state_t current_state, char input) {
  if (current_state == STATE_INITIAL) {
  
  } else if (current_state == STATE_ZERO) {

  } else if (current_state == STATE_ONE) {

  } else if (current_state == STATE_ZERO_ONE) {

  } else if (current_state = STATE_ACCEPT) {

  }
}

int main() {
  char string[MAX_STRING_LENGTH];
  
}
