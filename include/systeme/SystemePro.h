
#pragma once

#include "Systeme.h"
#include "../../include/distributeurEau/DistributeurEauPro.h"
#include "../../include/distributeurThe/DistributeurThePro.h"
#include "../../include/systemeChauffage/SystemeChauffagePro.h"

namespace Machine {

    class SystemePro : public Systeme {
        public:
            SystemePro(std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau, std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff);
            virtual ~SystemePro();
    };

} // namespace Machine