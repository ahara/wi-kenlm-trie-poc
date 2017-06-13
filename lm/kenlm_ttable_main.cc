#include <stdio.h>
#include "lm/model.hh"

int main() {
  printf("TEST\n");

  lm::ngram::Config config;
  config.load_method=util::LAZY;
  lm::ngram::TrieModel* modelPtr=new lm::ngram::TrieModel(NULL,config);

  return 0;
}