#include "console/Console.h"

#include <cmath>
#include <iostream>
#include <locale>
#include <sstream>
#include <vector>

namespace {

bool estUnThe(const std::string& valeur)
{
    return valeur == "vert" || valeur == "noir" || valeur == "oolong";
}

console::Instruction invalide(const std::string& message)
{
    console::Instruction resultat;
    resultat.type = console::TypeInstruction::Invalide;
    resultat.erreur = message;
    return resultat;
}

bool lireQuantite(const std::string& texte, double& quantite)
{
    // Le point est le séparateur décimal, indépendamment de la langue du système.
    std::istringstream entree(texte);
    entree.imbue(std::locale::classic());
    if (!(entree >> quantite)) {
        return false;
    }
    entree >> std::ws;
    return entree.eof() && std::isfinite(quantite) && quantite > 0.0;
}

} // namespace

namespace console {

Instruction analyser(const std::string& ligne)
{
    std::istringstream entree(ligne);
    std::vector<std::string> mots;
    for (std::string mot; entree >> mot;) {
        mots.push_back(mot);
    }
    Instruction resultat;
    if (mots.empty()) {
        return resultat;
    }
    const auto& nom = mots.front();
    if (nom == "selection") {
        if (mots.size() != 2 || !estUnThe(mots[1])) {
            return invalide("Utilisation : selection <vert|noir|oolong>.");
        }
        resultat.type = TypeInstruction::Selection;
        resultat.the = mots[1];
    } else if (nom == "remplir") {
        if (mots.size() != 3 || (mots[1] != "eau" && !estUnThe(mots[1]))) {
            return invalide("Utilisation : remplir <eau|vert|noir|oolong> <quantite>.");
        }
        if (!lireQuantite(mots[2], resultat.quantite)) {
            return invalide("La quantité doit être un nombre positif et fini, avec un point décimal au besoin.");
        }
        resultat.type = mots[1] == "eau" ? TypeInstruction::RemplirEau : TypeInstruction::RemplirThe;
        resultat.the = mots[1] == "eau" ? "" : mots[1];
    } else if (nom == "notifications") {
        if (mots.size() != 2 || (mots[1] != "activer" && mots[1] != "désactiver" && mots[1] != "desactiver")) {
            return invalide("Utilisation : notifications <activer|désactiver>.");
        }
        resultat.type = TypeInstruction::Notifications;
        resultat.notificationsActives = mots[1] == "activer";
    } else if (nom == "infuser" || nom == "reserves" || nom == "h" || nom == "q") {
        if (mots.size() != 1) {
            return invalide("Cette instruction ne prend aucun argument.");
        }
        if (nom == "infuser") resultat.type = TypeInstruction::Infuser;
        else if (nom == "reserves") resultat.type = TypeInstruction::Reserves;
        else if (nom == "h") resultat.type = TypeInstruction::Aide;
        else resultat.type = TypeInstruction::Quitter;
    } else {
        return invalide("Instruction inconnue. Entrez h pour afficher l’aide.");
    }
    return resultat;
}

void afficherAide()
{
    std::cout
        << "selection <vert|noir|oolong> : sélectionner le thé à préparer.\n"
        << "infuser : préparer une portion du thé sélectionné.\n"
        << "reserves : afficher les réserves d’eau et de thé.\n"
        << "remplir eau <quantite> : ajouter de l’eau, en millilitres.\n"
        << "remplir <vert|noir|oolong> <quantite> : ajouter du thé, en grammes.\n"
        << "notifications <activer|désactiver> : gérer les notifications à distance.\n"
        << "h : afficher cette aide.\n"
        << "q : quitter l’application.\n";
}

} // namespace console
