#include <raylib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int windowWidth, windowHeight, i,j;
    int box,step;
    int flag,start;
    windowWidth = 600;
    windowHeight = 600;
    box = windowWidth/8;
    step = box * 2;


    //SetConfigFlags(FLAG_WINDOW_RESIZABLE);    // Window configuration flags
    //InitWindow(GetWinLength(), GetWinHeight(), "Window title");
    InitWindow(windowWidth, windowHeight,"Boxes");
    SetWindowMinSize(400,400);
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

/*        DrawText("Congrats! You created your first window!",
        50,200,14,LIGHTGRAY);
        DrawRectangle(GetMouseX() - 50, GetMouseY() - 50, 100,100, RED);*/


    for(j=0, flag=1; j <= (windowHeight - box); j += box, flag++)
    {
        for(i=start;i <= (windowWidth - box);i += step)
        {
            DrawRectangle(i,j,box,box,RED);
        }
        if(flag % 2 == 0)
        {
            start = box;
        }
        else
        {
            start = 0;
        }
    }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
