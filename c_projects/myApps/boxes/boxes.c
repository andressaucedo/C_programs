#include <raylib.h>
int main(int argc, char const *argv[]) {

    InitWindow(800, 800, "My Cool Program");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You greated your first window!",
        190,200,20,LIGHTGRAY);

        DrawRectangle(GetMouseX() - 50, GetMouseY() - 50, 100,100, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
