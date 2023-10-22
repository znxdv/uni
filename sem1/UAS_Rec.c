#include <stdio.h>

void hanoi(int disks, char source, char target, char auxiliary) {
    if (disks == 1) {
        // If there's only one disk, move it directly from the source peg to the target peg
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    
    // Move (disks - 1) disks from the source peg to the auxiliary peg using the target peg as auxiliary
    hanoi(disks - 1, source, auxiliary, target);
    
    // Move the remaining disk from the source peg to the target peg
    printf("Move disk %d from %c to %c\n", disks, source, target);
    
    // Move (disks - 1) disks from the auxiliary peg to the target peg using the source peg as auxiliary
    hanoi(disks - 1, auxiliary, target, source);
}

int main() {
    printf("\033[2J\033[1;1H");  // Clear the console screen.
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    puts("");
    hanoi(disks, 'A', 'C', 'B');
    return 0;
}