#include <iostream>
#include <api.h>
#include <chrono>
#include "en.h"
#include <fstream>
#include <vector>
#include <string>
static constexpr auto DATA_PATH = "D:/double-array-trie/data/en_466k.txt";


const char*
sb_stemmer_stem(struct SN_env* stemmer, const char* word, int size)
{
    int ret;
    if (SN_set_current(stemmer, size, (const symbol*)(word)))
    {
        stemmer->l = 0;
        return nullptr;
    }
    ret = stem(stemmer);
    if (ret < 0) return nullptr;
    stemmer->p[stemmer->l] = 0;
    return (const char*)(stemmer->p);
}

int main() {
    SN_env* env = create_env();

    std::ifstream ifs(DATA_PATH);
    std::vector<std::string> words;
    std::vector<std::string> res;
    while (ifs) {
        std::string word;
        ifs >> word;
        words.push_back(word);
    }

    int n_chars = 0;
    for (auto& w : words) {
        n_chars += w.size();
    }

    res.reserve(words.size());

    auto clk = std::chrono::steady_clock::now();
    for (auto& w : words) {
        auto stem = sb_stemmer_stem(env, w.data(), w.size());
        res.emplace_back(stem);
    }
    auto diff = std::chrono::steady_clock::now() - clk;


    std::cout << "result size: " << res.size() << std::endl;
    std::cout << "word size: " << words.size() << ", time: " << (double)diff.count() / 1e6 / words.size() << " ms/word" << std::endl;
    std::cout << "char size: " << n_chars << ", time: " << (double)diff.count() / 1e6 / n_chars << " ms/char" << std::endl;


    close_env(env);
    return 0;
}