
#pragma once

#include <memory>

#include "../systeme/Systeme.h"
#include "../executeur/Executeur.h"
#include "../console/Console.h"

namespace Fabrique
{

    class FabriqueSysteme
    {
    public:
        virtual ~FabriqueSysteme();

        virtual std::unique_ptr<Machine::Systeme> creerSysteme() = 0;
        std::unique_ptr<Execution::Executeur> creerExecuteur(Machine::Systeme *sys);
        std::unique_ptr<Console::InterfaceConsole> creerInterfaceConsole();

    protected:
        FabriqueSysteme();
    };

} // namespace Fabrique
