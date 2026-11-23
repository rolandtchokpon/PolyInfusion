
#pragma once

#include "ProfilInfusion.h"

namespace Profil
{

    // Rinçage préalable des feuilles, dosées une seule fois lors du rinçage.
    class ProfilOolong : public ProfilInfusion
    {
    public:
        ProfilOolong();
        ~ProfilOolong();

    protected:
        virtual void rincer(Machine::Composants &composants) const override;
        virtual void infuser(Machine::Composants &composants) const override;
    };

} // namespace Profil
