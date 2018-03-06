/**
 * April Fools' Mouse Prank
 * Date: February 27, 2018
 * Author: Shawn Hymel (SparkFun Electronics)
 * 
 * Upload this to a SparkFun Pro Micro, and plug it into an 
 * unsuspecting computer. That's it!
 * 
 * This sketch was written by SparkFun Electronics, with lots of
 * help from the Arduino community. This code is completely free
 * for any use.
 */

#include "Mouse.h"

#define DEBUG 0

// Parameters
const int NUM_STATES = 3;             // Number of possible animations
const unsigned long WAIT_MIN = 10000; // ms (inclusive)
const unsigned long WAIT_MAX = 20000; // ms (exclusive)
const unsigned long JUMP_MIN = -1000; // Pixels (inclusive)
const unsigned long JUMP_MAX = 1000;  // Pixels (exclusive)
const int DIR_MIN = 0;                // Degrees (inclusive)
const int DIR_MAX = 360;              // Degrees (exclusive)
const int SPD_MIN = 1;                // Pixels (inclusive)
const int SPD_MAX = 5;                // Pixels (exclusive)
const int LINE_ACC = 10;              // Number of times to accumulate
const int LINE_NUM_MIN = 50;          // Min number of times to move in line
const int LINE_NUM_MAX = 300;         // Max number of times to move in line
const int JITTER_MIN = -4;            // Pixels (inclusive)
const int JITTER_MAX = 5;             // Pixels (exclusive)
const int JITTER_NUM_MIN = 50;        // Min number of times to jitter
const int JITTER_NUM_MAX = 300;       // Max number of times to jitter

// Patterns
typedef enum {
  STATE_JUMP,
  STATE_LINE,
  STATE_JITTER
} mouse_states;

void setup() {
  randomSeed(analogRead(0));

#if DEBUG
  Serial.begin(9600);
#endif
}

void loop() {

  // Wait a random amount of time
  delay(random(WAIT_MIN, WAIT_MAX));

  // Pick a random state
  switch ( random(NUM_STATES) ) {
    case STATE_JUMP:
      mouseJump();
      break;
    case STATE_LINE:
      mouseLine();
      break;
    case STATE_JITTER:
      mouseJitter();
      break;
    default:
      break;
  }
}

void mouseJump() {
  Mouse.move(random(JUMP_MIN, JUMP_MAX), random(JUMP_MIN, JUMP_MAX), 0);
}

void mouseLine() {

  // Pick a random direction and speed
  int dir_deg = random(DIR_MIN, DIR_MAX);
  float dir = dir_deg * (PI / 180);
  float spd = (float)random(SPD_MIN, SPD_MAX) / LINE_ACC;
  float x = spd * cos(dir);
  float y = spd * sin(dir);
  float x_acc;
  float y_acc;
  int line_num = random(LINE_NUM_MIN, LINE_NUM_MAX);

#if DEBUG
  Serial.print("Speed: ");
  Serial.print(spd);
  Serial.print(" | Dir: ");
  Serial.print(dir_deg);
  Serial.print(" deg ");
  Serial.print(dir);
  Serial.print(" rad | x:");
  Serial.print(x);
  Serial.print(" y:");
  Serial.println(y);
#endif

  // Move mouse in a line for a random number of times
  for ( int j = 0; j < line_num; j++ ) {

    // Accumulate the motion for a few times, round it, and apply
    x_acc = 0;
    y_acc = 0;
    for ( int i = 0; i < LINE_ACC; i++ ) {
      x_acc += x;
      y_acc += y;
    }
    Mouse.move((int)(x_acc + 0.5), (int)(y_acc + 0.5), 0);

    delay(10);
  }

#if DEBUG
  Serial.print("Moving x:");
  Serial.print((int)(x_acc + 0.5));
  Serial.print(" y:");
  Serial.println((int)(y_acc + 0.5));
#endif
}

void mouseJitter() {

  int jitter_times = random(JITTER_NUM_MIN, JITTER_NUM_MAX);
  
  // Cause the mouse to jitter some random amount
  for ( int i = 0; i < jitter_times; i++ ) {
    Mouse.move(random(JITTER_MIN, JITTER_MAX), random(JITTER_MIN, JITTER_MAX), 0);
    delay(10);
  }
}

