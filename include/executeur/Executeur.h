
#pragma once
#include "../console/Instruction.h"
#include "HistoriqueCMD.h"
namespace Execution
{
    class Executeur
    {
    public:
        Executeur(Machine::Systeme *sys);
        ~Executeur();

        void executer(const Console::Instruction &inst);

    private:
        std::shared_ptr<CMD::Commande> commande(const Console::Instruction &inst);

        Machine::Systeme *sys_;
        std::unique_ptr<HistoriqueCMD> hist_;
    };

} // namespace Execution