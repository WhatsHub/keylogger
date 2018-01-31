#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>

int main(int argc, char** argv){

    int fd, bytes;
    struct input_event data;

    const char *pDevice = "/dev/input/event1";

    // Open Keyboard
    fd = open(pDevice, O_RDONLY | O_NONBLOCK);
    if(fd == -1){

        printf("ERROR Opening %s\n", pDevice);
        return -1;
    }

    while(1)
    {
        // Read Keyboard Data
        bytes = read(fd, &data, sizeof(data));
        if(bytes > 0)
        {
	    if(data.value == KEY_W){
	    	printf(" DER W-KEY WURDE GEDRUECKT!!!\n ");
	    }
            printf("Keypress value=%x, type=%x, code=%x\n", data.value, data.type, data.code);
        }
        else
        {
            // Nothing read
	    printf("Nothing to read\n");
            sleep(1);
        }
    }

    return 0;
 }
