#pragma once

#include <string>
#include <iostream>

namespace Machine {

    class SystemeChauffage {
        public:
            virtual ~SystemeChauffage() = 0;

            // L'eau part toujours de 20 °C ; seule la vitesse change selon le modèle.
            void chaufferEau(double temperature);
            void chaufferEauPreparation(double temperature);
            void chaufferEauRincage(double temperature);

        protected:
            SystemeChauffage(double vitesse);

            double vitesse_;

        private:
            double dureeChauffage(double temperature) const;
    };

} // namespace Machine
