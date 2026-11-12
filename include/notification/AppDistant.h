
#pragma once

#include "Observateur.h"
#include "../distributeurEau/DistributeurEau.h"
#include "../distributeurThe/DistributeurThe.h"

namespace Notification {

    class AppDistant : public Observateur {
        public:
            AppDistant(Machine::DistributeurEau* dEau, Machine::DistributeurThe* dThe);
            ~AppDistant();

            virtual void notifier(double qte) override;
            virtual void notifier(const std::string& the, double qte) override;
        private:
            Machine::DistributeurEau* dEau_;
            Machine::DistributeurThe* dThe_;

    };

} // namespace Notification