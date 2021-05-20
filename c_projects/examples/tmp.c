#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[128];
    char name[128];
    char value[128];
    FILE *fp;
    int port = 8000;
    int tmp;

    fp = fopen("filename.txt", "r");
    if (!fp) {
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        if (sscanf(buf, "%128s %128s", name, value) == 2) {
            if (strcmp(name, "ipaddress") == 0) {
                printf("My IP is %s\n", value);
            }
            else if (strcmp(name, "portnumber") == 0) {
                if (sscanf(value, "%d", &tmp) == 1) {
                    port = tmp;
                    printf("My Port is: %d\n", port);
                }
                else {
                    fprintf(stderr, "Error: Could not read port number\n");
                }
            }
            else {
                fprintf(stderr, "Unknown value: %s\n", name);
            }
        }
    }

    return 0;
}
