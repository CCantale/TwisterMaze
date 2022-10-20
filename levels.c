#include "headers/levels.h"

void    level1(void)
{
    char    *level;

    level = alloc_string(" \n \n \n"
                        "           _______________________________________\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "          |                                        |\n"
                        "           _______________________________________\n");

    edit_map(ft_split(level));
}
