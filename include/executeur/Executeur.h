
#pragma once
#include <memory>
#include "../console/Instruction.h"
#include "HistoriqueCMD.h"
#include "RegistreRoutines.h"

namespace Execution
{
    // Traduit une instruction de la console en commande et l'exécute.
    // Les changements de réglages passent par l'historique ; les autres commandes non.
    class Executeur
    {
    public:
        Executeur(Machine::Systeme *sys);
        ~Executeur();

        void executer(const Console::Instruction &inst);

    private:
        std::shared_ptr<CMD::CmdReglage> creerReglage(const Console::Instruction &inst);
        std::shared_ptr<CMD::Commande> creerCommande(const Console::Instruction &inst);

        Machine::Systeme *sys_;
        std::unique_ptr<HistoriqueCMD> hist_;
        std::unique_ptr<RegistreRoutines> routines_;
    };

} // namespace Execution
