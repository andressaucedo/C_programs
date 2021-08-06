#include <raylib.h>
int main(int argc, char const *argv[]) {

    InitWindow(800, 600, "My Cool Program");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You greated your first window!",
        190,200,20,LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
