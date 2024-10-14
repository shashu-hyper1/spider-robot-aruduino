#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Left eye parameters
int leftEyeX = SCREEN_WIDTH / 3 - 10; // Move the left eye slightly left
int leftEyeY = SCREEN_HEIGHT / 2;
int eyeRadius = 20;
int pupilRadius = 5;

// Right eye parameters
int rightEyeX = 2 * SCREEN_WIDTH / 3 + 10; // Move the right eye slightly right
int rightEyeY = SCREEN_HEIGHT / 2;

void setup() {
  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
}

void loop() {
  // For testing, you can call each function one by one.
  forward();   // Call forward() to center the pupils
  delay(1000); // Wait for 1 second

  backward();  // Call backward() to move pupils down
  delay(1000); // Wait for 1 second

  left();      // Call left() to move pupils left
  delay(1000); // Wait for 1 second

  right();     // Call right() to move pupils right
  delay(1000); // Wait for 1 second

  happy();     // Call happy() to animate pupils in a crazy manner
  delay(2000); // Wait for 2 seconds to see the animation

  angry();     // Call angry() to make the pupils look angry
  delay(2000); // Wait for 2 seconds to see the animation
}

// Function to center pupils (forward movement)
void forward() {
  // Clear previous frame
  display.clearDisplay();

  // Draw left eyeball and center pupil
  display.drawCircle(leftEyeX, leftEyeY, eyeRadius, WHITE);
  display.fillCircle(leftEyeX, leftEyeY, pupilRadius, WHITE);

  // Draw right eyeball and center pupil
  display.drawCircle(rightEyeX, rightEyeY, eyeRadius, WHITE);
  display.fillCircle(rightEyeX, rightEyeY, pupilRadius, WHITE);

  // Display everything
  display.display();
}

// Function to move pupils down (backward movement)
void backward() {
  // Clear previous frame
  display.clearDisplay();

  // Draw left eyeball and move pupil down
  display.drawCircle(leftEyeX, leftEyeY, eyeRadius, WHITE);
  display.fillCircle(leftEyeX, leftEyeY + eyeRadius / 2, pupilRadius, WHITE);

  // Draw right eyeball and move pupil down
  display.drawCircle(rightEyeX, rightEyeY, eyeRadius, WHITE);
  display.fillCircle(rightEyeX, rightEyeY + eyeRadius / 2, pupilRadius, WHITE);

  // Display everything
  display.display();
}

// Function to move pupils left (left movement)
void left() {
  // Clear previous frame
  display.clearDisplay();

  // Draw left eyeball and move pupil left
  display.drawCircle(leftEyeX, leftEyeY, eyeRadius, WHITE);
  display.fillCircle(leftEyeX - eyeRadius / 2, leftEyeY, pupilRadius, WHITE);

  // Draw right eyeball and move pupil left
  display.drawCircle(rightEyeX, rightEyeY, eyeRadius, WHITE);
  display.fillCircle(rightEyeX - eyeRadius / 2, rightEyeY, pupilRadius, WHITE);

  // Display everything
  display.display();
}

// Function to move pupils right (right movement)
void right() {
  // Clear previous frame
  display.clearDisplay();

  // Draw left eyeball and move pupil right
  display.drawCircle(leftEyeX, leftEyeY, eyeRadius, WHITE);
  display.fillCircle(leftEyeX + eyeRadius / 2, leftEyeY, pupilRadius, WHITE);

  // Draw right eyeball and move pupil right
  display.drawCircle(rightEyeX, rightEyeY, eyeRadius, WHITE);
  display.fillCircle(rightEyeX + eyeRadius / 2, rightEyeY, pupilRadius, WHITE);

  // Display everything
  display.display();
}

// Function to animate pupils in a crazy happy manner
void happy() {
  // Parameters for animation
  int amplitude = 15; // Increased movement amplitude
  int speed = 30;     // Speed of the animation

  for (int i = 0; i < 100; i++) {
    // Calculate random movement offsets
    int xOffset = random(-amplitude, amplitude);
    int yOffset = random(-amplitude, amplitude);

    // Clear previous frame
    display.clearDisplay();

    // Draw left eyeball and move pupil
    display.drawCircle(leftEyeX, leftEyeY, eyeRadius, WHITE);
    display.fillCircle(leftEyeX + xOffset, leftEyeY + yOffset, pupilRadius, WHITE);

    // Draw right eyeball and move pupil
    display.drawCircle(rightEyeX, rightEyeY, eyeRadius, WHITE);
    display.fillCircle(rightEyeX + xOffset, rightEyeY + yOffset, pupilRadius, WHITE);

    // Display everything
    display.display();

    // Wait for the next frame
    delay(speed);
  }
}

// Function to animate pupils in an angry manner
void angry() {
  // Parameters for animation
  int cornerOffset = 10; // Offset for angry pupils
  int speed = 100;       // Speed of the animation

  for (int i = 0; i < 10; i++) {
    // Clear previous frame
    display.clearDisplay();

    // Draw left eyeball as a semicircle (upper half)
    display.drawCircle(leftEyeX, leftEyeY, eyeRadius, WHITE);
    display.fillRect(leftEyeX - eyeRadius, leftEyeY, 2 * eyeRadius, eyeRadius, BLACK); // Hide lower half

    // Draw pupil at the top-right corner of the semicircle
    display.fillCircle(leftEyeX + eyeRadius / 2 - cornerOffset, leftEyeY - eyeRadius / 2 + cornerOffset, pupilRadius, WHITE);

    // Draw right eyeball as a semicircle (upper half)
    display.drawCircle(rightEyeX, rightEyeY, eyeRadius, WHITE);
    display.fillRect(rightEyeX - eyeRadius, rightEyeY, 2 * eyeRadius, eyeRadius, BLACK); // Hide lower half

    // Draw pupil at the top-right corner of the semicircle
    display.fillCircle(rightEyeX + eyeRadius / 2 - cornerOffset, rightEyeY - eyeRadius / 2 + cornerOffset, pupilRadius, WHITE);

    // Display everything
    display.display();

    // Wait for the next frame
    delay(speed);

    // Clear previous frame
    display.clearDisplay();

    // Draw left eyeball as a semicircle (lower half)
    display.drawCircle(leftEyeX, leftEyeY, eyeRadius, WHITE);
    display.fillRect(leftEyeX - eyeRadius, leftEyeY - eyeRadius, 2 * eyeRadius, eyeRadius, BLACK); // Hide upper half

    // Draw pupil at the bottom-left corner of the semicircle
    display.fillCircle(leftEyeX - eyeRadius / 2 + cornerOffset, leftEyeY + eyeRadius / 2 - cornerOffset, pupilRadius, WHITE);

    // Draw right eyeball as a semicircle (lower half)
    display.drawCircle(rightEyeX, rightEyeY, eyeRadius, WHITE);
    display.fillRect(rightEyeX - eyeRadius, rightEyeY - eyeRadius, 2 * eyeRadius, eyeRadius, BLACK); // Hide upper half

    // Draw pupil at the bottom-left corner of the semicircle
    display.fillCircle(rightEyeX - eyeRadius / 2 + cornerOffset, rightEyeY + eyeRadius / 2 - cornerOffset, pupilRadius, WHITE);

    // Display everything
    display.display();

    // Wait for the next frame
    delay(speed);
  }
}
