#include <stdio.h>
#include <string>

#include "lm/model.hh"
#include "lm/virtual_interface.hh"

int main() {
  lm::ngram::Config config;
  config.load_method=util::LAZY;
  lm::ngram::TrieModel* model = new lm::ngram::TrieModel("/home/adam/Tools/kenlm/lm/test.arpa",config);

  lm::ngram::State out_state;
  lm::WordIndex context[1];
  std::string key = "also";
  context[0] = model->GetVocabulary().Index(key.c_str());
  model->GetState(context, context + 1, out_state);

  printf("%u %f %u\n", out_state.length, out_state.backoff[0], out_state.words[0]);

  return 0;
}