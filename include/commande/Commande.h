
#pragma once
#include <iostream>
#include "../systeme/Systeme.h"
#include "../console/Console.h"

namespace CMD
{

    class Commande
    {
    public:
        virtual ~Commande() = 0;
        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) = 0;
        virtual void undo(Machine::Systeme *sys) = 0;

        // Rétablit silencieusement l'effet de executer() après un undo().
        // Les commandes réversibles la redéfinissent ; les autres n'ont rien à rétablir.
        virtual void redo(Machine::Systeme *sys);

        bool estReversible() const;

    protected:
        Commande(bool estReversible);

        bool estReversible_;
    };

} // namespace CMD
