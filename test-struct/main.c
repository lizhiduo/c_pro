#include <stdio.h>
#include <stdlib.h>

struct dev{
    int state;
    char name[20];
    struct dev_sub *dat;
};

struct dev_sub{
    int data;
    struct dev *pdev;
};

int main()
{

    struct dev *pdev = NULL;


    pdev = malloc(sizeof(struct dev) + 2 * sizeof(struct dev_sub));




    free(pdev);

    printf("Hello world!\n");
    return 0;
}
