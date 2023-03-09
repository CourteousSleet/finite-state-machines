#include "stdio.h"
#include "string.h"

#define MAX_STRING_LENGTH 1024

typedef enum {
  STATE_INITIAL,
  STATE_TWO,
  STATE_THREE,
  STATE_FOUR,
  STATE_SIX,
  STATE_ACCEPT,
  STATE_ILLEGAL
} state_t;

char* get_states(state_t current_state) {
  if (current_state == STATE_INITIAL) return "q1";
  else if (current_state == STATE_TWO) return "q2";
  else if (current_state == STATE_THREE) return "q3";
  else if (current_state == STATE_FOUR) return "q4";
  else if (current_state == STATE_ACCEPT) return "q5";
  else if (current_state == STATE_SIX) return "q6";
}

state_t transition(state_t current_state, char input) {
  if (input != '0' && input != '1') return STATE_ILLEGAL;
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
  fgets(input, sizeof(input), stdin);

  if (input[0] == '\n') {
    printf("Empty string.\nString rejected.\n");
    return 1;
  }

  state_t current = STATE_INITIAL;
  int len = strlen(input);

  printf("q1 --> ");

  for (int i = 0; i < len - 1; i++) {
    current = transition(current, input[i]);
    if (current == STATE_ILLEGAL) break;
    char* state = get_states(current);
    char* plug = "--> ";
    printf("%s ", state);
    if (i != len -1) printf ("%s", plug);
  }

  if (current == STATE_ACCEPT) {
    printf("String accepted.\n");
    return 0;
  } else if (current == STATE_ILLEGAL) {
    printf("Illegal alphabet. String rejected.\n");
  } else {
    printf("String rejected.\n");
  }

  return 0;
}
