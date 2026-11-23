
#pragma once
#include <string>
#include <vector>
#include "Commande.h"

namespace CMD
{

    // Composite : une routine est une Commande qui contient d'autres Commande
    // (changements élémentaires ou sous-routines). L'historique la traite comme une seule opération.
    class Routine : public Commande
    {
    public:
        explicit Routine(const std::string &nom);
        ~Routine();

        void ajouter(const std::shared_ptr<Commande> &enfant);

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;
        virtual void apercu(std::vector<std::string> &lignes) const override;
        virtual std::shared_ptr<Commande> cloner() const override;

    private:
        std::string nom_;
        std::vector<std::shared_ptr<Commande>> enfants_;
    };

} // namespace CMD
