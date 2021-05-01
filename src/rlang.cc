#include <napi.h>
#include <Rembedded.h>
#include <Rdefines.h>
#include <R_ext/Parse.h>

#include <string>

void doSplinesExample(const std::string& expression)
{
  SEXP e, tmp;
  int hadError;
  ParseStatus status;

  std::string expr("{");
  expr += expression;
  expr += "}";
  
  PROTECT(tmp = mkString(expr.c_str()));
  PROTECT(e = R_ParseVector(tmp, 1, &status, R_NilValue));
   
  R_tryEval(VECTOR_ELT(e, 0), R_GlobalEnv, &hadError);
  UNPROTECT(2);
}
Napi::String Hello(const Napi::CallbackInfo& info) {
  doSplinesExample(info[0].As<Napi::String>());
  Rf_endEmbeddedR(0);

  Napi::Env env = info.Env();
  return Napi::String::New(env, "Hello, world!");
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
  int argc = 2;
  char *argv[] = { "R", "--silent" };
  
  Rf_initEmbeddedR(argc, argv);


  exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Hello));
  return exports;
}

NODE_API_MODULE(rlang, Init)
