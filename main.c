#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#define WIDTH 640
#define HEIGHT 480
#define PADDLE_HEIGHT 80
#define PADDLE_WIDTH 10
#define BALL_SIZE 10
int leftY, rightY;
int ballX, ballY;
int ballDX, ballDY;
int leftScore = 0, rightScore = 0;
void drawGame() {
char score[50];
cleardevice();
line(WIDTH/2, 0, WIDTH/2, HEIGHT);
bar(20, leftY, 20+PADDLE_WIDTH, leftY+PADDLE_HEIGHT);
bar(WIDTH-30, rightY, WIDTH-30+PADDLE_WIDTH, rightY+PADDLE_HEIGHT);
bar(ballX, ballY, ballX+BALL_SIZE, ballY+BALL_SIZE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
sprintf(score, "%d | %d", leftScore, rightScore);
outtextxy(WIDTH/2 - 40, 10, score);
delay(15);
}
void resetBall(int direction) {

ballX = WIDTH/2;
ballY = HEIGHT/2;
ballDX = direction * 4;
ballDY = (rand() % 2 ? 3 : -3);
}
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
randomize();
leftY = HEIGHT/2 - PADDLE_HEIGHT/2;
rightY = HEIGHT/2 - PADDLE_HEIGHT/2;
resetBall( (rand()%2) ? 1 : -1 );
while(1) {
if (kbhit()) {
char ch = getch();
if (ch == 27) break; // ESC to quit
if (ch == 'w' || ch == 'W') leftY -= 15;
if (ch == 's' || ch == 'S') leftY += 15;
if (ch == 0) { // extended key
ch = getch();
if (ch == 72) rightY -= 15; // Up
if (ch == 80) rightY += 15; // Down
}
}
ballX += ballDX;
ballY += ballDY;
if (ballY <= 0 || ballY+BALL_SIZE >= HEIGHT)

ballDY = -ballDY;
if (ballX <= 20+PADDLE_WIDTH &&
ballY+BALL_SIZE >= leftY &&
ballY <= leftY+PADDLE_HEIGHT) {
ballDX = -ballDX;
}
if (ballX+BALL_SIZE >= WIDTH-30 &&
ballY+BALL_SIZE >= rightY &&
ballY <= rightY+PADDLE_HEIGHT) {
ballDX = -ballDX;
}
if (ballX <= 0) {
rightScore++;
resetBall(1);
}
if (ballX >= WIDTH) {
leftScore++;
resetBall(-1);

drawGame();
}
closegraph();
return 0;
}
