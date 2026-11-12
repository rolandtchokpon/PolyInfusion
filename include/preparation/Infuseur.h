
#pragma once

#include "../../include/distributeurEau/DistributeurEau.h"
#include "../../include/distributeurThe/DistributeurThe.h"
#include "../../include/systemeChauffage/SystemeChauffage.h"

namespace Machine {

    class Infuseur {
        public:
            Infuseur(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage);
            void infuser(const std::string& the);

            virtual ~Infuseur();
        
        private:
            DistributeurEau* distributeurEau_;
            DistributeurThe* distributeurThe_;
            SystemeChauffage* systemeChauffage_;
    };

} // namespace Machine