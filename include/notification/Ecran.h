
#pragma once

#include "Observateur.h"
#include "../reserve/Reserve.h"

namespace Notification
{

    class Ecran : public Observateur
    {
    public:
        Ecran(Machine::Reserve *reserve);
        ~Ecran();

        virtual void notifier(double qte) override;
        virtual void notifier(const std::string &the, double qte) override;

    private:
        Machine::Reserve* reserve_;
    };

} // namespace Notification