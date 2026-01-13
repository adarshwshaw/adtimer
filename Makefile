RAYLIB ?= /home/adarsh/Documents/dev/raylib-5.5_linux_amd64

adtimer: adtimer.c
	gcc -std=c99 -Wall -Wextra -o $@ $^ -I$(RAYLIB)/include -L$(RAYLIB)/lib -l:libraylib.a -lGL -lm -ldl -lrt -lpthread -lX11
