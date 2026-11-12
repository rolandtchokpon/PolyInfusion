
#pragma once

#include "../../include/distributeurEau/DistributeurEau.h"
#include "../../include/distributeurThe/DistributeurThe.h"
#include "../../include/systemeChauffage/SystemeChauffage.h"

namespace Machine {

    class Rinceur {
        public:
            Rinceur(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage);
            void rincer(const std::string& the);

            virtual ~Rinceur();
        
        private:
            DistributeurEau* distributeurEau_;
            DistributeurThe* distributeurThe_;
            SystemeChauffage* systemeChauffage_;
    };

} // namespace Machine
