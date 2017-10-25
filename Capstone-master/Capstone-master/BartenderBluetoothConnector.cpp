#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

int main( int argc, char **argv ){

    if( argc < 2 ){
        printf("Ensure you select what kind of drink you would like!\n
             A: SampleDrink1\n B: SampleDrink2\n C: SampleDrink3\n D: SampleDrink4\n E: SampleDrink5\n");
        return 0;
    }
    if( argv[1] != "A" || argv[1] != "B" || argv[1] != "C" || argv[1] != "D" ){
        printf("You have selected an invalid drink option. \nPlease select one of the following:\n
            A: SampleDrink1\n B: SampleDrink2\n C: SampleDrink3\n D: SampleDrink4\n E: SampleDrink5\n");
        return 0;
    }

    //Start bluetooth
    //Send argv[1]

    printf("Your drink will be made shortly!");
    return 0;

}