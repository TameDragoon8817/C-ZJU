int getindex(char *s)
{
    int week;
    char *day[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (week = 0; week <= 6; week++)
    {
        if (strcmp(s, day[week]) == 0)
            break;
    }
    if (week == 7)
        week = -1;
    return week;
}