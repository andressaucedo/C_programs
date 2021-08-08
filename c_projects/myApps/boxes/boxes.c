#include <raylib.h>
int main(int argc, char const *argv[]) {
    int winLength, winHeight, i,x;
    int box;
    winLength = 400;
    winHeight = 400;
    box = winHeight/8;
    InitWindow(winLength, winHeight, "My Cool Program");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!",
        50,200,14,LIGHTGRAY);

//        DrawRectangle(GetMouseX() - 50, GetMouseY() - 50, 100,100, RED);

      for(i = 1, x =0; i <= 8; x += (box * 2)){
        DrawRectangle(x, 0 , box, box ,RED);
      //  x = i*box;
      }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
