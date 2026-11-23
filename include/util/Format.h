
#pragma once

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

namespace Util
{

    // Formate un nombre pour l'affichage : virgule décimale, sans zéros inutiles
    // (ex. 5.5 -> "5,5", 20.0 -> "20", 7.50 -> "7,5").
    inline std::string nombre(double valeur)
    {
        std::ostringstream flux;
        flux.imbue(std::locale::classic());
        flux << std::fixed << std::setprecision(2) << valeur;

        std::string texte = flux.str();

        if (texte.find('.') != std::string::npos)
        {
            while (texte.back() == '0')
                texte.pop_back();
            if (texte.back() == '.')
                texte.pop_back();
        }

        if (texte == "-0")
            texte = "0";

        const std::size_t position = texte.find('.');
        if (position != std::string::npos)
            texte[position] = ',';

        return texte;
    }

} // namespace Util
