#include "CipherMap.h"

void CipherMap::default_wiring() {
    for (int idx = 0; idx < ciphermapping.size(); ++idx) {
        ciphermapping[idx] = idx;
    }
}