
#include "../../include/profil/ProfilOolong.h"
#include "../../include/util/Format.h"

namespace Profil
{

    ProfilOolong::ProfilOolong() : ProfilInfusion("oolong", 90.0, 90.0, 50.0) {}

    ProfilOolong::~ProfilOolong() = default;

    void ProfilOolong::rincer(Machine::Composants &composants) const
    {
        composants.chauffage.chaufferEauRincage(temperature_);
        composants.eau.distribuerEau(volumeRincage_);
        composants.the.distribuerThe(nom_, quantiteService_);

        std::cout << "Rinçage des feuilles." << std::endl;
        std::cout << "Évacuation de l'eau de rinçage." << std::endl;
    }

    void ProfilOolong::infuser(Machine::Composants &composants) const
    {
        composants.chauffage.chaufferEauPreparation(temperature_);
        composants.eau.distribuerEau(volumeService_);

        std::cout << "Infusion : " << Util::nombre(tempsInfusion_) << " secondes simulées." << std::endl;
    }

} // namespace Profil
