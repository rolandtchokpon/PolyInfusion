
#pragma once
#include <memory>
#include <string>
#include "CmdReglage.h"

namespace CMD
{

    // Commande de la console « routine <nom> » : exécute une copie de la routine nommée
    // et l'annonce. Une seule entrée dans l'historique, quelle que soit la taille de la routine.
    class CmdRoutine : public CmdReglage
    {
    public:
        CmdRoutine(const std::string &nom, const std::shared_ptr<CmdReglage> &routine);
        ~CmdRoutine();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;
        virtual std::string description() const override;
        virtual std::unique_ptr<IterateurReglage> creerIterateur() const override;
        virtual std::shared_ptr<CmdReglage> cloner() const override;

    private:
        std::string nom_;
        std::shared_ptr<CmdReglage> routine_;
    };

} // namespace CMD
