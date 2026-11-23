
#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
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

        // Ajoute, dans l'ordre d'exécution, la description de chaque changement élémentaire.
        // Aucun effet sur les réglages ni sur l'historique.
        virtual void apercu(std::vector<std::string> &lignes) const;

        // Copie profonde, dans l'état « jamais exécuté ». nullptr pour les commandes non réversibles.
        virtual std::shared_ptr<Commande> cloner() const;

        bool estReversible() const;

    protected:
        Commande(bool estReversible);

        bool estReversible_;
    };

} // namespace CMD
