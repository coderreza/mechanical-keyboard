#include <conio.h>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int main() {
    
    bool wasDown[256] = { false };

    while (true) {
        for (int vk = 0; vk < 256; ++vk) {
            bool isDown = (GetAsyncKeyState(vk) & 0x8000) != 0;
            if (isDown && !wasDown[vk]) {
                // fresh press of virtual key vk — happens even if
                // your console is not the focused window
                PlaySound(TEXT("click.wav"), NULL,
                    SND_FILENAME | SND_ASYNC);
            }
            wasDown[vk] = isDown;
        }
    }
}