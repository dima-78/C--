#include <iostream>
#include <conio.h>   // _kbhit() и _getch()
#include <windows.h> // sleep() и system("cls")

const int WIDTH = 50;
const int HEIGHT = 10;
bool gameOver;

int dinoPos;
int obstaclePos;
int score;
bool isJumping;
int jumpHeight;

void Setup() {
    gameOver = false;
    dinoPos = HEIGHT - 2;  // позиция дино (немного выше)
    obstaclePos = WIDTH - 1;
    score = 0;
    isJumping = false;
    jumpHeight = 0;
}

void Draw() {
    system("cls");  // чистим консоль

    // верхнюя граница
    std::cout << "+";
    for (int i = 0; i < WIDTH; i++) std::cout << "-";
    std::cout << "+\n";

    // игровое поле
    for (int i = 0; i < HEIGHT; i++) {
        std::cout << "|";
        for (int j = 0; j < WIDTH; j++) {
            if (i == dinoPos && j == 2) {
                std::cout << "R";  // дино
            } else if (i == HEIGHT - 1 && j == obstaclePos) {
                std::cout << "#";  // препятствие
            } else if (i == HEIGHT - 1) {
                std::cout << "_";  // земля
            } else {
                std::cout << " ";
            }
        }
        std::cout << "|\n";
    }

    // нижнюя граница
    std::cout << "+";
    for (int i = 0; i < WIDTH; i++) std::cout << "-";
    std::cout << "+\n";

    std::cout << "Score: " << score << std::endl;
}

void Input() {
    if (_kbhit()) {
        char key = _getch();
        if ((key == ' ' || key == 'w') && !isJumping) {
            isJumping = true;
            jumpHeight = 3;  // высота прыжка
        }
    }
}

void Logic() {
    // прыжок
    if (isJumping) {
        dinoPos--;
        jumpHeight--;
        if (jumpHeight == 0) {
            isJumping = false;
        }
    } else if (dinoPos < HEIGHT - 2) {
        dinoPos++;  // гравитация
    }

    // препятствия
    obstaclePos--;
    if (obstaclePos <= 0) {
        obstaclePos = WIDTH - 1;
        score++;
    }

    // коллизии
    if (obstaclePos == 2 && dinoPos >= HEIGHT - 2) {
        gameOver = true;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(50);  
    }

    std::cout << "Game Over! Final Score: " << score << std::endl;
    std::cout << "Press any key to exit...";
    _getch();  

    return 0;
}
/* #include <iostream>
int main() {
    std::cout << "Hello from MinGW!" << std::endl;
    return 0;
}
*/
