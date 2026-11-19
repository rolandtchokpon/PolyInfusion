
#pragma once

#include "DistributeurThe.h"

namespace Machine {

    class DistributeurThePro : public DistributeurThe {
        public:
            DistributeurThePro(Reserve *reserve);
            virtual ~DistributeurThePro();
    };

} // namespace Machine