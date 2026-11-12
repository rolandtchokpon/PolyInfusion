#pragma once

#include <string>
#include <iostream>

namespace Machine {

    class SystemeChauffage {
        public:
            virtual ~SystemeChauffage() = 0;

            void chaufferEauRincage(double temperature);
            void chaufferEau(double temperature);
        
        protected:
            SystemeChauffage(double vitesse);

            double vitesse_;
    };

} // namespace Machine