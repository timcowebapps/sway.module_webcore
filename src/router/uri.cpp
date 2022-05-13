#include <sway/webcore/router/uri.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

Uri::Uri(const std::string &str)
    : regex_(UriRegex())
    , str_(str) {

  pmatch_ = (regmatch_t *)malloc(Uri::nmatch * sizeof(regmatch_t));
  int matched = regex_.exec(str.c_str(), Uri::nmatch, pmatch_, 0);
  if ( matched ) {
    //  EM_ASM({console.log("String " + UTF8ToString($0) + " does not match regex " + UTF8ToString($1))},
    //      str.c_str(),
    //      UriRegex::expression);
  }
}

Uri::~Uri() {
  free(pmatch_);
}

const std::string Uri::getPath() const {
  return (pmatch_[6].rm_so > -1) ? str_.substr(pmatch_[6].rm_so, pmatch_[6].rm_eo - pmatch_[6].rm_so) : std::string();
}

const std::string Uri::getQuery() const {
  return (pmatch_[7].rm_so > -1) ? str_.substr(pmatch_[7].rm_so, pmatch_[7].rm_eo - pmatch_[7].rm_so) : std::string();
}

const std::string Uri::getFragment() const {
  return (pmatch_[10].rm_so > -1) ? str_.substr(pmatch_[10].rm_so, pmatch_[10].rm_eo - pmatch_[10].rm_so)
                                  : std::string();
}

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
