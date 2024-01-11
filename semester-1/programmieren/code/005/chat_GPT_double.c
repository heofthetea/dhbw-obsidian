#include <stdio.h>

void printBytes(double value)
{
    unsigned char *bytePtr = (unsigned char *)&value;

    printf("Bytes of double %.2f are: ", value);

    for (int i = 0; i < sizeof(double); ++i)
    {
        printf("%02X ", bytePtr[i]);
    }

    printf("\n");
}

int main()
{
    //double myDouble = 3.14159; // Replace this with your desired double value
    double myDouble = -88.125;

    printBytes(myDouble);

    return 0;
}
