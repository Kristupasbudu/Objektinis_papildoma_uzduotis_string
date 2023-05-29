#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <regex>

std::set<std::string> ZodziuIsgavimas(const std::string &eilute)
{
    std::set<std::string> zodziai;
    std::regex zodzioRegex("\\b[A-Za-z]+\\b");
    auto zodzioPradzia = std::sregex_iterator(eilute.begin(), eilute.end(), zodzioRegex);
    auto zodzioPabaiga = std::sregex_iterator();

    for (std::sregex_iterator it = zodzioPradzia; it != zodzioPabaiga; ++it)
    {
        std::smatch atitikmuo = *it;
        zodziai.insert(atitikmuo.str());
    }

    return zodziai;
}

std::set<std::string> UrlsEiluteje(const std::string &eilute)
{
    std::set<std::string> urls;
    std::regex urlRegex("(https?://|www\\.)[a-zA-Z0-9\\-\\.]+\\.[a-zA-Z]{2,}(\\S*)?");
    auto urlPradzia = std::sregex_iterator(eilute.begin(), eilute.end(), urlRegex);
    auto urlPabaiga = std::sregex_iterator();

    for (std::sregex_iterator it = urlPradzia; it != urlPabaiga; ++it)
    {
        std::smatch atitikmuo = *it;
        std::string url = atitikmuo.str();
        if (url.find("https://") == 0 || url.find("www.") == 0)
        {
            urls.insert(url);
        }
    }

    return urls;
}

int main()
{

    std::map<std::string, int> zodziuSkaiciai;
    std::map<std::string, std::set<int>> zodziuNuorodos;
    std::set<std::string> urls;

    std::string eilute;
    int eilutesNumeris = 1;

    std::ifstream inputFile("tekstas.txt");
    std::ofstream outputFile("rezultatai.txt");

    if (!inputFile)
    {
        std::cout << "Nepavyko atidaryti įvesties failo." << std::endl;
        return 1;
    }

    if (!outputFile)
    {
        std::cout << "Nepavyko atidaryti išvesties failo." << std::endl;
        return 1;
    }

    while (std::getline(inputFile, eilute))
    {
        std::set<std::string> zodziai = ZodziuIsgavimas(eilute);
        std::set<std::string> eilutesUrls = UrlsEiluteje(eilute);

        for (const auto &zodis : zodziai)
        {
            if (!std::isdigit(zodis[0]))
            { // Skip words starting with a digit
                ++zodziuSkaiciai[zodis];
                zodziuNuorodos[zodis].insert(eilutesNumeris);
            }
        }

        urls.insert(eilutesUrls.begin(), eilutesUrls.end());

        ++eilutesNumeris;
    }

    for (const auto &pora : zodziuSkaiciai)
    {
        if (pora.second > 1)
        {
            outputFile << pora.first << ": " << pora.second << std::endl;
        }
    }

    outputFile << std::endl
               << "Susiejimo Lentelė" << std::endl;
    for (const auto &pora : zodziuNuorodos)
    {
        if (pora.second.size() > 1)
        {
            outputFile << pora.first << ": ";

            for (const auto &eilute : pora.second)
            {
                outputFile << eilute << " ";
            }

            outputFile << std::endl;
        }
    }

    outputFile << std::endl
               << "URL Adresai" << std::endl;
    for (const auto &url : urls)
    {
        outputFile << url << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Rezultatai sėkmingai išsaugoti rezultatai.txt faile." << std::endl;

    return 0;
}
