
#pragma once

#include "Systeme.h"
#include "../../include/distributeurEau/DistributeurEauCompact.h"
#include "../../include/distributeurThe/DistributeurTheCompact.h"
#include "../../include/systemeChauffage/SystemeChauffageCompact.h"

namespace Machine {

    class SystemeCompact : public Systeme {
        public:
            SystemeCompact(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage);
            virtual ~SystemeCompact();

        protected:
            virtual void dummy() override {}
    };

} // namespace Machine