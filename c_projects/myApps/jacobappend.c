int arg_check(int argc, char **argv, const char *da, const char *ddarg)
{
    int i;
    for (i = 0; i < argc; i++) {
        if ((da && strcmp(argv[i], da) == 0) || (ddarg && strcmp(argv[i], ddarg) == 0)) {
            return i;
        }
    }
    return -1;
}

char *arg_get(int argc, char **argv, const char *da, const char *ddarg)
{
    int i;
    for (i = 0; i < argc; i++) {
        if (((da && strcmp(argv[i], da) == 0) || (ddarg && strcmp(argv[i], ddarg) == 0)) && (i + 1 < argc)) {
            return argv[i + 1];
        }
    }
    return NULL;
}

int file_exists(const char *filename)
{
    struct stat buffer;
    return stat(filename, &buffer) == 0;
}
