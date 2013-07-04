%{
void buildLocationInfo(SourceFile *file, const char *token, YYSTYPE *retval, const YYLTYPE *loc);
void initScanner(YYSTYPE *yylval, YYLTYPE *yylloc);
void updatePosition(YYLTYPE *yylloc, const char *token);
void resetPosition(YYLTYPE *yylloc);

#define YY_DECL	\
	int yylex(YYSTYPE *yylval_param, YYLTYPE *yylloc_param, CompilationUnit *unit)

#define YY_USER_INIT \
	initScanner(yylval, yylloc);

#define YY_USER_ACTION  \
	updatePosition(yylloc, yytext); \
	buildLocationInfo(unit->srcFile, yytext, yylval, yylloc); \
	resetPosition(yylloc);

%}

%option bison-bridge
%option bison-locations
%option yylineno
%option noyywrap

digit                       [0-9]
nonzero_digit               [1-9]
octal_digit                 [0-7]
hexadecimal_digit           [0-9a-fA-F]

unsigned_suffix             [uU]
long_suffix                 [lL]

hex_quad                    {hexadecimal_digit}{4}

universal_character_name    (\\u{hex_quad}|\\U{hex_quad}{2})

nondigit                    [{universal_character_name}_a-zA-Z]

digit_sequence              {digit}+
sign                        [\+\-]

floating_suffix             [flFL]

