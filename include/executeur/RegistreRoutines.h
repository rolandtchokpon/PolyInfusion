
#pragma once
#include <map>
#include <memory>
#include <string>
#include "../commande/CmdReglage.h"

namespace Execution
{

    // Catalogue des routines prédéfinies, construites au lancement sans rien exécuter.
    class RegistreRoutines
    {
    public:
        RegistreRoutines();
        ~RegistreRoutines();

        void enregistrer(const std::string &nom, const std::shared_ptr<CMD::CmdReglage> &routine);

        // La routine d'origine, pour la consulter (apercu). nullptr si le nom est inconnu.
        std::shared_ptr<CMD::CmdReglage> obtenir(const std::string &nom) const;

        // Une copie neuve à exécuter : chaque exécution a ses propres valeurs à restaurer.
        std::shared_ptr<CMD::CmdReglage> creerExecution(const std::string &nom) const;

    private:
        std::map<std::string, std::shared_ptr<CMD::CmdReglage>> routines_;
    };

} // namespace Execution
