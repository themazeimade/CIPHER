#include <algorithm>
#include <cctype>
#include <cstdint>
#include <ctype.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

class T_Decipher {
public:
  void decryptMessage(std::string message, std::string freqLang);
  void printDMessage();

private:
  void parse2counter(std::string message);
  void translateFreq(std::string freqLang);
  std::map<char, int32_t> alpha_counter;
  std::map<char, char> translatedMap;
  std::string decryptedMessage;
};

void T_Decipher::parse2counter(std::string message) {
  for (const char alpha : message) {
    if (!isalpha(alpha))
      continue;
    char a = std::tolower(alpha);
    if (alpha_counter.count(a)) {
      alpha_counter[a]++;
    } else
      alpha_counter.insert({a, 1});
  }
};

void T_Decipher::translateFreq(std::string freqLang) {
  std::vector<std::pair<char, int32_t>> vc(alpha_counter.begin(),
                                           alpha_counter.end());
  std::sort(vc.begin(), vc.end(),
            [](const auto &a, const auto &b) { return a.second > b.second; });
  for (int i = 0; i < freqLang.length(); i++) {
    translatedMap.insert({vc[i].first, std::tolower(freqLang[i])});
  };
};

void T_Decipher::decryptMessage(std::string message, std::string freqLang) {
  parse2counter(message);
  translateFreq(freqLang);
  for (char alpha : message) {
    // char a = std::tolower(alpha);
    auto it = translatedMap.find(std::tolower(alpha));
    if (it == translatedMap.end()) {
      decryptedMessage.push_back(alpha);
    } else if (islower(alpha)){
      decryptedMessage.push_back(it->second);
    } else decryptedMessage.push_back(std::toupper(it->second));
  }
};

void T_Decipher::printDMessage() {
  std::cout << "Decrypted Message: " << std::endl
            << decryptedMessage << std::endl;
}

int main() {
  std::string DMessage =
      R"(Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb.
Xof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg fnxfexdqn oqp ge ofe.
Zgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.
Xof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro gxofe. - Mgon Rdepdrw.
(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)
(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)
  )";
  std::string freqTable = "TEOAISRHNUCMDLGWFPYKJBVQX";
  T_Decipher decrypter;
  decrypter.decryptMessage(DMessage, freqTable);
  decrypter.printDMessage();
  return 1;
}
