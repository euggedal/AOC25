#include <stdio.h>
int main() {
    FILE *file = fopen("./input.txt", "r");
    if (file == NULL) {
        perror("Could not open filesssre");
        return 1;
    }
    int position = 50;
    int zero_count = 0;
    char direction;
    int distance;
    while (fscanf(file, "%c%d\n", &direction, &distance) != EOF) {
        if (direction == 'L') {
            position = (position - distance + 100) % 100;
        } else if (direction == 'R') {
            position = (position + distance) % 100;
        }

        if (direction == 'L') {
            for (int i = 1; i <= distance; i++) {
                int current_position = (position + i) % 100;
                if (current_position == 0) {
                    zero_count++;
                }
            }
        } else if (direction == 'R') {
            for (int i = 1; i <= distance; i++) {
                int current_position = (position - i + 100) % 100;
                if (current_position == 0) {
                    zero_count++;
                }
            }
        }
    }
    fclose(file);
    printf("The password to open the door is: %d\n", zero_count);
    return 0;
}
