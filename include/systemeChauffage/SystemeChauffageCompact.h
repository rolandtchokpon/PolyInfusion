#pragma once

#include <string>
#include <iostream>
#include "SystemeChauffage.h"

namespace Machine {

    class SystemeChauffageCompact : public SystemeChauffage {
        public:
            SystemeChauffageCompact();
            virtual ~SystemeChauffageCompact();
    };

} // namespace Machine