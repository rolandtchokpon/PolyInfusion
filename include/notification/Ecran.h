
#pragma once

#include "Observateur.h"
#include "../distributeurEau/DistributeurEau.h"
#include "../distributeurThe/DistributeurThe.h"

namespace Notification {

    class Ecran : public Observateur {
        public:
            Ecran(Machine::DistributeurEau* d1, Machine::DistributeurThe* d2);
            ~Ecran();

            virtual void notifier(double qte) override;
            virtual void notifier(const std::string& the, double qte) override;

        private:
            Machine::DistributeurEau* dEau_;
            Machine::DistributeurThe* dThe_;
    };

}  // namespace Notification