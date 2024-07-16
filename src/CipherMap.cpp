#include "CipherMap.h"

void CipherMap::default_wiring() {
    int *currentPos = std::begin(ciphermapping);
    int *endPos = std::end(ciphermapping);
    int idx {0};

    while (currentPos != endPos) {
        ciphermapping[idx] = idx;
        ++currentPos;
        ++idx;
    }
}