#include <ncurses.h>

int main()
{
    int x, y;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, y, x);

    int pos_y = y / 2;
    int pos_x = x / 2;

    while (1)
    {
        clear();
        mvprintw(pos_y, pos_x, "X");
        refresh();

        // print the coordinates
        mvprintw(0, 0, "y: %d, x: %d", pos_y, pos_x);
        // max y and x
        mvprintw(1, 0, "max y: %d, max x: %d", y - 1, x - 1);

        int ch = getch();
        switch (ch)
        {
        case KEY_UP:
            pos_y--;
            break;
        case KEY_DOWN:
            pos_y++;
            break;
        case KEY_LEFT:
            pos_x--;
            break;
        case KEY_RIGHT:
            pos_x++;
            break;
        }

        if (pos_y < 0)
            pos_y = y - 1;
        else if (pos_y > y - 1)
            pos_y = 0;

        if (pos_x < 0)
            pos_x = x - 1;
        else if (pos_x > x - 1)
            pos_x = 0;
    }

    endwin();
    return 0;
}
