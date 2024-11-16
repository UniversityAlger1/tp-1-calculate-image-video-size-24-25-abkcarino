#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored section)
//   durationCredits: duration in seconds of the credits (black-and-white section)
//   fps: frames per second of the video
//   unit: Unit of the output value. It could be 'bt' (bits), 'ko' (kilobits), 'mo' (megabits), 'go' (gigabits)
// Return value:
//   Total video size in the specified unit
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Frame size for the colored section (3 bytes per pixel, with padding)
   
    int frameSizeColor = w * h * 3; // Size of one color frame in bytes

    // Frame size for the black-and-white section (1 byte per pixel, with padding)
  
    int frameSizeBW = w * h; // Size of one black-and-white frame in bytes

    // Total frames in each section
    int totalFramesMovie = durationMovie * fps;
    int totalFramesCredits = durationCredits * fps;

    // Total size in bytes for each section
    long long totalBytesMovie = (long long)frameSizeColor * totalFramesMovie;
    long long totalBytesCredits = (long long)frameSizeBW * totalFramesCredits;

    // Total size in bytes for the entire video
    long long totalBytes = totalBytesMovie + totalBytesCredits;

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
