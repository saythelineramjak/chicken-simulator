
#include "raylib.h"

 Texture2D atlas;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "chicken simulator");
    InitAudioDevice();
    Image image = LoadImage("chknres/ckhn.png");
    Image big = LoadImage("chknres/bigckhn.png");
    Sound caw = LoadSound("chknres/ckhnsound.wav");
    Texture2D texture = LoadTextureFromImage(image);
    Texture2D bigtex = LoadTextureFromImage(big);
    UnloadImage(image); 
    UnloadImage (big);
    SetTargetFPS(60);               
    
    int count=1;
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        BeginDrawing();

            ClearBackground(BLUE);
            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
            DrawText ("You have simulated the chicken this many times:", 0, 0, 20, WHITE);
             DrawText (TextFormat("%i", count), 500, 0, 50, RED);
           
           if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) PlaySound (caw);
           if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) DrawTexture(bigtex, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
           if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){count = count + 1;}
        EndDrawing();
    };
      
   
    CloseWindow();   
    UnloadTexture(texture);
    UnloadTexture(bigtex);
    UnloadSound (caw);  
       

    return 0;
}