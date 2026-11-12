
#pragma once

#include <iostream>

namespace Notification {

    const double SEUIL_QTE_THE = 10.0; // g
    const double SEUIL_QTE_EAU = 500.0; // mL

    class Observateur {
        public:
            virtual ~Observateur() = 0;
            virtual void notifier(double qte) = 0;
            virtual void notifier(const std::string& the, double qte) = 0;
    };

}  // namespace Notification