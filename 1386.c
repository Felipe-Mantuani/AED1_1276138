#include <stdio.h>
#include <string.h>

int main(void) {
    int n, caso = 1;
    char palavras[100][51];

    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%s", palavras[i]);
        }

        int decodificavel = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && strlen(palavras[i]) < strlen(palavras[j]) &&
                    strncmp(palavras[i], palavras[j], strlen(palavras[i])) == 0) {
                    decodificavel = 0;
                    break;
                }
            }
            if (!decodificavel) {
                break;
            }
        }

        if (decodificavel) {
            printf("Set %d is immediately decodable\n", caso++);
        } else {
            printf("Set %d is not immediately decodable\n", caso++);
        }
    }

    return 0;
}
