#include "prof.h"
#include <raylib.h>

Prof_Define(subframe);

int main(void)
{
    InitWindow(800, 600, "IProf");

    prof_report_t report = {0};

    while (!WindowShouldClose()) {
        BeginDrawing();
        Prof_Begin(frame)
        ClearBackground(GetColor(0x181818FF));
        DrawFPS(10, 10);
        for (int i = 0; i < report.nrecords; ++i) {
            DrawText(TextFormat("%s: %.2f %.2f %.2f", report.records[i].name, report.records[i].self, report.records[i].hier, report.records[i].count), 
                    10, 30+(i*16), 16, WHITE);
        }
        Prof_End
        EndDrawing();
        Prof_update(true);

        Prof_get_report(&report);
    }

    CloseWindow();
    return 0;
}
