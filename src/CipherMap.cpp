#include "CipherMap.h"

void CipherMap::default_wiring() {
    int idx {0};
    for (auto currentPos = std::begin(ciphermapping); currentPos != std::end(ciphermapping); ++currentPos, ++idx) {
        ciphermapping[idx] = idx;
    }
}