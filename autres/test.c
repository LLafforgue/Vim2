#include <stdlib.h>

int count_tokens(const char* str, char delim) {
    int count = 0;
    while (*str) {
        if (*str == delim) count++;
        str++;
    }
    return count + 1;
}

char** split(const char* str, char delim, int* count) {
    *count = count_tokens(str, delim);
    char** result = malloc(*count * sizeof(char*));
    if (!result) return NULL;

    int i = 0;
    const char* start = str;
    while (*str) {
        if (*str == delim) {
            int len = str - start;
            result[i] = malloc(len + 1);
            if (!result[i]) {
                for (int j = 0; j < i; j++) free(result[j]);
                free(result);
                *count = 0;
                return NULL;
            }
            for (int j = 0; j < len; j++) result[i][j] = start[j];
            result[i][len] = '\0';
            i++;
            start = str + 1;
        }
        str++;
    }
    // Dernier token
    int len = str - start;
    result[i] = malloc(len + 1);
    if (!result[i]) {
        for (int j = 0; j < i; j++) free(result[j]);
        free(result);
        *count = 0;
        return NULL;
    }
    for (int j = 0; j < len; j++) result[i][j] = start[j];
    result[i][len] = '\0';

    return result;
}

void free_split(char** tokens, int count) {
    for (int i = 0; i < count; i++) free(tokens[i]);
    free(tokens);
}

int main() {
    const char* str = "bonjour,tout,le,monde";
    char delim = ',';
    int count = 0;

    char** tokens = split(str, delim, &count);
    if (tokens) {
        for (int i = 0; i < count; i++) {
            // Utilisez tokens[i]
            free(tokens[i]);
        }
        free(tokens);
    }
    return 0;
}
