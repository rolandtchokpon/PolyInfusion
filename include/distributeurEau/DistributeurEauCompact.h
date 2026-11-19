
#pragma once

#include "DistributeurEau.h"

namespace Machine
{

    class DistributeurEauCompact : public DistributeurEau
    {
    public:
        DistributeurEauCompact(Reserve *reserve);
        virtual ~DistributeurEauCompact();
    };

} // namespace Machine