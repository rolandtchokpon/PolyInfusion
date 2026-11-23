
#include "../../include/profil/ProfilInfusion.h"
#include "../../include/util/Format.h"

namespace Profil
{

    ProfilInfusion::ProfilInfusion(const std::string &nom, double temperature, double tempsInfusion, double volumeRincage) : nom_(nom),
                                                                                                                            volumeRincage_(volumeRincage),
                                                                                                                            temperature_(temperature),
                                                                                                                            tempsInfusion_(tempsInfusion)
    {
    }

    ProfilInfusion::~ProfilInfusion() = default;

    const std::string &ProfilInfusion::nom() const { return nom_; }

    Besoins ProfilInfusion::besoins() const { return Besoins{volumeService_ + volumeRincage_, quantiteService_}; }

    void ProfilInfusion::preparer(Machine::Composants &composants) const
    {
        std::cout << "Préparation d'un thé " << nom_ << "." << std::endl;

        rincer(composants);
        infuser(composants);

        std::cout << "Service : " << Util::nombre(volumeService_) << " mL." << std::endl;
        std::cout << "Votre thé est prêt." << std::endl;
    }

    void ProfilInfusion::rincer(Machine::Composants &) const {}

    void ProfilInfusion::infuser(Machine::Composants &composants) const
    {
        composants.chauffage.chaufferEau(temperature_);
        composants.eau.distribuerEau(volumeService_);
        composants.the.distribuerThe(nom_, quantiteService_);

        std::cout << "Infusion : " << Util::nombre(tempsInfusion_) << " secondes simulées." << std::endl;
    }

} // namespace Profil
