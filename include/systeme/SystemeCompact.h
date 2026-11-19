
#pragma once

#include "Systeme.h"
#include "../../include/distributeurEau/DistributeurEauCompact.h"
#include "../../include/distributeurThe/DistributeurTheCompact.h"
#include "../../include/systemeChauffage/SystemeChauffageCompact.h"

namespace Machine {

    class SystemeCompact : public Systeme {
        public:
            SystemeCompact(std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau, std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff);
            virtual ~SystemeCompact();
    };

} // namespace Machine