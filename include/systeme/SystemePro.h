
#pragma once

#include "Systeme.h"
#include "../../include/distributeurEau/DistributeurEauPro.h"
#include "../../include/distributeurThe/DistributeurThePro.h"
#include "../../include/systemeChauffage/SystemeChauffagePro.h"

namespace Machine {

    class SystemePro : public Systeme {
        public:
            SystemePro(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage);
            virtual ~SystemePro();

            virtual void dummy() override {}
    };

} // namespace Machine