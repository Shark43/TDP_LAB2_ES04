#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main( )
{
    FILE *fpR, *fpW;

    if ((fpR = fopen("../testo.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fpW = fopen("../testoFinale.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char nw, lt = EOF, toprint;
    int k = 0, n, m, h = 0;
    while ( (nw = fgetc(fpR) ) != EOF) {
        if(isdigit(nw)) {
            n = (atoi(&nw) + k ) % 10;
            k++;
            fprintf(fpW, "%d", n);
            lt = EOF;
        } else if( (nw >= 'a' && nw <= 'z') || (nw >= 'A' && nw <= 'Z') ) {
            if(lt != EOF) {
                if (!isdigit(lt)) {
                    n = islower(lt) ? 'a' : 'A';
                    m = islower(nw) ? 'a' : 'A';
                    h = abs(((h + lt - n) % 26));
                    toprint = ((nw - m + h) % 26 ) + m;
                    fprintf(fpW, "%c", toprint);
                } else {
                    fprintf(fpW, "%c", nw);
                }
            } else {
                fprintf(fpW, "%c", nw);
            }
            lt = nw;
        } else {
            fprintf(fpW, "%c", nw);
            lt = EOF;
        }

        if(isspace(nw)) {
            lt = EOF;
            h = 0;
        }
    }

    return 0;
}
