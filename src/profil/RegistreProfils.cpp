
#include "../../include/profil/RegistreProfils.h"
#include "../../include/profil/ProfilVert.h"
#include "../../include/profil/ProfilNoir.h"
#include "../../include/profil/ProfilOolong.h"

namespace Profil
{

    RegistreProfils::RegistreProfils()
    {
        ajouter(std::make_shared<ProfilVert>());
        ajouter(std::make_shared<ProfilNoir>());
        ajouter(std::make_shared<ProfilOolong>());
    }

    RegistreProfils::~RegistreProfils() = default;

    void RegistreProfils::ajouter(const std::shared_ptr<ProfilInfusion> &profil)
    {
        if (profils_.find(profil->nom()) == profils_.end())
            ordre_.push_back(profil->nom());

        profils_[profil->nom()] = profil;
    }

    const ProfilInfusion *RegistreProfils::trouver(const std::string &nom) const
    {
        auto it = profils_.find(nom);
        return it == profils_.end() ? nullptr : it->second.get();
    }

    const std::vector<std::string> &RegistreProfils::noms() const { return ordre_; }

} // namespace Profil
