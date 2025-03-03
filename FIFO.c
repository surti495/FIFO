#include <stdio.h> 
int main() { 
    int pages[] = {1, 3, 0, 3, 5, 6, 3}; 
    int n = sizeof(pages) / sizeof(pages[0]); 
    int capacity = 3; 
    int frames[3], front = 0, pageFaults = 0; 
    int i, j, found; 
    // Initialize the frames with -1 (representing empty slots) 
    for (i = 0; i < capacity; i++) { 
        frames[i] = -1; 
    } 
    // Process each page in the reference string 
    for (i = 0; i < n; i++) { 
        found = 0; 
        // Check if the page is already in one of the frames 
        for (j = 0; j < capacity; j++) { 
            if (frames[j] == pages[i]) { 
                found = 1; 
                break; 
            } 
        } 
        // If the page is not found in any of the frames, it is a page fault 
        if (!found) { 
            // Replace the page in the current frame 
            frames[front] = pages[i]; 
            front = (front + 1) % capacity; 
            pageFaults++; 
        } 
    } 
    // Print the total number of page faults 
    printf("Total Page Faults (FIFO): %d\n", pageFaults); 
    return 0; 
}