#include "TranslitClass.h"

std::string TranslitClass::TranslitVoid(const std::string& strFromClipboard, const std::string& pathSlovar) {
    std::string strFromSlovar;
    std::ifstream fin(pathSlovar);

    std::string result = strFromClipboard;

    for (size_t i = 0; i < result.size(); ++i) {
        fin.clear();
        fin.seekg(0, std::ios::beg);

        char currentChar = result[i];

        while (std::getline(fin, strFromSlovar)) {
            if (currentChar == strFromSlovar[0]) {
                if (strFromSlovar.size() == 2) {
                    result[i] = '\\';
                }
                else {
                    result[i] = strFromSlovar[2];
                }
                break;
            }
        }
    }

    fin.close();
    return result;
};
