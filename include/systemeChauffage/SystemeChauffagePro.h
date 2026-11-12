#pragma once

#include <string>
#include <iostream>
#include "SystemeChauffage.h"

namespace Machine {

    class SystemeChauffagePro : public SystemeChauffage {
        public:
            SystemeChauffagePro();
            virtual ~SystemeChauffagePro();
    };

} // namespace Machine