
#pragma once
#include <map>
#include <memory>
#include <string>
#include "../commande/Commande.h"

namespace Execution
{

    // Catalogue des routines prédéfinies, construites au lancement sans rien exécuter.
    class RegistreRoutines
    {
    public:
        RegistreRoutines();
        ~RegistreRoutines();

        void enregistrer(const std::string &nom, const std::shared_ptr<CMD::Commande> &routine);

        // La routine d'origine, pour la consulter (apercu). nullptr si le nom est inconnu.
        std::shared_ptr<CMD::Commande> obtenir(const std::string &nom) const;

        // Une copie neuve à exécuter : chaque exécution a ses propres valeurs à restaurer.
        std::shared_ptr<CMD::Commande> creerExecution(const std::string &nom) const;

    private:
        std::map<std::string, std::shared_ptr<CMD::Commande>> routines_;
    };

} // namespace Execution
