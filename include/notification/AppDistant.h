
#pragma once

#include "Observateur.h"
#include "../reserve/Reserve.h"

namespace Notification
{

    class AppDistant : public Observateur
    {
    public:
        AppDistant(Machine::Reserve *reserve);
        ~AppDistant();

        virtual void notifier(double qte) override;
        virtual void notifier(const std::string &the, double qte) override;

    private:
        Machine::Reserve *reserve_;
    };

} // namespace Notification