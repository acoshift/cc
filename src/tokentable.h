#ifndef CC_TOKENTABLE_H_
#define CC_TOKENTABLE_H_

#include <string>
#include <boost/regex.hpp>

struct TokenTableCell
{
  ::std::string name;
  ::boost::regex regex;
};

const TokenTableCell kTokenTable[] = 
{
  { "abstract", ::boost::regex("abstract") },
  { "and", ::boost::regex("and") },
  { "as", ::boost::regex("as") },
  { "assert", ::boost::regex("assert") },
  { "base", ::boost::regex("base") },
  { "begin", ::boost::regex("begin") },
  { "class", ::boost::regex("class") },
  { "default", ::boost::regex("default") },
  { "delegate", ::boost::regex("delegate") },
  { "do", ::boost::regex("do") },
  { "done", ::boost::regex("done") },
  { "downcast", ::boost::regex("downcast") },
  { "downto", ::boost::regex("downto") },
  { "elif", ::boost::regex("elif") },
  { "else", ::boost::regex("else") },
  { "end", ::boost::regex("end") },
  { "exception", ::boost::regex("exception") },
  { "extern", ::boost::regex("extern") },
  { "false", ::boost::regex("false") },
  { "finally", ::boost::regex("finally") },
  { "for", ::boost::regex("for") },
  { "fun", ::boost::regex("fun") },
  { "function", ::boost::regex("function") },
  { "global", ::boost::regex("global") },
  { "if", ::boost::regex("if") },
  { "in", ::boost::regex("in") },
  { "inherit", ::boost::regex("inherit") },
  { "inline", ::boost::regex("inline") },
  { "interface", ::boost::regex("interface") },
  { "internal", ::boost::regex("internal") },
  { "lazy", ::boost::regex("lazy") },
  { "let", ::boost::regex("let") },
  { "match", ::boost::regex("match") },
  { "member", ::boost::regex("member") },
  { "module", ::boost::regex("module") },
  { "mutable", ::boost::regex("mutable") },
  { "namespace", ::boost::regex("namespace") },
  { "new", ::boost::regex("new") },
  { "null", ::boost::regex("null") },
  { "of", ::boost::regex("of") },
  { "open", ::boost::regex("open") },
  { "or", ::boost::regex("or") },
  { "override", ::boost::regex("override") },
  { "private", ::boost::regex("private") },
  { "public", ::boost::regex("public") },
  { "rec", ::boost::regex("rec") },
  { "return", ::boost::regex("return") },
  { "sig", ::boost::regex("sig") },
  { "static", ::boost::regex("static") },
  { "struct", ::boost::regex("struct") },
  { "then", ::boost::regex("then") },
  { "to", ::boost::regex("to") },
  { "true", ::boost::regex("true") },
  { "try", ::boost::regex("try") },
  { "type", ::boost::regex("type") },
  { "upcast", ::boost::regex("upcast") },
  { "use", ::boost::regex("use") },
  { "val", ::boost::regex("val") },
  { "void", ::boost::regex("void") },
  { "when", ::boost::regex("when") },
  { "while", ::boost::regex("while") },
  { "with", ::boost::regex("with") },
  { "yield", ::boost::regex("yield") },
  { "atomic", ::boost::regex("atomic") },
  { "break", ::boost::regex("break") },
  { "checked", ::boost::regex("checked") },
  { "component", ::boost::regex("component") },
  { "const", ::boost::regex("const") },
  { "constraint", ::boost::regex("constraint") },
  { "constructor", ::boost::regex("constructor") },
  { "continue", ::boost::regex("continue") },
  { "eager", ::boost::regex("eager") },
  { "fixed", ::boost::regex("fixed") },
  { "fori", ::boost::regex("fori") },
  { "functor", ::boost::regex("functor") },
  { "include", ::boost::regex("include") },
  { "measure", ::boost::regex("measure") },
  { "method", ::boost::regex("method") },
  { "mixin", ::boost::regex("mixin") },
  { "object", ::boost::regex("object") },
  { "parallel", ::boost::regex("parallel") },
  { "params", ::boost::regex("params") },
  { "process", ::boost::regex("process") },
  { "protected", ::boost::regex("protected") },
  { "pure", ::boost::regex("pure") },
  { "recursive", ::boost::regex("recursive") },
  { "sealed", ::boost::regex("sealed") },
  { "tailcall", ::boost::regex("tailcall") },
  { "trait", ::boost::regex("trait") },
  { "virtual", ::boost::regex("virtual") },
  { "volatile", ::boost::regex("volatile") },
  { "let!", ::boost::regex("let!") },
  { "use!", ::boost::regex("use!") },
  { "do!", ::boost::regex("do!") },
  { "yield!", ::boost::regex("yield!") },
  { "return!", ::boost::regex("return!") },
  { "line", ::boost::regex("line") },
  { "\'|\'", ::boost::regex("\\|") },
  { "\'->\'", ::boost::regex("->") },
  { "\'<-\'", ::boost::regex("<-") },
  { "\'.\'", ::boost::regex("\\.") },
  { "\':\'", ::boost::regex(":") },
  { "\'(\'", ::boost::regex("\\(") },
  { "\')\'", ::boost::regex("\\)") },
  { "\'[\'", ::boost::regex("\\[") },
  { "\']\'", ::boost::regex("\\]") },
  { "\'[<\'", ::boost::regex("\\[<") },
  { "\'>]\'", ::boost::regex(">\\]") },
  { "\'[|\'", ::boost::regex("\\|\\[") },
  { "\'|]\'", ::boost::regex("\\|\\]") },
  { "\'{\'", ::boost::regex("\\{") },
  { "\'}\'", ::boost::regex("\\}") },
  { "\':?>\'", ::boost::regex(":\\?>") },
  { "\':?\'", ::boost::regex(":\\?") },
  { "\':>\'", ::boost::regex(":>") },
  { "\'..\'", ::boost::regex("\\.\\.") },
  { "\'::\'", ::boost::regex("::") },
  { "\':=\'", ::boost::regex(":=") },
  { "\';;\'", ::boost::regex(";;") },
  { "\';\'", ::boost::regex(";") },
  { "\'=\'", ::boost::regex("=") },
  { "\'_\'", ::boost::regex("_") },
  { "\'?\'", ::boost::regex("\\?") },
  { "\'??\'", ::boost::regex("\\?\\?") },
  { "\'(*)\'", ::boost::regex("\\(\\*\\)") },
  { "\'<@\'", ::boost::regex("<@") },
  { "\'@>\'", ::boost::regex("@>") },
  { "\'<@@\'", ::boost::regex("<@@") },
  { "\'@@>\'", ::boost::regex("@@>") },
  { "\'~\'", ::boost::regex("~") },
  { "\'`\'", ::boost::regex("`") },
  { "\'#\'", ::boost::regex("#") },
  { "\'!\'", ::boost::regex("!") },
  { "\'%\'", ::boost::regex("%") },
  { "\'&\'", ::boost::regex("&") },
  { "\'*\'", ::boost::regex("\\*") },
  { "\'+\'", ::boost::regex("\\+") },
  { "\'-\'", ::boost::regex("-") },
  { "\'/\'", ::boost::regex("/") },
  { "\'<\'", ::boost::regex("<") },
  { "\'>\'", ::boost::regex(">") },
  { "\'@\'", ::boost::regex("@") },
  { "\'^\'", ::boost::regex("\\^") },
  { "\'?<-\'", ::boost::regex("\\?<-") },
  { "\'$\'", ::boost::regex("\\$") },
  { "\',\'", ::boost::regex(",") },
  { "\'&&\'", ::boost::regex("&&") },
  { "\'||\'", ::boost::regex("\\|\\|") },
  { "\'\'\'", ::boost::regex("\'") },
  { "\'\"\'", ::boost::regex("\"") },
  { "\'\\\'", ::boost::regex("\\\\") },
  { "__SKIP__whitespace-or-newline", ::boost::regex("(\\n|\\r\\n|\\s+)") },
  { "__SKIP__block-comment", ::boost::regex("\\(\\*((?!\\*\\)).)*\\*\\)") },
  { "__SKIP__end-of-line-comment", ::boost::regex("//[^\\n\\r]*(\\n|\\r\\n)") },
  { "if-directive", ::boost::regex("#if\\s+[a-zA-Z_]([a-zA-Z0-9_\'])*") },
  { "else-directive", ::boost::regex("#else") },
  { "endif-directive", ::boost::regex("#endif") },
  { "ident", ::boost::regex("(([a-zA-Z_]([a-zA-Z0-9_\'])*)|(``(([^`]|\\n|\\r\\n|\\t)|`([^`]|\\n|\\r\\n|\\t))+``))") },
  { "reserved-ident-formats", ::boost::regex("[a-zA-Z_]([a-zA-Z0-9_\'])*(!|#)") },
  { "char", ::boost::regex("\'([^\\n\\t\\r\'\\\\\"]|(\\\\[\"\\\\\'ntbrafv])|(\\\\[0-9][0-9][0-9])|(\\\\u[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f]))\'") },
  { "string", ::boost::regex("\"([^\\n\\t\\r\'\\\\\"]|(\\\\[\"\\\\\'ntbrafv])|(\\\\[^\"\\\\\'ntbrafv])|(\\\\[0-9][0-9][0-9])|(\\\\u[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f])|(\\\\U[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f])|(\\n|\\r\\n))*\"") },
  { "verbatim-string", ::boost::regex("@\"([^\\n\\t\\r\'\\\\\"]|(\\\\[^\"\\\\\'ntbrafv])|(\\n|\\r\\n)|\\\\|\"\")*\"") },
  { "bytechar", ::boost::regex("\'([^\\n\\t\\r\'\\\\\"]|(\\\\[\"\\\\\'ntbrafv]))\'B") },
  { "bytearray", ::boost::regex("\"([^\\n\\t\\r\'\\\\\"]|(\\\\[\"\\\\\'ntbrafv])|(\\\\[^\"\\\\\'ntbrafv])|(\\\\[0-9][0-9][0-9])|(\\\\u[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f])|(\\\\U[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f])|(\\n|\\r\\n))*\"B") },
  { "verbatim-bytearray", ::boost::regex("@\"([^\\n\\t\\r\'\\\\\"]|(\\\\[^\"\\\\\'ntbrafv])|(\\n|\\r\\n)|\\\\|\"\")*\"B") },
  { "triple-quoted-string", ::boost::regex("\"\"\"((?!\"\"\")(.|\\n|\\r\\n|\\t))*\"\"\"") },
  { "sbyte", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))y") },
  { "byte", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))uy") },
  { "int16", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))s") },
  { "uint16", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))us") },
  { "int32", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))l") },
  { "uint32", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))(ul|u)") },
  { "nativeint", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))n") },
  { "unativeint", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))un") },
  { "int64", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))L") },
  { "uint64", ::boost::regex("(([0-9]+)|((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+)))(UL|uL)") },
  { "ieee32", ::boost::regex("((([0-9]+\\.[0-9]*)|([0-9]+(\\.[0-9]*)?[eE][\\+-]?[0-9]+))[Ff])|(((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+))lf)") },
  { "ieee64", ::boost::regex("(([0-9]+\\.[0-9]*)|([0-9]+(\\.[0-9]*)?[eE][\\+-]?[0-9]+))|(((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+))LF)") },
  { "bignum", ::boost::regex("([0-9]+)[QRZING]") },
  { "decimal", ::boost::regex("((([0-9]+\\.[0-9]*)|([0-9]+(\\.[0-9]*)?[eE][\\+-]?[0-9]+))|([0-9]+))[Mm]") },
  { "int", ::boost::regex("([0-9]+)") },
  { "xint", ::boost::regex("((0[xX][0-9A-Fa-f]+)|(0[oO][0-7]+)|(0[bB][0-1]+))") },
};

constexpr int kTokenTableCount = 182;

#endif  // CC_TOKENTABLE_H_
