
#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "ProfilInfusion.h"

namespace Profil
{

    // Catalogue des profils d'infusion, indexés par le nom du thé.
    // Ajouter un profil = écrire sa classe et l'enregistrer ici ; rien d'autre ne change.
    class RegistreProfils
    {
    public:
        RegistreProfils();
        ~RegistreProfils();

        void ajouter(const std::shared_ptr<ProfilInfusion> &profil);

        // nullptr si aucun profil ne porte ce nom.
        const ProfilInfusion *trouver(const std::string &nom) const;

        const std::vector<std::string> &noms() const;

    private:
        std::map<std::string, std::shared_ptr<ProfilInfusion>> profils_;
        std::vector<std::string> ordre_;
    };

} // namespace Profil
