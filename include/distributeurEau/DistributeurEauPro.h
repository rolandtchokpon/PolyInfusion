
#pragma once

#include "DistributeurEau.h"

namespace Machine
{

    class DistributeurEauPro : public DistributeurEau
    {
    public:
        DistributeurEauPro(Reserve *reserve);
        virtual ~DistributeurEauPro();
    };

} // namespace Machine
