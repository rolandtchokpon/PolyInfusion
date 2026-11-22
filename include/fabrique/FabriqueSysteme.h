
#pragma once

#include "../systeme/SystemeCompact.h"
#include "../systeme/SystemePro.h"
#include "../executeur/Executeur.h"
#include "../console/Console.h"

namespace Fabrique
{

    class FabriqueSysteme
    {
    public:
        virtual ~FabriqueSysteme() = 0;
        virtual std::unique_ptr<Machine::Systeme> creerSysteme() = 0;

    protected:
        FabriqueSysteme();
    };

} // namespace Fabrique