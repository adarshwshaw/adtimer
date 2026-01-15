#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define alarm "alarm.mp3"

int main(int argc, char** argv)
{
    int h=0,m=0,s=0;
    for (int i =1;i<argc;i++){
	char* arg=argv[i];
	if (strcmp("-h",arg) == 0){
	    h = atoi(argv[i+1]);
	}else if (strcmp("-m",arg)==0){
	    m = atoi(argv[i+1]);
	}else if (strcmp("-s",arg)==0){
	    s = atoi(argv[i+1]);
	}
    }
    if (argc < 2){
	h=1;
    }
    // SetTraceLogLevel(LOG_NONE);
    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(470, 120, "ADTimer");
    InitAudioDevice();
    SetTargetFPS(24.0);
    char time_str[16]={0};
    float timer=h*3600 + m*60 + s;
    float time_elapse=0;
    Music music = LoadMusicStream(alarm);
    music.looping=true;
    bool playing = false;
    
    while (!WindowShouldClose())
    {
	PollInputEvents();
        BeginDrawing();
            ClearBackground((Color){0x18,0x18,0x18,0xff});
	    time_elapse = GetFrameTime();
	    timer -= time_elapse;
	    if(timer > 0){
		h = timer/3600.0;
		m = ((int)timer%3600)/60;
		s = (int)timer%60;

		sprintf(time_str,"%02d:%02d:%02d",h,m,s);
	    }else {
		if (!playing){
		    PlayMusicStream(music);
		    playing=true;
		}else{
		    UpdateMusicStream(music);
		}
	    }
            DrawText(time_str, 5, 5, 120, LIGHTGRAY);
        EndDrawing();
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    

    return 0;
}
