
#pragma once
#include <memory>
#include <string>
#include "Commande.h"

namespace CMD
{

    // Commande de la console « routine <nom> » : exécute une copie de la routine nommée
    // et l'annonce. Une seule entrée dans l'historique, quelle que soit la taille de la routine.
    class CmdRoutine : public Commande
    {
    public:
        CmdRoutine(const std::string &nom, const std::shared_ptr<Commande> &routine);
        ~CmdRoutine();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;
        virtual void apercu(std::vector<std::string> &lignes) const override;
        virtual std::shared_ptr<Commande> cloner() const override;

    private:
        std::string nom_;
        std::shared_ptr<Commande> routine_;
    };

} // namespace CMD
