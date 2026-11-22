
#pragma once
#include <iostream>
#include "../systeme/Systeme.h"
#include "../console/Console.h"
#include "../routine/Duo.h"
#include "../routine/Solo.h"
#include "../routine/Matin.h"

namespace CMD
{

    class Commande
    {
    public:
        virtual ~Commande() = 0;
        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) = 0;
        virtual void undo(Machine::Systeme *sys) = 0;

        const Console::Instruction &sauvgarde();
        bool estReversible() const;

    protected:
        Commande(bool estReversible);
        std::shared_ptr<Routine::IRoutine> lireRoutine(const std::string &r);

        bool estReversible_;
        bool afficherModif_;
        unsigned int portionsAvant_;
        std::string theAvant_;
        Console::Instruction instruction_;
    };

} // namespace Commande