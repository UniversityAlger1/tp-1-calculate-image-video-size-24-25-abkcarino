#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {

    int totalBytes = w * h*3;
    
    // Convert total size to bits (1 byte = 8 bits)
    float totalBits = totalBytes * 8;

    // Convert to the specified unit
    if (strcmp(unit, "bt") == 0) {
        return totalBits; // Size in bits
    } else if (strcmp(unit, "ko") == 0) {
        return totalBits / 1024; // Size in kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return totalBits / (1024 * 1024); // Size in megabits
    } else if (strcmp(unit, "go") == 0) {
        return totalBits / (1024 * 1024 * 1024); // Size in gigabits
    }

    // If the unit is invalid, return 0
    return 0;
}
