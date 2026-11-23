
#include "../../include/fabrique/FabriqueSysteme.h"

namespace Fabrique
{

    FabriqueSysteme::FabriqueSysteme() = default;

    FabriqueSysteme::~FabriqueSysteme() = default;

    std::unique_ptr<Execution::Executeur> FabriqueSysteme::creerExecuteur(Machine::Systeme *sys)
    {
        return std::make_unique<Execution::Executeur>(sys);
    }

    std::unique_ptr<Console::InterfaceConsole> FabriqueSysteme::creerInterfaceConsole()
    {
        return std::make_unique<Console::InterfaceConsole>();
    }

} // namespace Fabrique
