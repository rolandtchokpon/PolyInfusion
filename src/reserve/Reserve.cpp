
#include "../../include/reserve/Reserve.h"
#include "../../include/util/Format.h"

namespace Machine
{

    const double QTE_EAU_INITIALE = 2000.0; // mL
    const double QTE_THE_INITIALE = 20.0;   // g

    Reserve::Reserve() : Notification::Notificateur(),
                         qteEau_(QTE_EAU_INITIALE)
    {
    }

    void Reserve::ajouterThe(const std::string &nom)
    {
        if (thes_.find(nom) == thes_.end())
        {
            ordreThes_.push_back(nom);
            thes_[nom] = QTE_THE_INITIALE;
        }
    }

    void Reserve::eauSuffisante(double quantite, double ratio) const
    {
        double quantiteRequise = quantite * (1.0 + ratio);

        if (qteEau_ < quantiteRequise)
        {
            throw EauInsuffisante(quantiteRequise, qteEau_);
        }
    }

    void Reserve::theSuffisant(const std::string &the, double quantite, double ratio) const
    {
        auto it = thes_.find(the);
        double quantiteRequise = quantite * (1.0 + ratio);

        if (it == thes_.end())
        {
            throw TheInsuffisant(the, quantiteRequise, 0.0);
        }

        if (it->second < quantiteRequise)
        {
            throw TheInsuffisant(the, quantiteRequise, it->second);
        }
    }

    void Reserve::afficherReserves() const
    {
        std::cout << "Eau : " << Util::nombre(qteEau_) << " mL" << std::endl;

        for (const std::string &nom : ordreThes_)
        {
            std::cout << "Thé " << nom << " : " << Util::nombre(thes_.at(nom)) << " g" << std::endl;
        }
    }

    void Reserve::remplirThe(const std::string &the, double quantite)
    {
        ajouterThe(the);
        thes_[the] += quantite;

        std::cout << "Ajout de thé " << the << " : " << Util::nombre(quantite) << " g." << std::endl;

        verifierThe(the, thes_[the]);
    }

    void Reserve::remplirEau(double quantite)
    {
        qteEau_ += quantite;

        std::cout << "Ajout d'eau : " << Util::nombre(quantite) << " mL." << std::endl;

        verifierEau(qteEau_);
    }

    void Reserve::distribuerThe(const std::string &the, double quantite, double ratio)
    {
        double quantiteRequise = quantite * (1.0 + ratio);

        thes_[the] -= quantiteRequise;

        std::cout << "Consommation de thé " << the << " : " << Util::nombre(quantiteRequise) << " g." << std::endl;

        verifierThe(the, thes_[the]);
    }

    void Reserve::distribuerEau(double quantite, double ratio)
    {
        double quantiteRequise = quantite * (1.0 + ratio);

        qteEau_ -= quantiteRequise;

        std::cout << "Consommation d'eau : " << Util::nombre(quantiteRequise) << " mL." << std::endl;

        verifierEau(qteEau_);
    }

} // namespace Machine
