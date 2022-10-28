#include "..\headers\utils\player_utils.h"

char    what_key(t_player player, int key)
{
    if (key == UP_KEY)
        return(player.up_key);
    else if (key == DOWN_KEY)
        return(player.down_key);
    else if (key == LEFT_KEY)
        return(player.left_key);
    else if (key == RIGHT_KEY)
        return(player.right_key);
    return (0);
}

void     change_pl_pos(t_player player[], int which_one, int x, int y)
{
    char avatar;

    if (which_one == PLAYER_ONE)
        avatar = PLAYER_ONE_CHAR;
    else
        avatar = PLAYER_TWO_CHAR;
    edit_map_xy(' ', player[which_one].x, player[which_one].y);
    player[which_one].x = x;
    player[which_one].y = y;
    edit_map_xy(avatar, player[which_one].x, player[which_one].y);
}

void     keys_handler(t_player *player)
{
    static short    first;
    short           flag;

    if (first == 0)
    {
        player[0].up_key = 'w';
        player[0].down_key = 's';
        player[0].left_key = 'a';
        player[0].right_key = 'd';
        player[1].up_key = 'i';
        player[1].down_key = 'k';
        player[1].left_key = 'j';
        player[1].right_key = 'l';
        first = 1;
    }
    else
    {
        flag = 0;
        if (rand() % 2)
            switch_keys(&player[0].up_key, &player[1].up_key, &flag);
        if (rand() % 2)
            switch_keys(&player[0].down_key, &player[1].down_key, &flag);
        if (rand() % 2)
            switch_keys(&player[0].left_key, &player[1].left_key, &flag);
        if (rand() % 2)
            switch_keys(&player[0].right_key, &player[1].right_key, &flag);
        if (flag == 0)
            keys_handler(player);
    }
}

void    switch_keys(char *key_one, char *key_two, short *flag)
{
    char    temp;

    temp = *key_one;
    *key_one = *key_two;
    *key_two = temp;
    *flag = 1;
}
