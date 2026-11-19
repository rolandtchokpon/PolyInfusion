
#pragma once

#include "DistributeurThe.h"

namespace Machine
{

    class DistributeurTheCompact : public DistributeurThe
    {
    public:
        DistributeurTheCompact(Reserve *reserve);
        virtual ~DistributeurTheCompact();
    };

} // namespace Machine