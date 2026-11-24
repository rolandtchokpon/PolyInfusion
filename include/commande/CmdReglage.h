
#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Commande.h"
#include "IterateurReglage.h"

namespace CMD
{

    // Changement de réglage : exécutable, annulable, rétablissable, descriptible et copiable.
    // Seuls ces objets entrent dans l'historique et peuvent être regroupés dans une routine ;
    // un nouveau type de réglage doit fournir tout le contrat pour compiler.
    class CmdReglage : public Commande
    {
    public:
        virtual ~CmdReglage() = 0;

        virtual void undo(Machine::Systeme *sys) = 0;

        // Rétablit silencieusement l'effet de executer() après un undo().
        virtual void redo(Machine::Systeme *sys) = 0;

        // Description d'un changement (« Sélectionner le thé noir. »), sans aucun effet.
        virtual std::string description() const = 0;

        // Itérateur sur les changements élémentaires, dans l'ordre d'exécution.
        // C'est lui, et non la routine, qui fait le parcours (aperçu).
        virtual std::unique_ptr<IterateurReglage> creerIterateur() const = 0;

        // Copie profonde, dans l'état « jamais exécuté » : chaque exécution a ses propres valeurs à restaurer.
        virtual std::shared_ptr<CmdReglage> cloner() const = 0;

    protected:
        CmdReglage();
    };

} // namespace CMD