simple_escape_sequence      (\\'|\\\"|\\\?|\\\\|\\a|\\b|\\f|\\n|\\r|\\t|\\v)
octal_escape_sequence       \\{octal_digit}{1,3}
hexadecimal_escape_sequence \\x{hexadecimal_digit}+

escape_sequence             ({simple_escape_sequence}|{octal_escape_sequence}|{hexadecimal_escape_sequence})

s_char                      ([^\"\\\n\r]+|{escape_sequence}|{universal_character_name})
s_char_sequence             {s_char}+
string_literal              L?\"{s_char_sequence}?\"

exponent_part               [eE]{sign}?{digit_sequence}
fractional_constant         ({digit_sequence}?\.{digit_sequence}|{digit_sequence}\.)
floating_literal            ({fractional_constant}{exponent_part}?{floating_suffix}?|{digit_sequence}{exponent_part}{floating_suffix}?)

decimal_literal             {nonzero_digit}{digit}*
octal_literal               0{octal_digit}*
hexadecimal_literal         (0x|0X){hexadecimal_digit}+

integer_suffix              ({unsigned_suffix}{long_suffix}?|{long_suffix}{unsigned_suffix}?)
integer_literal             ({decimal_literal}|{octal_literal}|{hexadecimal_literal}){integer_suffix}?


c_char                      ([^'\\\n\r]+|{escape_sequence}|{universal_character_name})
c_char_sequence             {c_char}+
character_literal           L?'{c_char_sequence}'

identifier                  {nondigit}({nondigit}|{digit})*

%%

"asm"                       { return KW_ASM; }
"auto"                      { return KW_AUTO; }
"bool"                      { return KW_BOOL; }
"break"                     { return KW_BREAK; }
"case"                      { return KW_CASE; }
"catch"                     { return KW_CATCH; }
"char"                      { return KW_CHAR; }
"class"                     { return KW_CLASS; }
"const"                     { return KW_CONST; }
"const_cast"                { return KW_CONST_CAST; }
"continue"                  { return KW_CONTINUE; }
"default"                   { return KW_DEFAULT; }
"delete"                    { return KW_DELETE; }
"do"                        { return KW_DO; }
"double"                    { return KW_DOUBLE; }
"dynamic_cast"              { return KW_DYNAMIC_CAST; }
"else"                      { return KW_ELSE; }
"enum"                      { return KW_ENUM; }
"explicit"                  { return KW_EXPLICIT; }
"export"                    { return KW_EXPORT; }
"extern"                    { return KW_EXTERN; }
"false"                     { return KW_FALSE; }
"float"                     { return KW_FLOAT; }
"friend"                    { return KW_FRIEND; }
"for"                       { return KW_FOR; }
"goto"                      { return KW_GOTO; }
"if"                        { return KW_IF; }
"inline"                    { return KW_INLINE; }
"int"                       { return KW_INT; }
"long"                      { return KW_LONG; }
"mutable"                   { return KW_MUTABLE; }
"namespace"                 { return KW_NAMESPACE; }
"new"                       { return KW_NEW; }
"operator"                  { return KW_OPERATOR; }
"private"                   { return KW_PRIVATE; }
"protected"                 { return KW_PROTECTED; }
"public"                    { return KW_PUBLIC; }
"register"                  { return KW_REGISTER; }
"reinterpret_cast"          { return KW_REINTERPRET_CAST; }
"return"                    { return KW_RETURN; }
"short"                     { return KW_SHORT; }
"signed"                    { return KW_SIGNED; }
"sizeof"                    { return KW_SIZEOF; }
"static"                    { return KW_STATIC; }
"static_cast"               { return KW_STATIC_CAST; }
"struct"                    { return KW_STRUCT; }
"switch"                    { return KW_SWITCH; }
"template"                  { return KW_TEMPLATE; }
"this"                      { return KW_THIS; }
"throw"                     { return KW_THROW; }
"true"                      { return KW_TRUE; }
"try"                       { return KW_TRY; }
"typedef"                   { return KW_TYPEDEF; }
"typeid"                    { return KW_TYPEID; }
"typename"                  { return KW_TYPENAME; }
"union"                     { return KW_UNION; }
"unsigned"                  { return KW_UNSIGNED; }
"using"                     { return KW_USING; }
"virtual"                   { return KW_VIRTUAL; }
"void"                      { return KW_VOID; }
"volatile"                  { return KW_VOLATILE; }
"wchar_t"                   { return KW_WCHAR_T; }
"while"                     { return KW_WHILE; }

"::"                        { return COLON_2X; }

"["                         { return SQ_LPAR; }
"]"                         { return SQ_RPAR; }
"("                         { return LPAR; }
")"                         { return RPAR; }
"."                         { return DOT; }
"->"                        { return OP_ARROW; }
"++"                        { return OP_INC; }
"--"                        { return OP_DEC; }

"*"                         { return OP_STAR; }
"&"                         { return OP_AMP; }
"!"                         { return OP_LOG_NEG; }
"~"                         { return OP_TILDA; }

","                         { return COMMA; }

"/"                         { return OP_DIV; }
"%"                         { return OP_MOD; }

"+"                         { return OP_ADD; }
"-"                         { return OP_SUB; }

"<<"                        { return OP_LSH; }
">>"                        { return OP_RSH; }

"<"                         { return OP_LT; }
">"                         { return OP_GT; }
"<="                        { return OP_LE; }
">="                        { return OP_GE; }
"=="                        { return OP_EQ; }
"!="                        { return OP_NE; }

"^"                         { return OP_XOR; }
"|"                         { return OP_BIT_OR; }

"&&"                        { return OP_LOG_AND; }
"||"                        { return OP_LOG_OR; }

"="                         { return OP_ASSIGN; }
"*="                        { return OP_ASSIGN_MUL; }
"/="                        { return OP_ASSIGN_DIV; }
"%="                        { return OP_ASSIGN_MOD; }
"+="                        { return OP_ASSIGN_ADD; }
"-="                        { return OP_ASSIGN_SUB; }
">>="                       { return OP_ASSIGN_RSH; }
"<<="                       { return OP_ASSIGN_LSH; }
"&="                        { return OP_ASSIGN_AND; }
"^="                        { return OP_ASSIGN_XOR; }
"|="                        { return OP_ASSIGN_OR; }

"?"                         { return QUESTIONMARK; }
":"                         { return COLON; }

".*"                        { return DOT_STAR; }
"->*"                       { return OP_ARROW_STAR; }

";"                         { return SEMICOLON; }
"{"                         { return LVINCULUM; }
"}"                         { return RVINCULUM; }
"..."                       { return ELIS; }

{identifier}                { return IDENTIFIER; }

{integer_literal}           { return INT_LITERAL; }
{character_literal}         { return CHARACTER_LITERAL; }
{floating_literal}          { return FLOAT_LITERAL; }
{string_literal}            { return STR_LITERAL; }

"//"[^\n\r]*				/* single-line comment */
"/\*"([^\*]*\*)+"/"			/* multi-line comment */

[ \t\n\r]+
.                           { return *yytext; }

<<EOF>>                     { unit->srcFile->lastToken = yylval->src; yyterminate(); }

%%

void buildLocationInfo(SourceFile *file, const char *token, YYSTYPE *retval, const YYLTYPE *loc)
{
	static Comment *comm;
	static int len;
	//
	comm = NULL;
	if((len = strlen(token)) >= 2)
	{
		if((token[0] == '/') && ((token[1] == '/') || (token[1] == '*')))
		{
			comm = new Comment;
			comm->text = token + 2;
			if(token[1] == '*')
			{
				comm->text.erase(len - 3);
			}
		}
	}
	//
	if(retval->src)
	{
		retval->src->insertAfter(new SourceLocation(token, loc->first_line, loc->first_column, loc->last_line, loc->last_column));
		retval->src = retval->src->next;
	}
	else
	{
		file->firstToken = retval->src = new SourceLocation(token, loc->first_line, loc->first_column, loc->last_line, loc->last_column);
	}
	//
	if(comm)
	{
		retval->src->parent = comm;
		comm->locFirst = comm->locLast = retval->src;
	}
}

void initScanner(YYSTYPE *yylval, YYLTYPE *yylloc)
{
	yylval->src = NULL;
	//
	yylloc->first_line = yylloc->first_column = 1;
	yylloc->last_line  = yylloc->last_column  = 1;
}

void updatePosition(YYLTYPE *yylloc, const char *token)
{
	yylloc->last_line = yyget_lineno();
	//
	if(yylloc->first_line == yylloc->last_line)
	{
		yylloc->last_column = yylloc->first_column + yyget_leng();
	}
	else
	{
		yylloc->last_column = 1;
		for(int i = yyget_leng() - 1; i >= 0; i--, yylloc->last_column++)
			if((token[i] == '\r') || (token[i] == '\n'))
				break;
	}
}

void resetPosition(YYLTYPE *yylloc)
{
	yylloc->first_line   = yylloc->last_line;
	yylloc->first_column = yylloc->last_column;
}
