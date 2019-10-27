#include <stdio.h>
#include <stdlib.h>

namespace GLEngine {
    static void FatalError(std::string error) {
        error = "\nFATAL ERROR: " + error + "\n";
        std::printf("%s", error.c_str());
        exit(EXIT_FAILURE);
    }
}
